#include <iostream>
#include <queue>
using namespace std;

/*
 *  设置队列Q
 *  将根节点push进入Q
 *  while(Q不空)
 * {
 *      取出队列头部节点Node
 *      对Node进行访问
 *      将Node的左、右孩子push进入队列
 * }
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 二叉树广度遍历、层次遍历
// 广度优先搜索二叉树 (按行顺序遍历二叉树)
void BFS_print(TreeNode *root) 
{
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        TreeNode *node = Q.front();
        Q.pop(); 
        if (node->left)
            Q.push(node->left);
        if (node->right)
            Q.push(node->right);
    }
}

// 深度遍历有前序、中序以及后序三种遍历方法
// 深度优先搜索二叉树  一般主要指前序遍历
void DFS_print_preorder(TreeNode *node, int layer)  
{
    if (!node)
        return;

    for (int i = 0; i < layer; i++)
    {
        printf("--------"); // 根据层数打印相应数量的 --------
    }
    DFS_print_preorder(node->left, layer + 1);
    DFS_print_preorder(node->right, layer + 1);
}

// 其中，二叉树的深度遍历中，前中后序遍历如下所示：
void traversal(TreeNode *node)
{
    if (!node)
    {
        return;
    }
    //此时访问node成为前序遍历
    traversal(node->left);
    //此时访问node成为中序遍历
    traversal(node->right);
    //此时访问node成为后序遍历
}
