#include <iostream>
#include <iomanip>
#include <ctime>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"

using namespace std;

int main()
{
    string filename = "testG1.txt";
    int V = 8;
    cout << fixed << setprecision(2);

    DenseGraph<double> g1 = DenseGraph<double>(V, false);
    ReadGraph<DenseGraph<double>, double> read_graph1(g1, filename);
    g1.show();
    cout << endl;

    SparseGraph<double> g2 = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> read_graph2(g2, filename);
    g2.show();
    cout << endl;

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