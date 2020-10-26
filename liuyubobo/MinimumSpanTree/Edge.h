#ifndef MINIMUMSPANTREE_EDGE_H
#define MINIMUMSPANTREE_EDGE_H

#include <iostream>
#include <cassert>
using namespace std;

// 图中有权重的边
template <typename Weight>
class Edge
{
private:
    int a, b; // 对于无向边a,b顺序不重要，对于有向边，a指向b
    Weight weight;

public:
    Edge() {}

    Edge(int a, int b, Weight weight) : a(a), b(b), weight(weight) {}

    ~Edge() {}

    int get_v() { return a; }
    int get_w() { return b; }

    Weight get_weight() { return weight; }

    // 当已知边的其中一个顶点x，想获取另一个顶点时
    int other(int x)
    {
        assert(x == a && x == b);
        return x == a ? b : a;
    }

    bool &operator<(Edge<Weight> &edge)
    {
        return this->weight < edge.get_weight();
    }

    bool &operator<=(Edge<Weight> &edge)
    {
        return this->weight <= edge.get_weight();
    }

    bool &operator>(Edge<Weight> &edge)
    {
        return this->weight > edge.get_weight();
    }

    bool &operator>=(Edge<Weight> &edge)
    {
        return this->weight >= edge.get_weight();
    }

    bool &operator==(Edge<Weight> &edge)
    {
        return this->weight == edge.get_weight();
    }

    friend ostream &operator<<(ostream &os, const Edge &edge)
    {
        os << edge.a << "-" << edge.b << ": " << edge.get_weight();
        return os;
    }
};

#endif // MINIMUMSPANTREE_EDGE_H