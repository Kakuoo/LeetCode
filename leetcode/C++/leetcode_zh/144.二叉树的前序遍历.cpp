/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include <stack>
#include <string>
#include <cassert>
using namespace std;

// // 模板代码！！！
// while (栈非空 || p 非空)
// {
//     if (p 非空)
//     {
//     }
//     else
//     {
//     }
// }

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Command
{
    string s;
    TreeNode *node;
    Command(string s, TreeNode *node) : s(s), node(node) {}
};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        stack<Command> st;
        st.push(Command("go_through", root));
        while (!st.empty())
        {
            Command tmp = st.top();
            st.pop();

            if (tmp.s == "print")
                res.push_back(tmp.node->val);
            else
            {
                assert(tmp.s == "go_through");
                if (tmp.node->right)
                    st.push(Command("go_through", tmp.node->right));
                if (tmp.node->left)
                    st.push(Command("go_through", tmp.node->left));
                st.push(Command("print", tmp.node));
            }
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();

            res.push_back(node->val);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return res;
    }
};
// @lc code=end
