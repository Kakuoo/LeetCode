/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 *
 * https://leetcode-cn.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (39.12%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    13.2K
 * Total Submissions: 32.7K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * 给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
 * 
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
 * 
 * 示例:
 * 
 * 输入: 
 * words = ["oath","pea","eat","rain"] and board =
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * 
 * 输出: ["eat","oath"]
 * 
 * 说明:
 * 你可以假设所有输入都由小写字母 a-z 组成。
 * 
 * 提示:
 * 
 * 
 * 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
 * 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？
 * 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
#include <memory>
#include <iostream>
using namespace std;

/**
 * 使用前缀树 TrieTree 优化回溯算法
 * 如果单前单词不存在与所有单词的前缀中，则可以立即停止回溯
 */


// 方法一
#define TRIE_CHAR_NUM 26
class TrieNode
{
public:
    string word = "";
    vector<TrieNode *> child;
    TrieNode() : child(TRIE_CHAR_NUM, nullptr) {}
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        ios::sync_with_stdio(false);
        if (board.empty() || words.empty())
            return res;
        int rows = board.size(), cols = board[0].size();

        // 构建字典树--insert操作
        TrieNode root;
        for (string word : words)
        {
            TrieNode *curr = &root;
            for (int i = 0; i < word.size(); ++i)
            {
                int pos = word[i] - 'a';
                if (curr->child[pos] == nullptr)
                    curr->child[pos] = new TrieNode();
                curr = curr->child[pos];
            }
            curr->word = word;
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                dfs_mine(board, &root, i, j);
            }
        }
        return res;
    }

private:
    vector<string> res;
    static constexpr int dx[] = {-1, 1, 0, 0};
    static constexpr int dy[] = {0, 0, -1, 1};

    // 方法一：先进入下一个状态再判断合法性
    void dfs_mine(vector<vector<char>> &board, TrieNode *node, int x, int y)
    {
        if (x < 0 || x >= board.size() ||
            y < 0 || y >= board[0].size())
            return;
        char c = board[x][y];
        if (c == '#' || node->child[c - 'a'] == nullptr)
            return;
        node = node->child[c - 'a'];
        if (node->word != "")
        {
            res.push_back(node->word);
            node->word = "";
        }
        board[x][y] = '#'; // 用#表示已访问该位置，而不需要新指定一个vector<vector<int>> mark
        for (int i = 0; i < 4; ++i)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            dfs_mine(board, node, new_x, new_y);
        }
        board[x][y] = c;
    }

    // 方法二：先判断下一个状态的合法性再进入
    void dfs_other(vector<vector<char>>& board, TrieNode* node, int x, int y){
        char c = board[x][y];
        //递归边界
        if(c=='#' || node->child[c-'a']==0) return;
        node = node->child[c-'a'];
        if(node->word!=""){
            res.push_back(node->word);
            node->word = "";
        }
        board[x][y] = '#';
        if(x>0) dfs_other(board, node, x-1, y);
        if(y>0) dfs_other(board, node, x, y-1);
        if(x+1<board.size()) dfs_other(board, node, x+1, y);
        if(y+1<board[0].size()) dfs_other(board, node, x, y+1);
        board[x][y] = c;
    }  
};

// 方法二 还未调试正确，程序存在问题
// #define TRIE_MAX_CHAR_NUM 26

// struct TrieNode
// {
//     string word = "";
//     TrieNode *child[TRIE_MAX_CHAR_NUM];
//     bool is_end;
//     TrieNode() : is_end(false)
//     {
//         for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i)
//         {
//             child[i] = nullptr;
//         }
//     }
// };

// class TrieTree
// {
// public:
//     TrieTree() {}
//     ~TrieTree()
//     {
//         // 释放专门用来堆区new出来的空间
//         for (auto e : node_vec_)
//         {
//             delete e;
//         }
//     }
//     void insert(const char *word);
//     bool search(const char *word);
//     bool start_with(const char *prefix);
//     TrieNode *root() { return &root_; }

// private:
//     TrieNode *new_node_()
//     {
//         TrieNode *node = new TrieNode();
//         node_vec_.push_back(node);
//         return node;
//     }
//     vector<TrieNode *> node_vec_;
//     TrieNode root_;
// };

