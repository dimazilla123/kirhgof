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

    Matrix<int> mat(n, n);

    return 0;
}