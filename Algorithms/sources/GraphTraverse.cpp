#include "Graph.h"

static void DFS(Graph *g, int v)
{
    cout << "Cunrrent node: " << v << endl;
    g->SetMark(v, VISITED);
    for(int w = g->GetFirstNeighbor(v); w < g->GetVertexNum(); w = g->GetNextNeighbor(v, w))
    {
        if(g->GetMark(w) == UNVISITED)
        {
            DFS(g, w);
        }
    }
}

static void BFS(Graph *g, int v)
{
    queue<int> nodes;
    nodes.push(v);
    g->SetMark(v, VISITED);
    while(!nodes.empty())
    {
        int node = nodes.front();
        nodes.pop();
        cout << "Current node: " << node << endl;
        for(int w = g->GetFirstNeighbor(node); w < g->GetVertexNum(); w = g->GetNextNeighbor(node, w))
        {
            if(g->GetMark(w) == UNVISITED)
            {
                nodes.push(w);
                g->SetMark(w, VISITED);
            }
        }
    }
}

void TestGraphTraverse()
{
    Graph *g = new Graph(6);
    g->SetEdge(0, 2, 1); g->SetEdge(2, 0, 1);
    g->SetEdge(0, 4, 1); g->SetEdge(4, 0, 1);
    g->SetEdge(1, 2, 1); g->SetEdge(2, 1, 1);
    g->SetEdge(1, 5, 1); g->SetEdge(5, 1, 1);
    g->SetEdge(2, 3, 1); g->SetEdge(3, 2, 1);
    g->SetEdge(2, 5, 1); g->SetEdge(5, 2, 1);
    g->SetEdge(3, 5, 1); g->SetEdge(5, 3, 1);
    g->SetEdge(4, 5, 1); g->SetEdge(5, 4, 1);
    g->PrintMatrix();
    // DFS(g, 0);
    BFS(g, 0);
}