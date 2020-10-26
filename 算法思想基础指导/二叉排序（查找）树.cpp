#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 二叉查找树 插入节点
 * 
 * 将某节点（insert_node），插入至以node为根的二叉树中：
 * 如果insert_node节点值小于当前node的节点值：
 *     如果node有左子树，则递归将该节点插入至左子树为根二叉排序树中，否则，将node->left赋值为该节点的地址
 * 否则（大于等于的情况）：
 *      如果node有右子树，则递归将该节点插入至右子树为根二叉排序树中，否则，将node->right赋值为该节点的地址
 * 
 */

void BFS_insert(TreeNode *node, TreeNode *insertNode)
{
    if (insertNode->val < node->val)
    {
        if (node->left)
        {
            BFS_insert(node->left, insertNode);
        }
        else
        {
            node->left = insertNode; // 当左子树为空时，将node的左指针与待插入节点相连
        }
    }
    else
    {
        if (node->right)
        {
            BFS_insert(node->right, insertNode); // 当右子树非空时，将node的右指针与待插入节点相连
        }
        else
        {
            node->right = insertNode;
        }
    }
}

/*
 * 二叉查找树 查找节点
 * 
 * 查找某数值value是否在二叉查找树中出现：
 * 如果value等于当前查看node的节点值：返回真
 * 如果value节点值小于当前node节点值：
 *      如果当前节点有左子树，继续在左子树中查找该值；否则返回假
 * 否则（value节点值大于当前节点值）
 *      如果当前节点有右子树，继续在右子树中查找该值；否则返回假
 * 
 */

bool BFS_search(TreeNode *node, int value)
{
    if (value == node->val)
    {
        return true;
    }
    
    if (value < node->val)
    {
        if (node->left)
        {
            return BFS_search(node->left, value);
        }
        else
        {
            return false;
        }
    }
    else if (value > node->val)
    {
        if (node->right)
        {
            return BFS_search(node->right, value);
        }
        else
        {
            return false;
        }
    }
}
