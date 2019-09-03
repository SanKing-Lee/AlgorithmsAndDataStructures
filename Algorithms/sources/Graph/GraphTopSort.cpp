#include "Graph.h"

/**
 * @brief   递归进行拓扑排序，对每个点利用深度优先算法遍历它的依赖项，
 *          当所有的依赖项（邻居以及邻居的邻居）遍历完成，则该事件也可以完成了
 * @param [in] g: 图结构体指针
 */
static void RecurssiveTopSort(Graph *g);
/**
 * @brief 递归拓扑排序的辅助函数，在深度遍历的过程中不断地查找依赖项，所有依赖项完成后，输出当前结点
 * @param [in] g: 图结构体指针
 * @param [in] v: 图结点 
 */
static void RecurssiveTopSortHelp(Graph *g, int v);
/**
 * @brief 利用栈进行非递归的拓扑排序，把初始点压入栈中，并设置它的标记为VISITED，
 *      寻找它的依赖项（邻居），把依赖项压入栈中，当它的所有依赖项完成了，也即所有邻居完成了，栈顶即为该结点
 * @param [in] g: 图指针
 */
static void StackTopSort(Graph *g);
/**
 * @brief 利用队列进行拓扑排序，计算每个结点的依赖项个数，如果依赖项个数为0，则可出队
 * @param [in] g: 图指针
 */
static void QueueTopSort(Graph *g);

void RecurssiveTopSort(Graph *g)
{
    // 初始化标记为未访问
    for (int i = 0; i < g->GetVertexNum(); i++)
    {
        g->SetMark(i, UNVISITED);
    }
    // 对每个点进行遍历
    for (int i = 0; i < g->GetVertexNum(); i++)
    {
        if (g->GetMark(i) == UNVISITED)
        {
            // 递归寻找接下来的依赖
            RecurssiveTopSortHelp(g, i);
        }
    }
}

void RecurssiveTopSortHelp(Graph *g, int v)
{
    // 设置标记
    g->SetMark(v, VISITED);
    // 递归对邻居进行操作
    for (int w = g->GetFirstNeighbor(v); w < g->GetVertexNum(); w = g->GetNextNeighbor(v, w))
    {
        if (g->GetMark(w) == UNVISITED)
        {
            RecurssiveTopSortHelp(g, w);
        }
    }
    // 所有的依赖项（单向邻居）都完成了，该结点也就可以完成了
    cout << "Finish node: " << v << endl;
}

void StackTopSort(Graph *g)
{
    // 初始化栈
    stack<int> vertexStack;
    for (int i = 0; i < g->GetVertexNum(); i++)
    {
        g->SetMark(i, UNVISITED);
        vertexStack.push(i);
    }

    // 深度优先遍历所有的结点
    while (!vertexStack.empty())
    {
        int v = vertexStack.top();
        // 如果当前结点已经访问过，则可以弹出并显示该结点事件已完成
        if (g->GetMark(v) == VISITED)
        {
            cout << "Finish node: " << v << endl;
            vertexStack.pop();
            continue;
        }
        g->SetMark(v, VISITED);
        // 遍历所有的依赖项（邻居）并加入所有未访问过的依赖项
        for (int w = g->GetFirstNeighbor(v); w < g->GetVertexNum(); w = g->GetNextNeighbor(v, w))
        {
            if (g->GetMark(w) == UNVISITED)
            {
                vertexStack.push(w);
            }
        }
    }
}

void QueueTopSort(Graph *g)
{
    queue<int> vertexQueue;
    // 用于记录每个结点的依赖项个数，并初始化为0
    int *count = new int[g->GetVertexNum()]();
    // 根据图设置结点的邻居依赖项个数，它的邻居即为依赖它的结点
    for (int i = 0; i < g->GetVertexNum(); i++)
    {
        for (int w = g->GetFirstNeighbor(i); w < g->GetVertexNum(); w = g->GetNextNeighbor(i, w))
        {
            count[w]++;
        }
    }
    // 找到所有依赖项为0的结点，即可以在一开始就完成的事件
    for (int i = 0; i < g->GetVertexNum(); i++)
    {
        if (count[i] == 0)
        {
            vertexQueue.push(i);
        }
    }
    while (!vertexQueue.empty())
    {
        // 获取队列的首部结点
        int v = vertexQueue.front();
        // 如果当前首部结点的依赖项为0，则该结点可弹出
        // 并将所有依赖该结点的结点（即该结点的邻居结点）的依赖项个数减1
        if (count[v] == 0)
        {
            cout << "Finish node: " << v << endl;
            vertexQueue.pop();
            for (int w = g->GetFirstNeighbor(v); w < g->GetVertexNum(); w = g->GetNextNeighbor(v, w))
            {
                count[w]--;
                // 如果邻居结点的依赖项个数减为0，则意味着该结点也完成了，加入队列
                if (count[w] == 0)
                {
                    vertexQueue.push(w);
                }
            }
        }
    }
}

void TestGraphTopSort()
{
    Graph *g = new Graph(7);
    g->InitFromFile("./Algorithms/config/TestGraphTopSortEdges.txt");
    // RecurssiveTopSort(g);
    // StackTopSort(g);
    QueueTopSort(g);
}