/**
 * UnionFind 并查集
 * 
 * 可用于判断网络中节点的连接状态，
 * 可实现数学中的集合类实现
 * 
 * 对于路径问题，连接问题比路径问题回答的内容要少
 * 与排序算法做比较；
 * 与select（找出排名第几的元素）做比较；
 * 与堆做比较；
 * 
 * 
 * 对于一组数据主要支持两个操作
 * union(p, q)
 * find(p)
 * is_connected(p, q)
 * 
 */

#ifndef UNIONFIND_UNIONFIND1_H
#define UNIONFIND_UNIONFIND1_H
#include <cassert>
using namespace std;

namespace UF1
{
    class UnionFind
    {
    private:
        int *id;
        int count_;

    public:
        UnionFind(int n) : count_(n)
        {
            id = new int[n];
            for (int i = 0; i < n; i++)
            {
                id[i] = i;
            }
        }
        ~UnionFind()
        {
            delete[] id;
        }

        int Find(int p)
        {
            assert(p >= 0 && p < count_);
            return id[p];
        }

        bool IsConnected(int p, int q)
        {
            return Find(p) == Find(q);
        }

        void UnionElements(int p, int q)
        {
            int p_id = Find(p);
            int q_id = Find(q);
            if (p_id == q_id)
            {
                return;
            }

            for (int i = 0; i < count_; i++)
            {
                if (id[i] == p_id)
                {
                    id[i] = q_id;
                }
            }
        }
    };
} // namespace UF1

#endif // UNIONFIND_UNIONFIND1_H