/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr)
            return false;
        if (q == nullptr)
            return false;

        if (p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);   
        }
        else
        {
            return false;
        }
        
    }
};

// 简化写法
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr)
            return false;
        if (q == nullptr)
            return false;

        queue<TreeNode *> Q;
        Q.push(p);
        Q.push(q);
        while (Q.size() >= 2)
        {
            TreeNode *p_tmp = Q.front();
            Q.pop();
            TreeNode *q_tmp = Q.front();
            Q.pop();

            if (p_tmp->val != q_tmp->val)
                return false;
            if (p_tmp->left && q_tmp->left)
            {
                Q.push(p_tmp->left);
                Q.push(q_tmp->left);
            }
            else
            {
                if (p_tmp->left != nullptr && q_tmp->left == nullptr)
                {
                    return false;
                }
                if (p_tmp->left == nullptr && q_tmp->left != nullptr)
                {
                    return false;
                }
            }

            if (p_tmp->right && q_tmp->right)
            {
                Q.push(p_tmp->right);
                Q.push(q_tmp->right);
            }
            else
            {
                if (p_tmp->right != nullptr && q_tmp->right == nullptr)
                {
                    return false;
                }
                if (p_tmp->right == nullptr && q_tmp->right != nullptr)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// 复杂写法
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr)
            return false;
        if (q == nullptr)
            return false;
        // else  // 可以替换成简洁的上式
        // {
        //     if (p == nullptr && q != nullptr)
        //         return false;
        //     if (p != nullptr && q == nullptr)
        //         return false;
        // }

        queue<TreeNode *> Q;
        TreeNode *p_bak = p;
        TreeNode *q_bak = q;
        Q.push(p_bak);
        Q.push(q_bak);
        while (Q.size() >= 2)
        {
            TreeNode *p_tmp = Q.front();
            Q.pop();
            TreeNode *q_tmp = Q.front();
            Q.pop();

            if (p_tmp->val != q_tmp->val)
                return false;
            if (p_tmp->left && q_tmp->left)
            {
                Q.push(p_tmp->left);
                Q.push(q_tmp->left);
            }
            else
            {
                if (p_tmp->left != nullptr && q_tmp->left == nullptr)
                {
                    return false;
                }
                if (p_tmp->left == nullptr && q_tmp->left != nullptr)
                {
                    return false;
                }
            }

            if (p_tmp->right && q_tmp->right)
            {
                Q.push(p_tmp->right);
                Q.push(q_tmp->right);
            }
            else
            {
                if (p_tmp->right != nullptr && q_tmp->right == nullptr)
                {
                    return false;
                }
                if (p_tmp->right == nullptr && q_tmp->right != nullptr)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
