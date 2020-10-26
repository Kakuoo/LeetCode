/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include <string>
#include <stack>
#include <cassert>
using namespace std;

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
    vector<int> postorderTraversal(TreeNode *root)
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
            {
                res.push_back(tmp.node->val);
            }
            else
            {
                assert(tmp.s == "go_through");

                st.push(Command("print", tmp.node));
                if (tmp.node->right)
                    st.push(Command("go_through", tmp.node->right));
                if (tmp.node->left)
                    st.push(Command("go_through", tmp.node->left));          
            }
        }
        return res;
    }
};


// 自杀式迭代，遍历完树没了
// 遍历破坏了树的结构
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node->left == nullptr && node->right == nullptr)
            {
                res.push_back(node->val);
                st.pop();
            }
            if (node->right != nullptr)
            {
                st.push(node->right);
                node->right = nullptr;
            }
            if (node->left != nullptr)
            {
                st.push(node->left);
                node->left = nullptr;
            }
        }
        return res;
    }
};
// @lc code=end
