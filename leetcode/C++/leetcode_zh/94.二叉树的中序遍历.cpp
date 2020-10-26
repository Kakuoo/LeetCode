/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode *root)
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

                if (tmp.node->right)
                    st.push(Command("go_through", tmp.node->right));
                st.push(Command("print", tmp.node));
                if (tmp.node->left)
                    st.push(Command("go_through", tmp.node->left));
            }
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        stack<TreeNode *> st;
        TreeNode *node = root;
        while (!st.empty() || node)
        {
            while (node)
            {
                st.push(node);
                node = node->left;
            }

            node = st.top();
            st.pop();
            res.push_back(node->val);

            node = node->right;
        }
        return res;
    }
};
// @lc code=end
