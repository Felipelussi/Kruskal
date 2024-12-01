//
// Created by felipe on 12/1/24.
//

#ifndef UNIONFIND_H
#define UNIONFIND_H
#include <vector>
using namespace std;

class UnionFind {
   private:
     std::vector<int> elements;
     public:
       UnionFind(int n) {
         elements.resize(n);
         for (int i = 0; i < n; i++) {
           elements[i] = i;
         }
       }
       int find(int p) {
         return elements[p];
       }

       void unite(int p, int q) {
         for(int i = 0; i < elements.size(); i++) {
           if(elements[i] == p) {
             elements[i] = q;
           }
         }
       }
       bool connected(int p, int q) {
         return find(p) == find(q);
       }
};



#endif //UNIONFIND_H
