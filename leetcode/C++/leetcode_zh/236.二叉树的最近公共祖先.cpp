/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (59.67%)
 * Likes:    422
 * Dislikes: 0
 * Total Accepted:    54.1K
 * Total Submissions: 89K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出: 3
 * 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出: 5
 * 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉树中。
 * 
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

#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path;
        vector<TreeNode *> node_p_path;
        vector<TreeNode *> node_q_path;
        TreeNode *result = 0;
        int finish = 0;
        preorder(root, p, path, node_p_path, finish);
        path.clear(); // 清空状态
        finish = 0;   // 清空状态
        preorder(root, q, path, node_q_path, finish);

        int path_len = 0;
        path_len = min(node_p_path.size(), node_q_path.size()); 
        // path_len = (node_p_path.size() < node_q_path.size()) ? node_p_path.size() : node_q_path.size();
        // if (node_p_path.size() < node_q_path.size())
        // {
        //     path_len = node_p_path.size();
        // }
        // else
        // {
        //     path_len = node_q_path.size();
        // }

        for (int i = 0; i < path_len; i++)
        {
            if (node_p_path[i] == node_q_path[i])
            {
                result = node_p_path[i];
            }
        }
        return result;
    }

private:
    void preorder(TreeNode *node, TreeNode *search,
                  vector<TreeNode *> &path, vector<TreeNode *> &result,
                  int &finish) // 记录是否找到节点search的变量，   未找到0，找到1
    {
        if (!node || finish == 1)
        {
            return;
        }
        path.push_back(node);
        if (node == search)
        {
            finish = 1;
            result = path;
        }
        preorder(node->left, search, path, result, finish);
        preorder(node->right, search, path, result, finish);
        path.pop_back();
    }
};
// @lc code=end
