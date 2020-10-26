/**
 * 图：
 * 
 * 基本知识点：
 * 阶、度
 * 树、森林、环
 * 有向图、无向图、完全有向图、完全无向图
 * 连通图、连通分量
 * 图的存储和表达方式：邻接矩阵、邻接链表
 * 
 * 算法：
 * 图的遍历：深度优先、广度优先
 * 环的检测：有向图、无向图
 * 拓扑排序：
 * 最短路径算法：Dijkstra, Bellman-Ford, Loyd warshall
 * 连通性相关算法：Kosaraju, Tarjan, 求解孤岛的数量, 判断是否为树
 * 图的着色，旅行商问题等
 * 
 * 
 * 必须掌握的知识点：
 * 图的存储和表达方式：邻接矩阵、邻接链表
 * 图的遍历：深度优先、广度优先
 * 二部图的献策（Bipartite）、树的检测、环的检测：有向图、无向图
 * 拓扑排序
 * 联合-查找算法（Union-Find，并查集） 
 * 最短路径：Dijkstra、Bellman-Ford
 * 
 */


#include <queue>
#include <iostream>
using namespace std;

struct GarphNode
{
    int label;
    vector<GarphNode *> neighbors;
    GarphNode(int x) : label(x) {}
};

// 图的宽度优先遍历
void BFS_graph(GarphNode *root, int visit[]) // visit[]为邻接表
{
    queue<GarphNode *> Q;
    Q.push(root);
    visit[root->label] = 1;
    while (!Q.empty())
    {
        GarphNode *node = Q.front();
        Q.pop();
        printf("%d", node->label);
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            if (visit[node->neighbors[i]->label == 0]) // 判断当前遍历点i的每个邻接点的visit值是否为0
            {
                Q.push(node->neighbors[i]);
                visit[node->neighbors[i]->label] = 1;
            }
        }
    }
}

// 图的深度优先遍历
void DFS_graph(GarphNode *node, int visit[]) // visit[]为邻接表
{
    visit[node->label] = 1;                          // 标记已访问顶点
    for (int i = 0; i < node->neighbors.size(); i++) // F访问相邻的且还没有被访问的顶点
    {
        if (visit[node->neighbors[i]->label] == 0) // 判断当前遍历点i的每个邻接点的visit值是否为0
        {
            DFS_graph(node->neighbors[i], visit);
        }
    }
}
