/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (root == nullptr)
            return res;
        if (root->left == nullptr && root->right == nullptr)
        {
            res.emplace_back(to_string(root->val));
            return res;
        }

        vector<string> left_str = binaryTreePaths(root->left);
        for (int i = 0; i < left_str.size(); i++)
        {
            res.emplace_back(to_string(root->val) + "->" + left_str[i]);
        }

        vector<string> right_str = binaryTreePaths(root->right);
        for (int i = 0; i < right_str.size(); i++)
        {
            res.emplace_back(to_string(root->val) + "->" + right_str[i]);
        }

        return res;
    }
};
// @lc code=end
