/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (67.39%)
 * Likes:    296
 * Dislikes: 0
 * Total Accepted:    32.7K
 * Total Submissions: 48K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// 思路一：通过vector存储并连接成单链表
// class Solution
// {
// public:
//     void flatten(TreeNode *root)
//     {
//         vector<TreeNode *> node_vec;
//         preorder(root, node_vec);
//         // for (int i = 0; i < node_vec.size(); i++)
//         // {
//         //     if (i == 0)
//         //     {
//         //         node_vec[i]== root;continue;
//         //     }
//         //     node_vec[i-1]->left = NULL;
//         //     node_vec[i-1]->right = node_vec[i];
//         // }
//          for (int i = 1; i < node_vec.size(); i++)
//         {
//             node_vec[i-1]->left = NULL;
//             node_vec[i-1]->right = node_vec[i];
//         }
//     }

// private:
//     void preorder(TreeNode *node, vector<TreeNode *> &node_vec)
//     {
//         if (!node)
//         {
//             return;
//         }
//         node_vec.push_back(node);
//         preorder(node->left, node_vec);
//         preorder(node->right, node_vec);
//     }
// };

// 思路二：in-place就地转换
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *last = nullptr;   // 当前子树先序遍历的最后一个节点，传引用会传出
        preorder(root, last);
    }

private:
    void preorder(TreeNode *node, TreeNode *&last)
    {
        if (!node)
        {
            return;
        }
        if (!node->left && !node->right)
        {   
            last = node;
            return;
        }
        TreeNode *left = node->left;    // 备份左右指针
        TreeNode *right = node->right;
        TreeNode *left_last = nullptr;  // 左右子树最后一个节点
        TreeNode *right_last = nullptr;
        if(left)
        {
            preorder(left, left_last);
            node->left = nullptr;
            node->right = left;
            last = left_last;   // 将该节点的last保存为左子树的last
        }
        if (right)
        {
            preorder(right, right_last);
            if (left_last)  // 若当前深度的node发现存在左子树的节点是最后一个节点
            {
                left_last->right = right;
            }
            last = right_last;
        }

    }
};
// @lc code=end
