#include "algebra.h"

#include <algorithm>
#include <cassert>

template<typename T>
T gcd(T a, T b);

template<typename T>
std::vector<T> solve(Matrix<T>& m)
{
    std::vector<T> ret(m.getHeight());
    solve(m, ret, m.getHeight());
    return ret;
}

template<typename T>
void solve(Matrix<T>& m, std::vector<T>& res, size_t variables_cnt)
{
    if (variables_cnt == 1)
    {
        res[0] = m[0].back() / m[0][0];
    }
    else
    {
        T prod = m[variables_cnt - 1][variables_cnt - 1];
        T gcd_res = m[variables_cnt - 1][variables_cnt - 1];
        for (size_t i = 0; i < variables_cnt - 1; ++i)
        {
            prod *= m[i][variables_cnt - 1];
            gcd_res = gcd(gcd_res, m[i][variables_cnt - 1]);
        }
        T lcm = prod / gcd_res;
        for (size_t i = 0; i < variables_cnt; ++i)
        {
            T mul = lcm / m[i][variables_cnt - 1];
            for (size_t j = 0; j < m.getWidth(); ++j)
                m[i][j] *= mul;
        }
        for (size_t i = 0; i < variables_cnt - 1; ++i)
            for (size_t j = 0; j < m.getWidth(); ++j)
                m[i][j] -= m[variables_cnt - 1][j];
        solve(m, res, variables_cnt - 1);
        res[variables_cnt - 1] = m[variables_cnt - 1].back();
        for (size_t i = 0; i < variables_cnt - 1; ++i)
            res[variables_cnt - 1] -= m[variables_cnt - 1][i] * res[i];
        res[variables_cnt - 1] /= m[variables_cnt - 1][variables_cnt - 1];
    }
}

template<typename T>
bool are_equations_equal(const std::vector<T>& a, const std::vector<T>& b)
{
    size_t n = a.size();
    if ((a[0] == 0 && b[0] != 0) || (a[0] != 0 && b[0] == 0))
        return false;
    //auto get_koef = (b[0] != 0 ? [](const T& x, const T& y) {return x / y;} :
    //                             [](const T& x, const T& y) {return y / x;});
    auto get_koef = [](const T& x, const T& y)
    {
        return (x == 0 || y == 0 ? 0 : x / y);
    };

    T k = get_koef(a[0], b[0]);
    for (size_t i = 1; i < n; ++i)
    {
        if (!((a[i] == b[i] && a[i] == 0) || (k == get_koef(a[i], b[i]))))
        {
            return false;
        }
    }

    return true;
}

template<typename T>
bool add_equation(Matrix<T>& m, const std::vector<T>& line)
{
    assert(m.getWidth() == line.size());
    for (auto &l : m) 
    {
        //std::vector<T> to_comp(l.begin(), l.end());
        std::vector<T> to_comp;
        for (auto el : l) 
            to_comp.push_back(el);
        if (are_equations_equal(to_comp, line)) 
            return false;
    }
    m.addLine();
    for (size_t i = 0; i < line.size(); i++) 
        m[m.getHeight() - 1][i] = line[i];
    return true;
}

#include "fractions.h"
#include "matrix.h"
template
std::vector<Fractional<int>> solve(Matrix<Fractional<int>>& m);
template
void solve(Matrix<Fractional<int>>& m, std::vector<Fractional<int>>& res, size_t variables_cnt);
template
std::vector<int> solve(Matrix<int>& m);
template
void solve(Matrix<int>& m, std::vector<int>& res, size_t variables_cnt);
template
bool are_equations_equal(const std::vector<int>& a, const std::vector<int>& b);
template
bool are_equations_equal(const std::vector<Fractional<int>>& a, const std::vector<Fractional<int>>& b);
template<>
bool add_equation(Matrix<int>& m, const std::vector<int>& line);
template
bool add_equation(Matrix<Fractional<int>>& m, const std::vector<Fractional<int>>& line);

template<typename T>
T gcd(T a, T b)
{
    while (b != T(0))
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}
