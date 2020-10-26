#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert> 
using namespace std;

template <typename Graph, typename Weight>  // DenseGraph或SparseGraph
class ReadGraph
{
public:
    ReadGraph(Graph &graph, const string &filename)
    {
        ifstream file(filename);
        string line;
        int vertex, edge;

        assert(file.is_open());
        
        assert(getline(file, line));
        stringstream ss(line);
        ss >> vertex >> edge;
        
        assert(vertex == graph.get_vertex());

        for (int i = 0; i < edge; i++)
        {
            assert(getline(file, line));
            stringstream ss(line);
            
            int a, b;
            Weight w;
            ss >> a >> b >> w;
            assert(a >= 0 && a < vertex);
            assert(b >= 0 && b < vertex);
            graph.AddEdge(a, b, w);
        }
    }
};