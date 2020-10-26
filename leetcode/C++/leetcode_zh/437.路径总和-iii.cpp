/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    // 在以root为根节点的二叉树中，寻找为sum的路径，返回这样的路径个数
    int pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return 0;
        int res = FindPath(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        
        return res;
    }

private:
    // 以node为根节点的二叉树中，寻找包含node的路径，和为sum
    // 返回这样的路径个数
    int FindPath(TreeNode *node, int num)
    {
        if (node == nullptr)
            return 0;
        
        int res = 0;
        if (node->val == num)
        {
            res +=1 ;
        }

        res += FindPath(node->left, num - node->val);
        res += FindPath(node->right, num - node->val);

        return res;
    }
};
// @lc code=end
