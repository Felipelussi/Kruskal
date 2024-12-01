#ifndef EDGEWEIGHTEDGRAPH_H
#define EDGEWEIGHTEDGRAPH_H
#include <vector>
#include "Edge.h"
#include <set>

using namespace std;

struct CompareEdge //Comparador
{
    bool operator()(const Edge& e1, const Edge& e2) const
    {
        return e1.weight < e2.weight;
    }
};


class EdgeWeightedGraph
{
public:
    int V;
    std::vector<std::vector<Edge>> adj;

    EdgeWeightedGraph(int V)
    {
        this->V = V;
        adj = vector<vector<Edge>>(V, vector<Edge>());
    }

    void addEdge(Edge e)
    {
        adj[e.v].push_back(e);
    };

    int getNumberOfVertices()
    {
        set<int> vertex;
        for (int i = 0; i < V; i++)
            for (auto e : adj[i])
            {
                vertex.insert(e.v);
                vertex.insert(e.w);
            }
        return vertex.size();
    }


    multiset<Edge, CompareEdge> edges()
    {
        multiset<Edge, CompareEdge> edges;
        for (int i = 0; i < V; i++)
            for (Edge e : adj[i])
                edges.insert(e);
        return edges;
    }
};

#endif //EDGEWEIGHTEDGRAPH_H
