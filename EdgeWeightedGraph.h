//
// Created by felipe on 12/1/24.
//

#ifndef EDGEWEIGHTEDGRAPH_H
#define EDGEWEIGHTEDGRAPH_H
#include <vector>
#include "Edge.h"
#include <set>

using namespace std;
struct CompareEdge
{
  bool operator()(const Edge& e1, const Edge& e2) const {
      return e1.weight < e2.weight;
  }
};


class EdgeWeightedGraph {
    private:
      int V;
      std::vector<std::vector<Edge>> adj;
      public:
        EdgeWeightedGraph(int V){
          this->V = V;
          adj = vector<vector<Edge>>(V, vector<Edge>());
          for (int i = 0; i < V; i++) {
            adj[i].clear();
          }
          }

          void addEdge(Edge e){
            int v = e.either();
            int w = e.other(v);
            adj[v].push_back(e);
            // adj[w].push_back(e);
          };

          vector<Edge> getAdj(int v){
            return adj[v];
          }

          int getV(){
            return V;
          }

          int getNumberOfVertices()
          {
            vector<bool> visited(V, false);
            int counter = 0;
            for (int i = 0; i < V; i++)
            {
              for (auto e : adj[i])
              {
                int v = e.either();
                int w = e.other(v);
                if (visited[v] == false)
                {
                  visited[e.either()] = true;
                  counter++;

                }
                if (visited[w] == false)
                {
                  visited[w] = true;
                  counter++;
                }
              }
            }
            return counter;
          }


         multiset<Edge, CompareEdge> edges(){
           multiset<Edge, CompareEdge> edges;
           for(int i = 0; i < V; i++){
             for(Edge e : adj[i]){
               edges.insert(e);
             }
           }
           return edges;
         }
};



#endif //EDGEWEIGHTEDGRAPH_H
