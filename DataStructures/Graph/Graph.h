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

    // ��ʼ��
    void Init(int n);

    // ��ȡ������
    int GetVertexNum();

    // ��ȡ����
    int GetEdgeNum();

    // ��ȡָ�����ĵ�һ���ھӽ��
    int GetFirstNeighbor(int v);

    // ��ȡָ������һ��һ���ھӽ��
    int GetNextNeighbor(int v, int w);

    // ����һ����
    void SetEdge(int v1, int v2, int wt);

    // ɾ��һ����
    void DelEdge(int v1, int v2);

    // ����֮���Ƿ���һ����
    bool IsEdge(int v1, int v2);

    // ��ȡ����֮��ߵ�Ȩ��
    int GetWeight(int v1, int v2);

    // ��ȡָ����ı��
    int GetMark(int v);

    // ��ָ�������ñ��
    void SetMark(int v1, int val);

    // ��ӡ����
    void PrintMatrix();
private:
    int m_numVertex;    // �����
    int m_numEdge;      // ����
    int **m_matrix;     // �ڽӾ���
    int *m_mark;        // �������
};
