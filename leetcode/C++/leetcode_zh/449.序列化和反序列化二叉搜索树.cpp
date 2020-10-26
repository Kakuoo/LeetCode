/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (50.70%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    4.2K
 * Total Submissions: 8.3K
 * Testcase Example:  '[2,1,3]'
 *
 * 序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
 * 
 * 设计一个算法来序列化和反序列化二叉搜索树。 对序列化/反序列化算法的工作方式没有限制。
 * 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
 * 
 * 编码的字符串应尽可能紧凑。
 * 
 * 注意：不要使用类成员/全局/静态变量来存储状态。 你的序列化和反序列化算法应该是无状态的。
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
#include <string>
#include <vector>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };


// 此方法未通过，存在问题！！！
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string data;
        BFS_preorder(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
        {
            return NULL;
        }
        vector<TreeNode *> nodeVec;
        int val = 0;
        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] == '#')
            {
                nodeVec.push_back(new TreeNode(val));
                val = 0;
            }
            else
            {
                val = val * 10 + data[i] - '0';
            }
        }
        for (int i = 1; i < nodeVec.size(); i++)
        {
            BFS_insert(nodeVec[0], nodeVec[i]);
        }
        return nodeVec[0];
    }

private:
    void int_to_string(int val, string str_val)
    {
        string tmp;
        while (val)
        {
            // tmp += (string)(val % 10);
            tmp += val % 10 + '0';
            val = val / 10;
        }
        for (int i = tmp.length() - 1; i >= 0; i--)
        {
            str_val += tmp[i]; // 逆序将字符串添加到str_val中
        }
        str_val += "#"; // 转换后的数字后面添加#特殊符号以区分
    }

    void BFS_preorder(TreeNode *node, string &data)
    {
        if (!node)
        {
            return;
        }
        string str_val;
        int_to_string(node->val, str_val);
        data += str_val;
        BFS_preorder(node->left, data);
        BFS_preorder(node->right, data);
    }

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
                node->left = insertNode;
            }
        }
        else
        {
            if (node->right)
            {
                BFS_insert(node->right, insertNode);
            }
            else
            {
                node->right = insertNode;
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
