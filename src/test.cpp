#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

#include "matrix.h"
#include "vertex_handler.h"
#include "algebra.h"

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    //Matrix<Fractional<int>> mat(n, n + 1);
    Matrix<int> mat(n, n + 1);

    /*
    for (auto &line : mat)
        for (auto &cell : line)
        {
            int x;
            std::cin >> x;
            cell = x;
        }
    */
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            int x;
            std::cin >> x;
            mat[i][j] = x;
        }
    }
    auto answ = solve(mat);
    for (auto e : answ)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}