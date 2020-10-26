#include <queue>
#include <stack>
#include <cassert>
using namespace std;

template <typename Graph>
class ShortestPath
{
private:
    Graph &G;
    int s;
    bool *visited;
    int *from;
    int *ord; // order 记录最短距离的顺序

public:
    ShortestPath(Graph &graph, int s) : G(graph), s(s)
    {
        assert(s >= 0 && s < G.get_vertex());

        visited = new bool[G.get_vertex()];
        from = new int[G.get_vertex()];
        ord = new int[G.get_vertex()];
        for (int i = 0; i < G.get_vertex(); i++)
        {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }


        // 无向图最短路径算法
        // 使用广度优先遍历（BFS）一定可以找到最短路径
        // 使用深度优先遍历不一定（取决于图是如何存储的，以及边加入的顺序）
        queue<int> Q;
        Q.push(s);
        visited[s] = true;
        ord[s] = 0;
        while (!Q.empty())
        {
            int v = Q.front();
            Q.pop();

            typename Graph::AdjIterator adj(G, v);
            for (auto i = adj.begin(); !adj.end(); i = adj.next())
            {
                if (!visited[i])
                {
                    Q.push(i);
                    visited[i] = true;
                    from[i] = v;
                    ord[i] = ord[v] + 1;
                }
            }
        }
    }

    ~ShortestPath()
    {
        delete[] visited;
        delete[] from;
        delete[] ord;
    }

    // 原点s到目标点w是否存在路径
    bool has_path(int w)
    {
        assert(w >= 0 && w < G.get_vertex());
        return visited[w];
    }

    // 将原点s到目标点w的路径存在vec中，最短路径
    void get_path(int w, vector<int> &vec)
    {
        assert(w >= 0 && w < G.get_vertex());

        stack<int> s;
        int p = w;
        while (p != -1)
        {
            s.push(p);
            p = from[p];
        }

        vec.clear();
        while (!s.empty())
        {
            vec.push_back(s.top());
            s.pop();
        }
    }

    void show_path(int w)
    {
        assert(w >= 0 && w < G.get_vertex());

        vector<int> vec;
        get_path(w, vec);

        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
            if (i == vec.size() - 1)
            {
                cout << endl;
            }
            else
            {
                cout << " -> ";
            }
        }
    }

    int length(int w)
    {
        assert(w >= 0 && w < G.get_vertex());
        return ord[w];
    }
};
