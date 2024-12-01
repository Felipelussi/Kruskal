//
// Created by felipe on 12/1/24.
//

#ifndef KRUSKAL_H
#define KRUSKAL_H
#include <iostream>
#include <vector>
#include "Edge.h"
#include "EdgeWeightedGraph.h"
#include <set>
#include "UnionFind.h"
using namespace std;


class Kruskal {
private:
vector<Edge> mst;

public:
  Kruskal(EdgeWeightedGraph g){
    multiset<Edge, CompareEdge> edges = g.edges();

    UnionFind uf(g.getV());

    while(!edges.empty() && mst.size() < g.getNumberOfVertices()){
      Edge e = *edges.begin();
      int v = e.either();
      int w = e.other(v);
      if(!uf.connected(v,w)){
        uf.unite(v,w);
      mst.push_back(e);
      }
      edges.erase(edges.begin());
    }


}
 void showMst(){
      for(int i = 0; i < mst.size(); i++){
        int v = mst[i].either();
        int w = mst[i].other(v);
        cout << "{" << v << " " << w << "}" << endl;
      }
      }

};



#endif //KRUSKAL_H
