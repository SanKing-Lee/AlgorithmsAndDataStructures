#include "Graph.h"

static void Dijkestra(Graph *g, int *D, int s);
static int MinVertex(Graph *g, int *D);

void TestSSSP();

void Dijkestra(Graph *g, int *D, int s)
{
    // 构建初始的距离数组
    for (int i = 0; i < g->GetVertexNum(); i++)
    {
        D[i] = g->GetWeight(s, i);
        cout << s << "->" << i << ": " << D[i] << endl;
    }
    // 遍历每个结点，获取s到它们的最短距离
    for (int i = 0; i < g->GetVertexNum(); i++)
    {
        // 获取s的未访问的最近邻居
        int v = MinVertex(g, D);
        cout << "min vertex: " << v << endl;
        // 如果不存在邻居
        if (D[v] == UNREACHABLE)
        {
            return;
        }
        g->SetMark(v, VISITED);
        // 更新所有s到v的邻居w的距离，如果从s现有的到w方法的距离大于s->v->w的距离，则更新
        for (int w = g->GetFirstNeighbor(v); w < g->GetVertexNum(); w = g->GetNextNeighbor(v, w))
        {
            cout << "Neighbor of " << v << ": " << w << endl;
            if (D[w] > D[v] + g->GetWeight(v, w))
            {
                D[w] = D[v] + g->GetWeight(v, w);
                cout << "updated: ";
                cout << s << "->" << w << ": " << D[w] << endl;
            }
        }
    }
}

int MinVertex(Graph *g, int *D)
{
    int res, i;
    // 初始化为第一个找到的点，距离不为UNREACHABLE且未访问
    for(i = 0; i < g->GetVertexNum(); i++)
    {
        if(g->GetMark(i) == UNVISITED)
        {
            break;
        }
    }
    cout << "Initial min vertex: " << i << endl;
    res = i;

    // 寻找距离最近的点
    for(; i < g->GetVertexNum(); i++)
    {
        if(D[i] < D[res] && g->GetMark(i) == UNVISITED)
        {
            res = i;
        }
    }
    cout << "Final min vertex: " << res << endl;
    return res;
}

void TestSSSP()
{
    int vertexNumber = 5;
    int source = 0;

    Graph *g = new Graph(vertexNumber);
    g->PrintMatrix();
    int D[vertexNumber];
    g->InitFromFile("./Algorithms/config/TestSSSPEdges.txt");
    Dijkestra(g, D, source);
    for(int i = 0; i < vertexNumber; i++)
    {
        cout << source << "->" << i << ": " << D[i] << endl;
    }
}