#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

#include "matrix.h"
#include "vertex_handler.h"

int main(int argc, char const *argv[])
{
    int n, m;
    std::cin >> n >> m;
    VertexHandler vh(n);

    for (int i = 0; i < m; ++i)
    {
        int a, b, num, dem;
        std::cin >> a >> b >> num >> dem;
        vh.addEdge(a - 1, b - 1, ResistanceType(num, dem));
    }

    Matrix<Fractional<int>> mat(n, n + 1);
    for (auto &l : mat)
    {
        static int j = 0;
        for (int i = 0; i < n + 1; ++i)
        {
            l[i] = i + j;
            l[i] = l[i] + Fractional<int>(1, 2) - Fractional<int>(1, 3);
        }
        ++j;
    }
    for (auto line : mat)
    {
        for (auto cell : line)
            std::cout << cell << ' ';
        std::cout << '\n';
    }

    return 0;
}