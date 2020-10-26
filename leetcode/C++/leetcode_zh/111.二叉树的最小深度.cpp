/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        if (root->left != nullptr && root->right != nullptr)
            return std::min(minDepth(root->left), minDepth(root->right)) + 1;
        if (root->left != nullptr)
            return minDepth(root->left) + 1;
        if (root->right != nullptr)
            return minDepth(root->right) + 1;
        return 1;
    }
};

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left_num = minDepth(root->left);
        int right_num = minDepth(root->right);
        return (left_num && right_num) ? std::min(left_num, right_num) + 1 : left_num + right_num + 1;
    }
};
// @lc code=end
