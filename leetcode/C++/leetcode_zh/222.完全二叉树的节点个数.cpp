/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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

// tql
/**
完全二叉树的高度可以直接通过不断地访问左子树就可以获取
判断左右子树的高度: 
如果相等说明左子树是满二叉树, 然后进一步判断右子树的节点数(最后一层最后出现的节点必然在右子树中)
如果不等说明右子树是深度小于左子树的满二叉树, 然后进一步判断左子树的节点数(最后一层最后出现的节点必然在左子树中)
**/
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int ld = GetDepth(root->left);
        int rd = GetDepth(root->right);

        if (ld == rd)
            return (1 << ld) + countNodes(root->right);  // 1(根节点) + (1 << ld)-1(左完全左子树节点数) + 右子树节点数量
        else
            return (1 << rd) + countNodes(root->left);  // 1(根节点) + (1 << rd)-1(右完全右子树节点数) + 左子树节点数量
        }

private:
    int GetDepth(TreeNode *node)
    {
        int depth = 0;
        while (node != nullptr)
        {
            depth++;
            node = node->left;
        }
        return depth;
    }
};

// 递归
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// 广搜 Time Limited Exceed
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        int res = 0;
        if (root == nullptr)
            return res;

        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            TreeNode *node = Q.front();
            Q.pop();
            res++;

            if (node->left)
                Q.emplace(node->left);
            if (node->right)
                Q.emplace(node->right);
        }
        return res;
    }
};
// @lc code=end
