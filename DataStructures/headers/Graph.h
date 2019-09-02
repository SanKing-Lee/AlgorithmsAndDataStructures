#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::queue;
using std::stack;
using std::string;

const static int NUM_OF_VERTEX = 8;
const static int VISITED = 1;
const static int UNVISITED = 0;

const static int OPEN_FILE_FAILED = -1;

class Graph
{
public:
    Graph(int numVert);
    ~Graph();
    
    void Init(int n);

    int InitFromFile(const string &filename);
    
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
