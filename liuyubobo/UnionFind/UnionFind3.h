/**
 * Quick Union 基于size的改进
 * 
 * 不应固定合并元素的顺序，会导致有高度过高的集合产生
 * 应该存储每个集合有多少个元素，在进行合并操作的时候，
 * 永远将元素少的集合合并至元素多的根节点上
 * 尽量使并查集的高度较低
 *  
 */

#ifndef UNIONFIND_UNIONFIND3_H
#define UNIONFIND_UNIONFIND3_H

#include <cassert>
using namespace std;

namespace UF3
{
    class UnionFind3
    {
    private:
        int *parent;
        int *sz; // sz[i]表示以i为根节点的集合中元素个数
        int count_;

    public:
        UnionFind3(int n) : count_(n)
        {
            parent = new int[n];
            sz = new int[n];
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
                sz[i] = 1;
            }
        }

        ~UnionFind3()
        {
            delete[] parent;
            delete[] sz;
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

            if (sz[p_root] <= sz[q_root])
            {
                parent[p_root] = q_root;
                sz[q_root] += sz[p_root];
            }
            else
            {
                parent[q_root] = p_root;
                sz[p_root] += q_root;
            }   
        }
    };
} // namespace UF3

#endif // UNIONFIND_UNIONFIND3_H
