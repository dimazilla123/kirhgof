#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

#include "matrix.h"

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    Matrix<std::pair<int, int>> m(n, n + 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n + 1; ++j)
            m[i][j] = std::make_pair(i, j);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
            std::cout << "{" << m[i][j].first << " " << m[i][j].second << "} ";
        std::cout << std::endl;
    }

    return 0;
}