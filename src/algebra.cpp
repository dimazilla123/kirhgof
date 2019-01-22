#include "algebra.h"

#include <algorithm>

template<typename T>
T gcd(T a, T b);

template<typename T>
std::vector<T> solve(const Matrix<T>& m)
{
    return solve(m, m.getHeight());
}

template<typename T>
std::vector<T>& solve(const Matrix<T>& m, size_t variables_cnt)
{
    if (variables_cnt == 1)
    {
        std::vector<T> ret(m.getWidth(), 0);
        ret[0] = *(m[0].end()--) / m[0][0];
        return ret;
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
        std::vector<T> ret = solve(m, variables_cnt - 1);
        T c = -*(m[variables_cnt - 1].end()--);
        for (int i = 0; i < variables_cnt - 1; ++i)
            c -= m[variables_cnt - 1][i] * ret[i];
        ret[variables_cnt - 1] = c / m[variables_cnt = 1][variables_cnt - 1];
        return ret;
    }
}