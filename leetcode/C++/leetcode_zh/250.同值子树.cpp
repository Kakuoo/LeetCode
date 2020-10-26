/**
 * Given a binary tree, count the number of uni-value subtrees.
 * A Uni-value subtree means all nodes of the subtree have the same value.
 * 给定一个二叉树，统计该二叉树数值相同的子树的个数
 * 同值子树是指该子树的所有节点都有拥有相同的数值 (说明度为0或1的节点，一定为同值子树)
 * 
 */
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 方法一
class Solution
{
public:
    int countUnivalSubtrees(TreeNode *root)
    {
        if (!root)
            return 0;
        is_uni(root);
        return res_;
    }

private:
    int res_ = 0;
    bool is_uni(TreeNode *node)
    {
        if (!node->left && !node->right)    // 无子树
        {
            ++res_;
            return true;
        }
        if (node->left)
        {
            bool flag =  is_uni(node->left) && node->val == node->left->val;
        }
        if (node->right)
        {
            bool flag = is_uni(node->right) && node->val == node->right->val;
        }
        if (flag)
            ++res_;
        return flag;
    }
};

// 方法二
class Solution
{
public:
    int countUnivalSubtrees(TreeNode *root)
    {
        if (!root)
            return 0;
        DFS(root, root->val, res_);
        return res_;
    }

private:
    int res_ = 0;
    bool DFS(TreeNode *node, int pre, int &res)
    {
        if (!node)
            return true;
        bool flag1 = DFS(node->left, node->val, res);
        bool flag2 = DFS(node->right, node->val, res);
        if (flag1 && flag2)
            res++;
        return (node->val == pre) && flag1 && flag2;
    }
};
