/**
 * Quick Union
 * 使得合并这个操作非常快
 * 
 * 将每一个元素，看做是一个节点
 * 每个节点都有一个指向父节点的指针
 * 
 * 逻辑上p和q连接在一起表现为他们拥有同样的根
 *  
 */

#ifndef UNIONFIND_UNIONFIND2_H
#define UNIONFIND_UNIONFIND2_H

#include <cassert>
using namespace std;

namespace UF2
{
    class UnionFind2
    {
    private:
        int *parent;
        int count_;

    public:
        UnionFind2(int n) : count_(n)
        {
            parent = new int[n];
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        ~UnionFind2()
        {
            delete[] parent;
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
            parent[p_root] = q_root;
        }
    };
} // namespace UF2

#endif // UNIONFIND_UNIONFIND2_H
