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
        std::vector<T> ret(m.getWidth(), 0);
        ret[0] = *(m[0].end()--) / m[0][0];
    }
    else
    {
        T prod = m[0][variables_cnt - 1];
        T gcd_of_products = prod;
        for (int i = 1; i < variables_cnt; ++i)
        {
            gcd_of_products = gcd(prod, m[i][variables_cnt - 1]);
            prod = prod * m[i][variables_cnt - 1];
        }
        T lcm = prod / gcd_of_products;
        for (auto &line : m)
        {
            T mul = lcm / line[variables_cnt - 1];
            std::for_each(line.begin(), line.end(), [&mul](T& val)
                {
                    val = val * mul;
                });
        }
        for (int i = 0; i < variables_cnt - 1; ++i)
            for (int j = 0; j < variables_cnt; ++j)
                m[i][j] = m[i][j] - m[variables_cnt - 1][j];
        solve(m, res, variables_cnt - 1);
        T c = *(m[variables_cnt - 1].end()--);
        c = c * (-1);
        for (int i = 0; i < variables_cnt - 1; ++i)
            c = c - m[variables_cnt - 1][i] * res[i];
        res[variables_cnt - 1] = c / m[variables_cnt - 1][variables_cnt - 1];
    }
}

#include "fractions.h"
//template
//std::vector<Fractional<int>> solve(Matrix<Fractional<int>>& m);
//template
//void solve(Matrix<Fractional<int>>& m, std::vector<Fractional<int>>& res, size_t variables_cnt);
template
std::vector<int> solve(Matrix<int>& m);
template
void solve(Matrix<int>& m, std::vector<int>& res, size_t variables_cnt);

template<typename T>
T gcd(T a, T b);