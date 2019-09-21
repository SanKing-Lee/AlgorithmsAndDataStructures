#include "Graph.h"

extern int MinVertex(Graph *g, int *D);

static void Prim(Graph *g, int *D, int *Path, int s);

class DijElem
{
public:
    DijElem(){};
    DijElem(int f, int t, int w) : from(f), to(t), weight(w){};
    ~DijElem(){};

    int from;
    int to;
    int weight;
};

static void Kruskal(Graph *g, DijElem *mst);

static bool Compare(const DijElem *elem1, const DijElem *elem2);

void TestMST();

void Prim(Graph *g, int *D, int *Path, int s)
{
    // 初始化路径数组和距离数组，Path[i]即为i被找到加入最小树集合前的邻居点
    // 一开始所有结点指向的引荐结点均为源结点
    for (int i = 0; i < g->GetVertexNum(); i++)
    {
        Path[i] = s;
        D[i] = g->GetWeight(s, i);
        cout << "D[" << i << "]: " << D[i] << endl;
    }
    for (int i = 0; i < g->GetVertexNum(); i++)
    {
        int v = MinVertex(g, D);
        if (D[v] == UNREACHABLE)
        {
            return;
        }
        if (v != s)
        {
            cout << "Handle edge: " << Path[v] << "->" << v << ", weight: " << D[v] << endl;
        }
        g->SetMark(v, VISITED);
        for (int w = g->GetFirstNeighbor(v); w < g->GetVertexNum(); w = g->GetNextNeighbor(v, w))
        {
            if (D[w] > g->GetWeight(v, w))
            {
                D[w] = g->GetWeight(v, w);
                Path[w] = v;
            }
        }
    }
}

void Kruskal(Graph *g, DijElem *mst)
{
    queue<DijElem> edges;
    
}

bool Compare(const DijElem *elem1, DijElem *elem2)
{
    return elem1->weight > elem2->weight;
}

void TestMST()
{
    int vertexNumber = 6;
    int source = 0;
    Graph *g = new Graph(vertexNumber);
    int D[vertexNumber];
    int Path[vertexNumber];
    g->InitFromFile("./Algorithms/config/TestMST.txt");
    Prim(g, D, Path, source);
}