// void TrieTree::insert(const char *word)
// {
//     TrieNode *ptr = &root_;
//     while (*word)
//     {
//         int pos = *word - 'a';
//         if (ptr->child[pos] == nullptr)
//             ptr->child[pos] = TrieTree::new_node_();
//         ptr = ptr->child[pos];
//         word++;
//     }
//     ptr->word = word;
//     ptr->is_end = true;
// }

// bool TrieTree::search(const char *word)
// {
//     TrieNode *ptr = &root_;
//     while (*word)
//     {
//         int pos = *word - 'a';
//         if (ptr->child[pos] == nullptr)
//             return false;
//         ptr = ptr->child[pos];
//         word++;
//     }
//     return ptr->is_end;
// }

// bool TrieTree::start_with(const char *prefix)
// {
//     TrieNode *ptr = &root_;
//     while (*prefix)
//     {
//         int pos = *prefix - 'a';
//         if (ptr->child[pos] == nullptr)
//         {
//             return false;
//         }
//         ptr = ptr->child[pos];
//         prefix++;
//     }
//     return true;
// }

// class Solution
// {
// public:
//     vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
//     {
//         vector<string> res;
//         for (auto word : words)
//         {
//             trie_tree.insert(word.c_str());
//         }
//         for (auto word : words)
//         {
//             for (int i = 0; i < board.size(); ++i)
//             {
//                 for (int j = 0; j < board[0].size(); ++j)
//                 {
//                     if (dfs(board, trie_tree.root(), i, j))
//                         res.push_back(word);
//                 }
//             }
//         }
//         return res;
//     }

// private:
//     bool dfs(vector<vector<char>> &board, TrieNode *node, int x, int y)
//     {
//         char c = board[x][y];
//         // 递归边界
//         if (!trie_tree.start_with(node->child[c - 'a']))
//             return false;
//         node = node->child[c - 'a'];
//         if (node->word != "")
//             return true;
//         if (x < 0 || x >= board.size() ||
//             y < 0 || y >= board[0].size())
//             return false;
//         for (int i = 0; i < 4; ++i)
//         {
//             int new_x = x + dx[i];
//             int new_y = y + dy[i];
//             if (dfs(board, node, new_x, new_y))
//                 return true;
//         }
//         return false;
//     }
//     static constexpr  int dx[] = {-1, 1, 0, 0};
//     static constexpr  int dy[] = {0, 0, -1, 1};
//     TrieTree trie_tree;
// };

/**
 * 参考leetcode 79题
 * 程序AC，但是Time limit Exceed
 *
 */
// class Solution
// {
// public:
//     vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
//     {
//         vector<string> res;
//         for (auto word : words)
//         {
//             if (exist(board, word))
//                 res.push_back(word);
//         }
//         return res;
//     }

// private:
//     bool exist(vector<vector<char>> &board, string &word)
//     {
//         if (board.empty() || word.empty())
//             return false;
//         int row = board.size(), col = board[0].size();
//         vector<vector<int>> mark(row, vector<int>(col, 0));
//         for (int i = 0; i < row; ++i)
//         {
//             for (int j = 0; j < col; ++j)
//             {
//                 if (dfs(board, word, 0, i, j, mark))
//                     return true;
//             }
//         }
//         return false;
//     }

//     bool dfs(vector<vector<char>> &board, string &word,
//              int word_idx, int x, int y, vector<vector<int>> &mark)
//     {
//         if (word_idx == word.size())
//             return true;
//         // 判断范围
//         if (x < 0 || x >= board.size() ||
//             y < 0 || y >= board[0].size() ||
//             board[x][y] != word[word_idx])
//             return false;
//         // 遍历board
//         if (mark[x][y] == 0)
//         {
//             mark[x][y] = 1;
//             static const int dx[] = {-1, 1, 0, 0};
//             static const int dy[] = {0, 0, -1, 1};
//             for (int i = 0; i < 4; ++i)
//             {
//                 int new_x = x + dx[i];
//                 int new_y = y + dy[i];
//                 if (dfs(board, word, word_idx + 1, new_x, new_y, mark))
//                 {
//                     return true;
//                 }
//             }
//             // 如果递归出现false的终点，则清除mark的标记，并回溯
//             mark[x][y] = 0;
//         }
//         return false;
//     }
// };
// @lc code=end
