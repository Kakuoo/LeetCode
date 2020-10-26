/**
 * 求图的连通分量
 */

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include <iostream>
#include <cassert>
#include "DenseGraph.h"
using namespace std;

template <typename Graph>
class Component
{
private:
    Graph G;
    bool *visited;       // 记录是否访问过该节点
    int component_count; // 统计连通分量
    int *id;             // 通过连通分量判断两个节点是否相连，相连的节点的id取相同的值，不相连的取不同值

    void DFS(int v)
    {
        visited[v] = true;
        id[v] = component_count;
        // Graph::AdjIterator adj(G, v); // 这样写有错误，编译器不清楚AdjIterator是Graph类中的一个类型还是成员变量
        typename Graph::AdjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next())
        {
            if (!visited[i])
                DFS(i);
        }
    }

public:
    Component(Graph &graph) : G(graph), component_count(0)
    {
        visited = new bool[G.get_vertex()];
        id = new int[G.get_vertex()];
        for (int i = 0; i < G.get_vertex(); i++)
        {
            visited[i] = false;
            id[i] = -1;
        }

        for (int i = 0; i < G.get_vertex(); i++)
        {
            if (!visited[i])
            {
                DFS(i);
                component_count++;
            }
        }
    }

    ~Component()
    {
        delete[] visited;
        delete[] id;
    }

    int get_count()
    {
        return component_count;
    }

    bool is_connected(int v, int w)
    {
        assert(v >= 0 && v < G.get_vertex());
        assert(w >= 0 && w < G.get_vertex());
        return id[v] == id[w];
    }
};

#endif // GRAPH_COMPONENT_H