/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 *
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (68.45%)
 * Likes:    189
 * Dislikes: 0
 * Total Accepted:    48K
 * Total Submissions: 68.6K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
 * 
 * 说明：
 * 你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
 * 
 * 示例 1:
 * 
 * 输入: root = [3,1,4,null,2], k = 1
 * ⁠  3
 * ⁠ / \
 * ⁠1   4
 * ⁠ \
 * 2
 * 输出: 1
 * 
 * 示例 2:
 * 
 * 输入: root = [5,3,6,2,4,null,null,1], k = 3
 * ⁠      5
 * ⁠     / \
 * ⁠    3   6
 * ⁠   / \
 * ⁠  2   4
 * ⁠ /
 * ⁠1
 * 输出: 3
 * 
 * 进阶：
 * 如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 基于栈的深度优先搜索 方法一
// 24ms runtime 78%
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int num = 0;
        stack<TreeNode *> st;
        TreeNode *p_curr = root;
        while (p_curr != nullptr || !st.empty())
        {
            if (p_curr != nullptr)
            {
                st.push(p_curr);
                p_curr = p_curr->left;
            }
            else
            {
                p_curr = st.top();
                st.pop();
                if (++num == k)
                    return p_curr->val;
                p_curr = p_curr->right;
            }
        }
        return 0;
    }
};

// 基于栈的深度优先搜索 方法二
// 28ms runtime 60%
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int num = 0;
        stack<TreeNode*> st;
        TreeNode * curr = root;
        while (curr || !st.empty())
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if (++num == k) return curr->val;
            curr = curr->right;
        }
        return 0;
    }
};


/**
 * 深度优先搜索 递归形式
 * 遇到第k个数就返回 28ms runtime：60%
 * 二叉搜索树中序遍历恰好是递增序列
 * 
 */
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int cnt = k, res = 0;
        DFS(root, cnt, res);
        return res;
    }

private:
    void DFS(TreeNode *node, int &cnt, int &res)
    {
        if (node == nullptr) // 如果node不存在
            return;
        DFS(node->left, cnt, res);
        if (--cnt == 0)
        {
            res = node->val;
            return;
        }
        DFS(node->right, cnt, res);
    }
};

/**
 * 深度优先搜索 递归形式
 * 
 * 问题分析
 * 只通过了39/91
 * 二叉排序树碰到了两个相同的值
 * [41,37,44,24,39,42,48,1,35,38,40,null,43,46,49,0,2,30,36,null,null,null,null,null,null,45,47,null,null,null,null,null,4,29,32,null,null,null,null,null,null,3,9,26,null,31,34,null,null,7,11,25,27,null,null,33,null,6,8,10,16,null,null,null,28,null,null,5,null,null,null,null,null,15,19,null,null,null,null,12,null,18,20,null,13,17,null,null,22,null,14,null,null,21,23]
 * Output: 25
 * Expected Answer: 24
 * 
 * 原因是其中元素有0值，而非null，下述语句有歧义，自动剔除了0值
 * if (node->val != NULL)
 * 将其更改为 if (node != nullptr)即可
 * 
 * AC：91/91, 24ms, runtime: 78%
 * 
 */
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> vec;
        DFS(root, vec);
        return vec[k - 1];
    }

private:
    void DFS(TreeNode *node, vector<int> &vec)
    {
        if (node == nullptr)
            return;
        DFS(node->left, vec);
        // if (node->val != NULL)
        if (node != nullptr)
            vec.push_back(node->val);
        DFS(node->right, vec);
    }
};
// @lc code=end
