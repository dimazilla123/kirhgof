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
std::vector<T> solve(const Matrix<T>& m, size_t variables_cnt)
{
    if (variables_cnt == 1)
        return std::vector<T>({*(m[0].end()--) / m[0][0]});
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
        
    }
}