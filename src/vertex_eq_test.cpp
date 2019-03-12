#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

#include "vertex_handler.h"
#include "algebra.h"

int main(int argc, char const *argv[])
{
    size_t n, m;
    std::cin >> n >> m;
    VertexHandler vh(n);

    for (int i = 0; i < m; ++i)
    {
        int from, to;
        ResistanceType res;
        PowerType pow;
        std::cin >> from >> to >> res >> pow;
        --from;
        --to;
        vh.addEdge(from, to, res, pow);
    }

    auto mat = vh.getEquations();
    for (auto line : mat)
    {
        for (auto cell : line)
        {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    auto res = solve(mat);
    for (auto e : res)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}