#ifndef VERTEX_HANDLER_H
#define VERTEX_HANDLER_H

#include <vector>
#include "fractions.h"
#include "matrix.h"

using ResistanceType = Fractional<int>;
using PowerType = Fractional<int>;
using MatrixType = Fractional<int>;

struct Edge
{
    size_t to;
    size_t from;
    size_t edge_num;
    ResistanceType resistance;
    PowerType power;
};

class VertexHandler
{
private:
    struct Vertex
    {
        std::vector<Edge> in, out;
    };
    std::vector<Vertex> edges;
    size_t next_edge_num = 0;
    void addVertexesEq(Matrix<MatrixType>& mat);
    void addLoopsEq(Matrix<MatrixType>& mat);
public:
    Matrix<MatrixType> getEquations();
    VertexHandler(size_t n);
    void addEdge(size_t from, size_t to, const ResistanceType& res, const PowerType& pow);
};

#endif