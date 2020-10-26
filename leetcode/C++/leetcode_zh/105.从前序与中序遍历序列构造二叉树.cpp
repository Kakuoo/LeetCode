/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return BuildTreeCore(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }

private:
    TreeNode *BuildTreeCore(int pre_l, int pre_r, int in_l, int in_r,
                            vector<int> &preorder, vector<int> &inorder)
    {
        if (pre_l > pre_r || in_l > in_r)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[pre_l]);

        // 确定前序遍历第一个元素在中序遍历数组中的位置
        int root_idx = in_l;
        while (root_idx <= in_r && preorder[pre_l] != inorder[root_idx])
            root_idx++;

        int width = root_idx - in_l;
        root->left = BuildTreeCore(pre_l + 1, pre_l + width, in_l, root_idx - 1, preorder, inorder);
        root->right = BuildTreeCore(pre_l + 1 + width, pre_r, root_idx + 1, in_r, preorder, inorder);
        return root;
    }
};

// @lc code=end
