#include <vector>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

class UnionFind
{
public: //Especificador de acesso
    vector<int> elementos;

    //Construtor
    UnionFind(int n)
    {
        elementos.resize(n);
        for (int i = 0; i < n; i++)
            elementos[i] = i;
    }

    bool conectados(int v1, int v2)
    {
        return elementos[v1] == elementos[v2];
    }

    void unir(int v1, int v2)
    {
        int inicial = elementos[v1];
        for (int i = 0; i < elementos.size(); i++)
            if (elementos[i] == inicial)
                elementos[i] = elementos[v2];
    }
};

class Aresta
{
public: //Especificador de acesso
    int v1;
    int v2;
    int peso;

    Aresta(int v1, int v2, int peso) //Construtor
    {
        this->v1 = v1;
        this->v2 = v2;
        this->peso = peso;
    };
};


struct ComparaArestaPQ //Comparador
{
    bool operator()(const Aresta& a1, const Aresta& a2) const
    {
        return a1.peso > a2.peso;
    }
};

struct CompareArestaSet
{
    bool operator()(const Aresta& a1, const Aresta& a2) const
    {
        if (a1.peso != a2.peso) return a1.peso < a2.peso;
        if (a1.v1 != a2.v1) return a1.v1 < a2.v1;
        return a1.v2 < a2.v2;
    }
};

class Grafo
{
public:
    int V;
    std::vector<std::vector<Aresta>> adj;

    Grafo(int V)
    {
        this->V = V;
        adj = vector<vector<Aresta>>(V, vector<Aresta>()); //inicializa vetor de vértices que aponta para vetor de arestas
    }

    void addAresta(Aresta e)
    {
        adj[e.v1].push_back(e);
        adj[e.v2].push_back(e);
    };

    int numeroVertices()
    {
        set<int> vertices;
        for (int i = 0; i < V; i++)
            for (auto e : adj[i])
            {
                vertices.insert(e.v1);
                vertices.insert(e.v2);
            }
        return vertices.size();
    }


    set<Aresta, CompareArestaSet> vertices() //Retorna conjunto de todas as arestas únicas do grafo
    {
        set<Aresta, CompareArestaSet> arestas;
        for (int i = 0; i < V; i++)
            for (auto e : adj[i])
                arestas.insert(e);
        return arestas;
    }
};

class Kruskal
{
public:
    vector<Aresta> arvoreGeradoraMinima;

    Kruskal(Grafo g)
    {
        priority_queue<Aresta, vector<Aresta>, ComparaArestaPQ> filaArestas;
        //Fila de prioridade usada para ordenar o conjunto de arestas pelo seu peso
        for (auto e : g.vertices())
        {
            filaArestas.push(e);
        }

        UnionFind uf(g.V);

        while (!filaArestas.empty() && arvoreGeradoraMinima.size() < g.numeroVertices() - 1)
        {
            Aresta a = filaArestas.top();
            if (!uf.conectados(a.v1, a.v2))
            {
                uf.unir(a.v1, a.v2);
                arvoreGeradoraMinima.push_back(a);
            }
            filaArestas.pop();
        }
    }

    void mostraArvoreGeradoraMinima()
    {
        for (int i = 0; i < arvoreGeradoraMinima.size(); i++)
        {
            int v1 = arvoreGeradoraMinima[i].v1;
            int v2 = arvoreGeradoraMinima[i].v2;
            cout << "Aresta: {" << v1 << ", " << v2 << "} Peso: " << arvoreGeradoraMinima[i].peso << endl;
        }
    }
};


int main()
{
    Grafo g(17);

    g.addAresta(Aresta(1, 2, 53));
    g.addAresta(Aresta(1, 6, 97));
    g.addAresta(Aresta(1, 8, 32));
    g.addAresta(Aresta(1, 13, 80));
    g.addAresta(Aresta(1, 9, 47));
    g.addAresta(Aresta(1, 7, 76));
    g.addAresta(Aresta(1, 3, 82));
    g.addAresta(Aresta(2, 4, 30));
    g.addAresta(Aresta(3, 4, 80));
    g.addAresta(Aresta(3, 5, 90));
    g.addAresta(Aresta(4, 6, 48));
    g.addAresta(Aresta(5, 7, 83));
    g.addAresta(Aresta(6, 10, 90));
    g.addAresta(Aresta(6, 12, 78));
    g.addAresta(Aresta(7, 9, 46));
    g.addAresta(Aresta(8, 10, 51));
    g.addAresta(Aresta(9, 11, 23));
    g.addAresta(Aresta(10, 14, 40));
    g.addAresta(Aresta(10, 12, 152));
    g.addAresta(Aresta(10, 16, 22));
    g.addAresta(Aresta(11, 13, 33));
    g.addAresta(Aresta(12, 14, 96));
    g.addAresta(Aresta(13, 15, 41));
    g.addAresta(Aresta(14, 16, 38));
    g.addAresta(Aresta(15, 16, 80));

    Kruskal kruskal = Kruskal(g);
    kruskal.mostraArvoreGeradoraMinima();
}
