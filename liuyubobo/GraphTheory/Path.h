#include <cassert>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

template <typename Graph>
class Path
{
private:
    Graph &G;
    int s; // source 原点 求从该点到其他任意一个点的路径
    bool *visited;
    int *from;

    void DFS(int v)
    {
        visited[v] = true;
        // Graph::AdjIterator adj(G, v); // 这样写有错误，编译器不清楚AdjIterator是Graph类中的一个类型还是成员变量
        typename Graph::AdjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next())
        {
            if (!visited[i])
            {
                from[i] = v;
                DFS(i);
            }
        }
    }

public:
    Path(Graph &graph, int s) : G(graph), s(s)
    {
        assert(s >= 0 && s < G.get_vertex());

        visited = new bool[G.get_vertex()];
        from = new int[G.get_vertex()];
        for (int i = 0; i < G.get_vertex(); i++)
        {
            visited[i] = false;
            from[i] = -1;
        }

        // 寻找路径算法
        DFS(s);
    }

    ~Path()
    {
        delete[] visited;
        delete[] from;
    }

    // 原点s到目标点w是否存在路径
    bool has_path(int w)
    {
        assert(w >= 0 && w < G.get_vertex());
        return visited[w];
    }

    // 将原点s到目标点w的路径存在vec中，非最短路径
    void get_path(int w, vector<int> &vec)
    {
        stack<int> s; // 倒推的过程，适合用栈
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

    // 打印从s到w的路径
    void show_path(int w)
    {
        vector<int> vec;
        get_path(w, vec);

        // for (auto e : vec)
        // {
        //     cout << e;
        //     if (e == vec.back())
        //     {
        //         cout << endl;
        //     }
        //     else
        //     {
        //         cout << " -> ";
        //     }
        // }
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
            if (i == vec.size() - 1)
                cout << endl;
            else
                cout << " -> ";
        }
    }
};