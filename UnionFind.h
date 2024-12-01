#ifndef UNIONFIND_H
#define UNIONFIND_H
#include <vector>

using namespace std;

class UnionFind
{
public: //Especificador de acesso
    std::vector<int> elements;

    //Construtor
    UnionFind(int n)
    {
        elements.resize(n);
        for (int i = 0; i < n; i++)
            elements[i] = i;
    }

    bool connected(int p, int q)
    {
        return elements[p] == elements[q];
    }

    void unite(int p, int q)
    {
        for (int i = 0; i < elements.size(); i++)
            if (elements[i] == p)
                elements[i] = q;
    }
};

#endif //UNIONFIND_H
