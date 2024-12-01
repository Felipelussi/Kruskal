#ifndef EDGE_H
#define EDGE_H

class Edge
{
public:  //Especificador de acesso
    int v;
    int w;
    int weight;

    Edge(int v, int w, int weight)   //Construtor
    {
        this->v = v;
        this->w = w;
        this->weight = weight;
    };
};

#endif //EDGE_H
