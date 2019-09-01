#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::vector;
using std::cout;
using std::endl;
using std::queue;
using std::stack;

const static int NUM_OF_VERTEX = 8;
const static int VISITED = 1;
const static int UNVISITED = 0;

class Graph
{
public:
    Graph(int numVert);
    ~Graph();
    
    void Init(int n);
    
    int GetVertexNum();

    int GetEdgeNum();

    int GetFirstNeighbor(int v);

    int GetNextNeighbor(int v, int w);

    void SetEdge(int v1, int v2, int wt);

    void DelEdge(int v1, int v2);

    bool IsEdge(int v1, int v2);

    int GetWeight(int v1, int v2);

    int GetMark(int v);

    void SetMark(int v1, int val);

    void PrintMatrix();
private:
    int m_numVertex;  
    int m_numEdge;    
    int **m_matrix;   
    int *m_mark;        
};
