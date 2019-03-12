#include "vertex_handler.h"
#include "algebra.h"

VertexHandler::VertexHandler(size_t n)
{
    edges.resize(n);
}

void VertexHandler::addEdge(size_t from, size_t to, const ResistanceType& res, const PowerType& pow)
{
    edges[from].out.push_back(
        Edge{
            .to = to,
            .from = from,
            .edge_num = next_edge_num,
            .resistance = res,
            .power = pow
        }
    );
    edges[to].in.push_back(
        Edge{
            .to = to,
            .from = from,
            .edge_num = next_edge_num,
            .resistance = res,
            .power = pow
        }
    );
    ++next_edge_num;
}

void VertexHandler::addVertexesEq(Matrix<MatrixType>& mat)
{
    std::vector<MatrixType> line(edges.size() + 1);
    for (size_t v = 0; v < edges.size(); ++v)
    {
        for (auto u : edges[v].in)
            line[u.edge_num] = -1;
        for (auto u : edges[v].out)
            line[u.edge_num] = 1;
        line.back() = MatrixType(0);
        add_equation(mat, line);
    }
}

void VertexHandler::addLoopsEq(Matrix<MatrixType>& mat)
{

}

Matrix<MatrixType> VertexHandler::getEquations()
{
    Matrix<MatrixType> ret(0, edges.size() + 1);
    addVertexesEq(ret);
    addLoopsEq(ret);
    return ret;
}
