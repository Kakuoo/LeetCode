#ifndef GRAPHTHEORY_SPARSEGRAPH_H
#define GRAPHTHEORY_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 稀疏图 - 邻接表
// 顶点 Vertex， 边 Edge
class SparseGraph
{
private:
    int n, m; // n 点数，m 边数
    bool directed;
    vector<vector<int>> g;

public:
    SparseGraph(int n, bool directed) : n(n), m(0), directed(directed)
    {
        for (int i = 0; i < n; i++)
        {
            g.push_back(vector<int>());
        }
    }
    ~SparseGraph() {}

    int get_vertex() { return n; }
    int get_edge() { return m; }

    void AddEdge(int v, int w)
    {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        /* 
        判断有无平行边has_edge的复杂度为O(n)，成本较高
        通常情况下，邻接表的数据结构下，不考虑平行边的问题
        */
        // if (has_edge(v, w))
        //     return;

        g[v].push_back(w);
        if (v != w && !directed) // 不是自环边，且不为无向图
        {
            g[w].push_back(v);
        }
        m++;
    }

    bool has_edge(int v, int w)
    {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        for (int i = 0; i < n; i++)
        {
            if (g[v][i] == w)
                return true;
            return false;
        }
    }

    void show()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "vertex: " << i << ":\t";
            for (int j = 0; j < g[i].size(); j++)
            {
                cout << g[i][j] << "\t";
            }
            cout << endl;
        }
    }

    /**
     * 为了避免将vector<vector<int>> g改为public，避免暴露数据，采用如下方法
     * 保持g为private，还能让外面遍历g，编写函数访问要到某一个节点的所有相邻节点，
     * 可这样每次都需要复制一份，也不理想
     * 
     * 在此，借助迭代器的思想，使用迭代器隐藏过程进而访问所有元素
     * 
     * 遍历图graph中的点v的相邻元素
     * 
     */
    class AdjIterator
    {
    private:
        SparseGraph &G;
        int v;
        int index;

    public:
        // graph：迭代的哪张图，v：迭代是图中哪个顶点，index：迭代到哪里了
        AdjIterator(SparseGraph &graph, int v) : G(graph), v(v), index(0) {}

        // 迭代器的begin()方法，访问第一个元素
        int begin()
        {
            index = 0;
            if (G.g[v].size()) // 不为0，说明有v的相邻节点
                return G.g[v][index];// return G.g[v][0];
            return -1;
        }

        // 迭代器的next()方法，访问下一个元素
        int next()
        {
            index++;
            if (index < G.g[v].size())
                return G.g[v][index];
            return -1;
        }

        // 迭代器的end()方法，判断是否迭代到容器的尾部
        bool end()
        {
            return index >= G.g[v].size();
        }
    };
};

#endif // GRAPHTHEORY_SPARSEGRAPH_H