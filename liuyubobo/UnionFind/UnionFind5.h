/**
 * Quick Union 路径压缩
 * 
 * 在当前节点向上搜索，若未找到节点，
 * 则将该节点向上迁移一些位置，
 * 使其尽量靠近根节点
 * 
 * 时间复杂度近乎为O(1)
 *  
 */

#ifndef UNIONFIND_UNIONFIND5_H
#define UNIONFIND_UNIONFIND5_H

#include <cassert>
using namespace std;

namespace UF5
{
    class UnionFind5
    {
    private:
        int *parent;
        int *rank; // rank[i]表示以i为根节点的树的高度
        int count_;

    public:
        UnionFind5(int n) : count_(n)
        {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind5()
        {
            delete[] parent;
            delete[] rank;
        }

        // 通过p索引不断地追溯自己的根节点
        // 直到p索引等于自己的根节点
        int Find(int p)
        {
            assert(p >= 0 && p < count_);
            
            /* 路径压缩： 方法一 */
            while (p != parent[p])
            {
                parent[p] = parent[parent[p]];  // 路径压缩相对于UnionFind4只此一句修改
                p = parent[p];
            }
            return p;

            /* 路径压缩： 方法二 理论上更好，但是实际递归中有时间损耗*/
            while (p != parent[p])
            {
                parent[p] = Find(parent[p]);
            }
            return parent[p];
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
} // namespace UF5

#endif // UNIONFIND_UNIONFIND5_H
