#include <vector>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

class UnionFind
{
public: //Especificador de acesso
    vector<int> elements;

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

    void unir(int p, int q)
    {
        int inicial = elements[p];
        for (int i = 0; i < elements.size(); i++)
            if (elements[i] == inicial)
                elements[i] = elements[q];
    }
};

class Edge
{
public: //Especificador de acesso
    int v;
    int w;
    int weight;

    Edge(int v, int w, int weight) //Construtor
    {
        this->v = v;
        this->w = w;
        this->weight = weight;
    };
};


struct CompareEdge //Comparador
{
    bool operator()(const Edge& e1, const Edge& e2) const
    {
        return e1.weight > e2.weight;
    }
};

struct CompareEdgeSet
{
    bool operator()(const Edge& e1, const Edge& e2) const
    {
        if (e1.weight != e2.weight) return e1.weight < e2.weight; // Compare weights
        if (e1.v != e2.v) return e1.v < e2.v; // Break ties by src
        return e1.w < e2.w; // Break further ties by dest
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
        adj = vector<vector<Edge>>(V, vector<Edge>()); //inicializa vetor de vértices que aponta para vetor de arestas
    }

    void addEdge(Edge e)
    {
        adj[e.v].push_back(e);
        adj[e.w].push_back(e);
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


    set<Edge, CompareEdgeSet> get_edges() //Retorna conjunto de todas as arestas únicas do grafo
    {
        set<Edge, CompareEdgeSet> edges;
        for (int i = 0; i < V; i++)
            for (auto e : adj[i])
                edges.insert(e);
        return edges;
    }
};

class Kruskal
{
public:
    vector<Edge> arvoreGeradoraMinima;

    Kruskal(EdgeWeightedGraph g)
    {
        priority_queue<Edge, vector<Edge>, CompareEdge> filaArestas;
        //Fila de prioridade usada para ordenar o conjunto de arestas pelo seu peso
        for (auto e : g.get_edges())
        {
            filaArestas.push(e);
        }

        UnionFind uf(g.V);

        while (!filaArestas.empty() && arvoreGeradoraMinima.size() < g.getNumberOfVertices() - 1)
        {
            Edge e = filaArestas.top();
            int v = e.v;
            int w = e.w;
            if (!uf.connected(v, w))
            {
                uf.unir(v, w);
                arvoreGeradoraMinima.push_back(e);
            }
            filaArestas.pop();
        }
    }

    void showMst()
    {
        for (int i = 0; i < arvoreGeradoraMinima.size(); i++)
        {
            int v = arvoreGeradoraMinima[i].v;
            int w = arvoreGeradoraMinima[i].w;
            cout << "Aresta: {" << v << ", " << w << "} Peso: " << arvoreGeradoraMinima[i].weight << endl;
        }
    }
};


int main()
{
    EdgeWeightedGraph e(17);

    e.addEdge(Edge(1, 2, 53));
    e.addEdge(Edge(1, 6, 97));
    e.addEdge(Edge(1, 8, 32));
    e.addEdge(Edge(1, 13, 80));
    e.addEdge(Edge(1, 9, 47));
    e.addEdge(Edge(1, 7, 76));
    e.addEdge(Edge(1, 3, 82));
    e.addEdge(Edge(2, 4, 30));
    e.addEdge(Edge(3, 4, 80));
    e.addEdge(Edge(3, 5, 90));
    e.addEdge(Edge(4, 6, 48));
    e.addEdge(Edge(5, 7, 83));
    e.addEdge(Edge(6, 10, 90));
    e.addEdge(Edge(6, 12, 78));
    e.addEdge(Edge(7, 9, 46));
    e.addEdge(Edge(8, 10, 51));
    e.addEdge(Edge(9, 11, 23));
    e.addEdge(Edge(10, 14, 40));
    e.addEdge(Edge(10, 12, 152));
    e.addEdge(Edge(10, 16, 22));
    e.addEdge(Edge(11, 13, 33));
    e.addEdge(Edge(12, 14, 96));
    e.addEdge(Edge(13, 15, 41));
    e.addEdge(Edge(14, 16, 38));
    e.addEdge(Edge(15, 16, 80));



    Kruskal kruskal = Kruskal(e);
    kruskal.showMst();
}
