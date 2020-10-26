#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"
using namespace std;

int main()
{
    string filename = "testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> read_graph(g, filename);
    g.show();
    cout << endl;

    Path<SparseGraph> dfs_path(g, 0);
    cout << "DFS: ";
    dfs_path.show_path(6);

    ShortestPath<SparseGraph> bfs_path(g, 0);
    cout << "BFS: ";
    bfs_path.show_path(6);

    return 0;
}


// int main()
// {
//     string filename1 = "testG1.txt";
//     SparseGraph g1(13, false);
//     ReadGraph<SparseGraph> read_graph1(g1, filename1);
//     Component<SparseGraph> component1(g1);
//     g1.show();
//     cout << "TestG1.txt, Component Count: " << component1.get_count() << endl;

//     cout << endl;

//     string filename2 = "testG2.txt";
//     DenseGraph g2(7, false);
//     ReadGraph<DenseGraph> read_graph2(g2, filename2);
//     Component<DenseGraph> component2(g2);
//     g2.show();
//     cout << "TestG2.txt, Component Count: " << component2.get_count() << endl;

//     return 0;
// }


// int main()
// {
//     int N = 20;  // 20个节点
//     int M = 100; // 100条边

//     srand((unsigned int)time(nullptr));

//     // Sparse Graph
//     SparseGraph g1(N, false);
//     for (int i = 0; i < M; i++)
//     {
//         int a = rand() % N;
//         int b = rand() % N;
//         g1.AddEdge(a, b);
//     }

//     // 复杂度O(E)，基于边数
//     for (int v = 0; v < N; v++)
//     {
//         cout << v << " : ";
//         SparseGraph::AdjIterator adj(g1, v);
//         for (auto w = adj.begin(); !adj.end(); w = adj.next())
//             cout << w << " ";
//         cout << endl;
//     }
//     cout << endl;

//     // Dense Graph
//     DenseGraph g2(N, false);
//     for (int i = 0; i < M; i++)
//     {
//         int a = rand() % N;
//         int b = rand() % N;
//         g2.AddEdge(a, b);
//     }

//     // 复杂度O(V^2)，基于顶点的平方
//     for (int v = 0; v < N; v++)
//     {
//         cout << v << " : ";
//         DenseGraph::AdjIterator adj(g2, v);
//         for (auto w = adj.begin(); !adj.end(); w = adj.next())
//             cout << w << " ";
//         cout << endl;
//     }
//     cout << endl;

//     return 0;
// }