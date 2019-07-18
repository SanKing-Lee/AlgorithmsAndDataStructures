#include "Graph.h"

void DeepFirstSearch(Graph g, int s);
void BreadthFirstSearch(Graph g, int s);
void RecurTopSort(Graph g);
void RecurTopSortHelp(Graph g, int v);
void QueueBasedTopSort(Graph g, queue<int> q);


int main() {
    Graph graph(6);
    graph.SetEdge(0,2,1);
    graph.SetEdge(2,0,1);
    graph.SetEdge(0,4,1);
    graph.SetEdge(4,0,1);
    graph.SetEdge(1,2,1);
    graph.SetEdge(2,1,1);
    graph.SetEdge(1,5,1);
    graph.SetEdge(5,1,1);
    graph.SetEdge(2,3,1);
    graph.SetEdge(3,2,1);
    graph.SetEdge(2,5,1);
    graph.SetEdge(5,2,1);
    graph.SetEdge(3,5,1);
    graph.SetEdge(5,3,1);
    graph.SetEdge(4,5,1);
    graph.SetEdge(5,4,1);
//    cout << "vertex number: " << graph.GetVertexNum() << endl;
//    cout << "edge number: "  << graph.GetEdgeNum() << endl;
//    graph.PrintMatrix();
    DeepFirstSearch(graph, 0);
    return 0;
}

void DeepFirstSearch(Graph g, int s) {
    stack<int> searchStack;
    searchStack.push(s);
    while(!searchStack.empty()) {
        int curVertex = searchStack.top();
        searchStack.pop();
        if(g.GetMark(curVertex) == UNVISITED) {
            cout << "Searched: " << curVertex << endl;
        }
        g.SetMark(curVertex, VISITED);
        for (int i = g.GetFirstNeighbor(curVertex);
                i < g.GetVertexNum(); i = g.GetNextNeighbor(curVertex, i)) {
            if (g.GetMark(i) == UNVISITED) {
//                g.SetMark(i, VISITED);
                searchStack.push(i);
            }
        }
    }
}
