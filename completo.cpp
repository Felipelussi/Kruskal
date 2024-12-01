#include <vector>
#include <set>
#include <iostream>
#include <queue>

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
                elements[i] = elements[q];
    }
};

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

using namespace std;

struct CompareEdge //Comparador
{
    bool operator()(const Edge& e1, const Edge& e2) const
    {
        return e1.weight > e2.weight;
    }
};

struct CompareEdgeSet {
    bool operator()(const Edge& e1, const Edge& e2) const {
        if (e1.weight != e2.weight) return e1.weight < e2.weight; // Compare weights
        if (e1.v != e2.v) return e1.v < e2.v;             // Break ties by src
        return e1.w < e2.w;                                // Break further ties by dest
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
        adj = vector<vector<Edge>>(V, vector<Edge>());
    }

    void addEdge(Edge e)
    {
        adj[e.v].push_back(e);
        adj[e.w].push_back(Edge(e.v, e.w, e.weight));
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


    set<Edge, CompareEdgeSet> get_edges()
    {
        set<Edge, CompareEdgeSet> edges;
        for (int i = 0; i < V; i++)
            for (auto e : adj[i])
                edges.insert(Edge(e.v, e.w, e.weight));

        for (auto e : edges)
        {
            cout << e.v << ", " << e.w << ", " << e.weight << endl;
        }
        return edges;
    }
};

class Kruskal
{
public:
    vector<Edge> mst;

    Kruskal(EdgeWeightedGraph g)
    {
        // multiset<Edge, CompareEdge> edges = g.edges();
        priority_queue<Edge, vector<Edge>, CompareEdge> edges;
        for (auto e : g.get_edges())
        {
            edges.push(e);
        }
        UnionFind uf(g.V);
        while (!edges.empty() && mst.size() < g.getNumberOfVertices() - 1)
        {
            Edge e = edges.top();
            int v = e.v;
            int w = e.w;
            if (!uf.connected(v, w))
            {
                uf.unite(v, w);
                mst.push_back(e);
            }
            edges.pop();
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

    e.get_edges();

    Kruskal kruskal = Kruskal(e);
    kruskal.showMst();

}