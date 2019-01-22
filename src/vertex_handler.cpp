#include "vertex_handler.h"

VertexHandler::VertexHandler(size_t n)
{
    edges.resize(n);
}

void VertexHandler::addEdge(size_t from, size_t to, const ResistanceType& res)
{
    edges[from].out.push_back(
        Edge{
            .to = to,
            .from = from,
            .edge_num = next_edge_num,
            .resistance = res
        }
    );
    edges[to].in.push_back(
        Edge{
            .to = to,
            .from = from,
            .edge_num = next_edge_num,
            .resistance = res
        }
    );
    ++next_edge_num;
}