#ifndef KRUSKAL_H
#define KRUSKAL_H
#include <iostream>
#include <vector>
#include "Edge.h"
#include "EdgeWeightedGraph.h"
#include <set>
#include "UnionFind.h"

using namespace std;

class Kruskal
{
public:
    vector<Edge> mst;

    Kruskal(EdgeWeightedGraph g)
    {
        multiset<Edge, CompareEdge> edges = g.edges();
        UnionFind uf(g.V);
        while (!edges.empty() && mst.size() < g.getNumberOfVertices() - 1)
        {
            Edge e = *edges.begin();
            int v = e.v;
            int w = e.w;
            if (!uf.connected(v, w))
            {
                uf.unite(v, w);
                mst.push_back(e);
            }
            edges.erase(edges.begin());
        }
    }

    void showMst()
    {
        for (int i = 0; i < mst.size(); i++)
        {
            int v = mst[i].v;
            int w = mst[i].w;
            cout << "{" << v << " " << w << "}" << endl;
        }
    }
};


#endif //KRUSKAL_H
