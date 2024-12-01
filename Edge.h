//
// Created by felipe on 12/1/24.
//

#ifndef EDGE_H
#define EDGE_H



class Edge {

  private:

    public:
    int v;
    int w;
  int weight;

      Edge(int v, int w, int weight){
        this->v = v;
        this->w = w;
        this->weight = weight;
      };

      int either(){
        return v;
      }

      int other(int v){
        if(v == this->v){
          return this->w;
        }
        return v;
      }

      const int getWeight(){
        return weight;
      }
};



#endif //EDGE_H
