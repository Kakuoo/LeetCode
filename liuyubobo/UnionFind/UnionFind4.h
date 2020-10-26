/**
 * Quick Union 基于层数rank的改进
 * 
 * 建议：
 * 相比于基于size的改进，建议使用基于层数rank的改进
 * 
 * 可以在合并操作时，考虑基于并查集的层数进行判断
 * 永远将rank小的集合合并至rank大的根节点上
 *  
 */

#ifndef UNIONFIND_UNIONFIND4_H
#define UNIONFIND_UNIONFIND4_H

#include <cassert>
using namespace std;

namespace UF4
{
    class UnionFind4
    {
    private:
        int *parent;
        int *rank; // rank[i]表示以i为根节点的树的高度
        int count_;

    public:
        UnionFind4(int n) : count_(n)
        {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind4()
        {
            delete[] parent;
            delete[] rank;
        }

        // 通过p索引不断地追溯自己的根节点
        // 直到p索引等于自己的根节点
        int Find(int p)
        {
            assert(p >= 0 && p < count_);

            while (p != parent[p])
            {
                p = parent[p];
            }
            return p;
        }

        bool IsConnected(int p, int q)
        {
            return Find(p) == Find(q);
        }

        void UnionElements(int p, int q)
        {
            int p_root = Find(p);
            int q_root = Find(q);

            if (p_root == q_root)
                return;

            if (rank[p_root] < rank[q_root])
            {
                parent[p_root] = q_root;
            }
            else if (rank[p_root] > rank[q_root])
            {
                parent[q_root] = p_root;
            }
            else if (rank[p_root] == rank[q_root])
            {
                parent[p_root] = q_root;
                rank[q_root]++;
            }
        }
    };
} // namespace UF4

#endif // UNIONFIND_UNIONFIND4_H
