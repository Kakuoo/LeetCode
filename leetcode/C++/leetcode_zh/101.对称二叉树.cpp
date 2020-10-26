/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归方法
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        return IsMirror(root->left, root->right);
    }

private:
    bool IsMirror(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;

        if (p->val == q->val)
        {
            bool flag1 = IsMirror(p->left, q->right);
            bool flag2 = IsMirror(p->right, q->left);
            return flag1 && flag2;
        }
        return false;
    }
};

// 迭代方法
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        queue<TreeNode *> Q;
        Q.push(root->left);
        Q.push(root->right);
        while (!Q.empty())
        {
            TreeNode *node1 = Q.front();
            Q.pop();
            TreeNode *node2 = Q.front();
            Q.pop();

            if (node1 == nullptr && node2 == nullptr)
            {
                continue;
            }
            if (node1 == nullptr || node2 == nullptr || node1->val != node2->val)
            {
                return false;
            }

            Q.push(node1->left);
            Q.push(node2->right);
            Q.push(node1->right);
            Q.push(node2->left);
        }
        return true;
    }
};
// @lc code=end
