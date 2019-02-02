#include "algebra.h"

#include <algorithm>

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
        for (int i = 0; i < variables_cnt - 1; ++i)
        {
            prod *= m[i][variables_cnt - 1];
            gcd_res = gcd(gcd_res, m[i][variables_cnt - 1]);
        }
        T lcm = prod / gcd_res;
        for (int i = 0; i < variables_cnt; ++i)
        {
            T mul = lcm / m[i][variables_cnt - 1];
            for (int j = 0; j < m.getWidth(); ++j)
                m[i][j] *= mul;
        }
        for (int i = 0; i < variables_cnt - 1; ++i)
            for (int j = 0; j < m.getWidth(); ++j)
                m[i][j] -= m[variables_cnt - 1][j];
        solve(m, res, variables_cnt - 1);
        res[variables_cnt - 1] = m[variables_cnt - 1].back();
        for (int i = 0; i < variables_cnt - 1; ++i)
            res[variables_cnt - 1] -= m[variables_cnt - 1][i] * res[i];
        res[variables_cnt - 1] /= m[variables_cnt - 1][variables_cnt - 1];
    }
}

#include "fractions.h"
template
std::vector<Fractional<int>> solve(Matrix<Fractional<int>>& m);
template
void solve(Matrix<Fractional<int>>& m, std::vector<Fractional<int>>& res, size_t variables_cnt);
template
std::vector<int> solve(Matrix<int>& m);
template
void solve(Matrix<int>& m, std::vector<int>& res, size_t variables_cnt);

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