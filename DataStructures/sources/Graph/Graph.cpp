#include "Graph.h"

Graph::Graph(int numVert)
{
    Init(numVert);
}

Graph::~Graph()
{
    delete[] m_mark;
    for (int i = 0; i < m_numVertex; i++)
    {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}

void Graph::Init(int n)
{
    m_numVertex = n;
    m_numEdge = 0;

    m_mark = new int[m_numVertex];
    for (int i = 0; i < m_numVertex; i++)
    {
        m_mark[i] = UNVISITED;
    }
    //    cout << "Initial mark success!" << endl;

    m_matrix = new int *[m_numVertex];
    for (int i = 0; i < m_numVertex; i++)
    {
        m_matrix[i] = new int[m_numVertex];
    }
    //    cout << "Create matrix success!" << endl;
    // cout << UNREACHABLE << endl;
    for (int i = 0; i < m_numVertex; i++)
    {
        for (int j = 0; j < m_numVertex; j++)
        {
            m_matrix[i][j] = UNREACHABLE;
        }
    }
    //    cout << "Initial matrix success!" << endl;
    //
    //    cout << "Initial graph success!" << endl;
}

int Graph::InitFromFile(const string &filename)
{
    ifstream ifsEdgeFile(filename);
    if (!ifsEdgeFile)
    {
        return OPEN_FILE_FAILED;
    }
    int v1, v2, wt;
    ifsEdgeFile >> v1;
    ifsEdgeFile >> v2;
    ifsEdgeFile >> wt;
    while (ifsEdgeFile)
    {
        // cout << "v1: " << v1 << ", v2: " << v2 << ", wt: " << wt << endl;
        SetEdge(v1, v2, wt);
        ifsEdgeFile >> v1;
        ifsEdgeFile >> v2;
        ifsEdgeFile >> wt;
    }
    ifsEdgeFile.close();
    return 0;
}

int Graph::GetVertexNum()
{
    return m_numVertex;
}

int Graph::GetEdgeNum()
{
    return m_numEdge;
}

int Graph::GetFirstNeighbor(int v)
{
    for (int i = 0; i < m_numVertex; i++)
    {
        if (m_matrix[v][i] != UNREACHABLE)
        {
            return i;
        }
    }
    return m_numVertex;
}

int Graph::GetNextNeighbor(int v, int w)
{
    for (int i = w + 1; i < m_numVertex; i++)
    {
        if (m_matrix[v][i] != UNREACHABLE)
        {
            return i;
        }
    }
    return m_numVertex;
}

void Graph::SetEdge(int v1, int v2, int wt)
{
    if (m_matrix[v1][v2] == UNREACHABLE)
    {
        m_numEdge++;
    }
    m_matrix[v1][v2] = wt;
}

void Graph::DelEdge(int v1, int v2)
{
    if (m_matrix[v1][v2] != UNREACHABLE)
    {
        m_numEdge--;
    }
    m_matrix[v1][v2] = 0;
}

bool Graph::IsEdge(int v1, int v2)
{
    return m_matrix[v1][v2] != UNREACHABLE;
}

int Graph::GetWeight(int v1, int v2)
{
    return m_matrix[v1][v2];
}

int Graph::GetMark(int v)
{
    return m_mark[v];
}

void Graph::SetMark(int v, int val)
{
    m_mark[v] = val;
}

void Graph::PrintMatrix()
{
    for (int i = 0; i < m_numVertex; i++)
    {
        for (int j = 0; j < m_numVertex; j++)
        {
            cout << m_matrix[i][j] << " ";
        }
        cout << endl;
    }
}
