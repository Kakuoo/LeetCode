/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 方法一
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int depth(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return max(depth(node->left), depth(node->right)) + 1;
    }
};

// 方法二
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return TreeDepth(root) != -1;
    }

private:
    int TreeDepth(TreeNode *node)
    {
        if (node == nullptr)
            return true;

        int left = TreeDepth(node->left);
        if (left == -1)
            return -1;
        int right = TreeDepth(node->right);
        if (right == -1)
            return -1;
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
};
// @lc code=end
