#ifndef GRAPHTHEORY_GRAPHGRAPH_H
#define GRAPHTHEORY_GRAPHGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 稠密图 - 邻接矩阵
// 顶点 Vertex， 边 Edge
class DenseGraph
{
private:
    int n, m;      // n 点数，m 边数
    bool directed; // 判断有向图或无向图
    vector<vector<bool>> g;

public:
    DenseGraph(int n, bool directed) : n(n), m(0), directed(directed)
    {
        for (int i = 0; i < n; i++)
        {
            g.push_back(vector<bool>(n, false));
        }
    }

    ~DenseGraph() {}

    int get_vertex() { return n; }
    int get_edge() { return m; }

    // 在顶点v和顶点w之间建立一条边
    void AddEdge(int v, int w)
    {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        if (has_edge(v, w)) // 解决平行边
            return;

        g[v][w] = true;
        if (!directed) // 若为无向图
        {
            g[w][v] = true;
        }
        m++;
    }

    bool has_edge(int v, int w)
    {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        return g[v][w];
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
        DenseGraph &G;
        int v;
        int index;

    public:
        AdjIterator(DenseGraph &graph, int v) : G(graph), v(v), index(-1) {}

        // 迭代器的begin()方法，访问第一个元素
        // 邻接矩阵第一个元素不一定为true，需要返回第一个为true的元素
        int begin()
        {
            index = -1;
            return next();
        }

        int next()
        {
            for (index++; index < G.get_vertex(); index++)
            {
                if (G.g[v][index] == true)
                    return index;
            }
            return -1;
        }

        bool end()
        {
            return index >= G.get_vertex();
        }
    };
};

#endif // GRAPHTHEORY_GRAPHGRAPH_H