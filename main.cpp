//
// Created by felipe on 12/1/24.
//

#include <cstdlib>
#include <iostream>
#include "UnionFind.h"
#include "EdgeWeightedGraph.h"
#include "Kruskal.h"

using namespace std;

int main()
{
    EdgeWeightedGraph e(10);

    e.addEdge(Edge(7, 8, 1));
    e.addEdge(Edge(1, 2, 3));
    e.addEdge(Edge(1, 3, 4));
    e.addEdge(Edge(3, 2, 5));
    e.addEdge(Edge(2, 6, 3));
    e.addEdge(Edge(2, 7, 2));
    e.addEdge(Edge(2, 8, 4));

    Kruskal kruskal = Kruskal(e);

    kruskal.showMst();
}
