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

    // 初始化
    void Init(int n);

    // 获取顶点数
    int GetVertexNum();

    // 获取边数
    int GetEdgeNum();

    // 获取指定结点的第一个邻居结点
    int GetFirstNeighbor(int v);

    // 获取指定结点的一下一个邻居结点
    int GetNextNeighbor(int v, int w);

    // 设置一条边
    void SetEdge(int v1, int v2, int wt);

    // 删除一条边
    void DelEdge(int v1, int v2);

    // 两点之间是否有一条边
    bool IsEdge(int v1, int v2);

    // 获取两点之间边的权重
    int GetWeight(int v1, int v2);

    // 获取指定点的标记
    int GetMark(int v);

    // 给指定点设置标记
    void SetMark(int v1, int val);

    // 打印矩阵
    void PrintMatrix();
private:
    int m_numVertex;    // 结点数
    int m_numEdge;      // 边数
    int **m_matrix;     // 邻接矩阵
    int *m_mark;        // 标记数组
};
