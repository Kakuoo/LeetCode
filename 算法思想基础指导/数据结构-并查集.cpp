/*
 * 并查集（Union Find）：不相交集合（Disjoint Set）
 * 
 * 应用于N个元素的集合求并与查询问题
 * 通常开始时让各个元素构成一个单元素的集合，然后按一定顺序将属于
 * 同一组的元素所在的集合合并，期间要反复查找一个元素在哪个集合中。
 * 
 * 当面对极大的数据量的时候，普通的数据结构无法解决，并查集就是解决
 * 该种问题的最优秀的算法。
 * 
 */

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
 * 
 * 1.基于数组形式
 * 2.基于父指针
 * 3.基于size的的改进
 * 4.基于rank（秩，层数）的改进
 * 5.基于路径压缩的改进（两种方法）
 * 
 */

#include <vector>
#include <cassert>
using namespace std;

// 方法一：数组形式
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

/** 方法二：父指针
 * 
 * 将每一个元素，看做是一个节点
 * 每个节点都有一个指向父节点的指针
 * 
 * 逻辑上p和q连接在一起表现为他们拥有同样的根
 * 
 */

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


/**
 * Quick Union 基于size的改进
 * 
 * 不应固定合并元素的顺序，会导致有高度过高的集合产生
 * 应该存储每个集合有多少个元素，在进行合并操作的时候，
 * 永远将元素少的集合合并至元素多的根节点上
 * 尽量使并查集的高度较低
 *  
 */

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
            // while (p != parent[p])
            // {
            //     parent[p] = parent[parent[p]];  // 路径压缩相对于UnionFind4只此一句修改
            //     p = parent[p];
            // }
            // return p;

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

/* 
 * 并查集：森林实现
 * 
 * 使用森林存储集合之间的关系，属于同一集合的不同元素，
 * 都有一个相同的根节点，代表这个集合
 * 
 * 当进行查找某个元素属于哪个集合时，即遍历该元素到根节点，
 * 返回根节点代表的集合；在遍历过程中使用**路径压缩**的优化算法，
 * 使整体树的形状更加扁平，从而优化查询的时间复杂度
 * 
 * 当进行合并时，即将两颗子树合为一棵树，将一颗子树的根节点指向
 * 另一颗子树的根节点；在合并时，可按子树的大小，将规模较小的子树
 * 合并到规模较大的子树上，从而使树规模更加平衡，从而优化未来查询的
 * 时间复杂度
 * 
 */

class DisjointSet
{
public:
    DisjointSet(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            id_.push_back(i);
            size_.push_back(1);
        }
        count_ = n;
    }

    /** 
     * 功能：查找p属于哪个集合
     * 
     * 查找时，增加路径压缩的优化算法
     * 当p与当前集合的id[p]不同时（直到p与id[p]相同时，跳出循环）：
     *      将p的父节点id[p]更新为id[p]的父节点id[id[p]]
     *      p = id[p]
     * 返回p的值
     * 
     */
    int find(int p)
    {
        while (p != id_[p])
        {
            id_[p] = id_[id_[p]];
            p = id_[p];
        }
        return p;
    }

    void union_item(int p, int q)
    {
        int i = find(p);
        int j = find(q);
        if (i == j)
        {
            return;
        }
        if (size_[i] < size_[j])
        {
            id_[i] = j;
            size_[j] += size_[i];
        }
        else
        {
            id_[j] = i;
            size_[i] += size_[j];
        }
        count_--;
    }

private:
    vector<int> id_;
    vector<int> size_;
    int count_;
};

/* 
 * 此方法：复杂度O(n)
 * 但是时间复杂度过高，含有大量合并操作
 * 
 */
class DisjointSet_bad
{
public:
    DisjointSet_bad(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            id_.push_back(i);
        }
    }

    int find(int p) // 查询元素p属于哪个集合
    {
        return id_[p];
    }

    void union_item(int p, int q) // 合并时，若两个元素属于同一个集合，则直接返回
    {
        int p_id = find(p);
        int q_id = find(q);
        if (p_id == q_id)
        {
            return;
        }
        for (int i = 0; i < id_.size(); ++i)
        {
            if (id_[i] == p_id)
            {
                id_[i] = q_id; // 将属于pid集合的元素全部改成属于qid对应的集合
            }
        }
    }

private:
    vector<int> id_;
};