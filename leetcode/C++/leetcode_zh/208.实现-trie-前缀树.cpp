/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (64.37%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    33.4K
 * Total Submissions: 50.1K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
#include <memory> // 包含unique_ptr<>
using namespace std;

// 方法一
class Trie
{
    Trie *child[26];
    bool is_word;

public:
    Trie()
    {
        is_word = false;
        for (int i = 0; i < 26; ++i)
        {
            child[i] = nullptr;
        }
    }
    ~Trie()
    {
        for (auto i : node_vec_)
        {
            delete i;
        }
        // for (int i = 0; i < node_vec_.size(); ++i)
        // {
        //     delete node_vec_[i];
        // }
    }

    void insert(string word)
    {
        Trie *ptr = this;
        for (char c : word)
        {
            if (!ptr->child[c - 'a'])
            {
                ptr->child[c - 'a'] = new Trie();
            }
            ptr = ptr->child[c - 'a'];
        }
        ptr->is_word = true;
    }

    bool search(string word)
    {
        Trie *ptr = this;
        for (char c : word)
        {
            if (!ptr->child[c - 'a'])
            {
                return false;
            }
            ptr = ptr->child[c - 'a'];
        }
        return ptr->is_word;
    }

    bool startsWith(string word)
    {
        Trie *ptr = this;
        for (char c : word)
        {
            if (!ptr->child[c - 'a'])
            {
                return false;
            }
            ptr = ptr->child[c - 'a'];
        }
        return true;
    }

private:
    Trie *new_word()
    {
        Trie *node = new Trie();
        node_vec_.push_back(node);
        return node;
    }
    vector<Trie *> node_vec_;
};

// 方法二
struct TrieNode
{
    unique_ptr<TrieNode> child[26];
    bool is_end;
    TrieNode() : is_end(false)
    {
        for (int i = 0; i < 26; ++i)
            child[i] = nullptr;
    }
};

class Trie
{
public:
    Trie() : root_(new TrieNode) {}

    void insert(string word)
    {
        TrieNode *ptr = root_.get();
        for (auto c : word)
        {
            if (ptr->child[c - 'a'] == nullptr)
            {
                ptr->child[c - 'a'].reset(new TrieNode());
            }
            ptr = ptr->child[c - 'a'].get();
        }
        ptr->is_end = true;
    }

    bool search(string word)
    {
        TrieNode *ptr = root_.get();
        for (auto c : word)
        {
            if (ptr->child[c - 'a'] == nullptr)
            {
                return false;
            }
            ptr = ptr->child[c - 'a'].get();
        }
        return ptr->is_end;
    }

    bool startsWith(string word)
    {
        TrieNode *ptr = root_.get();
        for (auto c : word)
        {
            if (ptr->child[c - 'a'] == nullptr)
            {
                return false;
            }
            ptr = ptr->child[c - 'a'].get();
        }
        return true;
    }

private:
    unique_ptr<TrieNode> root_;
};

// 方法三
#define TRIE_WORD_CHAR_NUM 26

struct TrieNode
{
    TrieNode *child[TRIE_WORD_CHAR_NUM];
    bool is_end;
    TrieNode() : is_end(false)
    {
        for (int i = 0; i < TRIE_WORD_CHAR_NUM; ++i)
        {
            child[i] = 0;
        }
    }
};

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie() {}
    ~Trie()
    {
        for (auto i : node_vec_)
        {
            delete i;
        }
        // for (int i = 0; i < Trie::node_vec_.size(); ++i)
        // {
        //     delete node_vec_[i];
        // }
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *ptr = &root_;
        for (int i = 0; i < word.length(); ++i)
        {
            int pos = word[i] - 'a';
            if (!ptr->child[pos])
            {
                ptr->child[pos] = Trie::new_word();
            }
            ptr = ptr->child[pos];
        }
        ptr->is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *ptr = &root_;
        for (int i = 0; i < word.length(); ++i)
        {
            int pos = word[i] - 'a';
            if (!ptr->child[pos])
            {
                return false;
            }
            ptr = ptr->child[pos];
        }
        return ptr->is_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *ptr = &root_;
        for (int i = 0; i < prefix.length(); ++i)
        {
            int pos = prefix[i] - 'a';
            if (!ptr->child[pos])
            {
                return false;
            }
            ptr = ptr->child[pos];
        }
        return true;
    }
    // 返回root_
    TrieNode *root()
    {
        return &root_;
    }

private:
    TrieNode *new_word()
    {
        TrieNode *node = new TrieNode;
        node_vec_.push_back(node);
        return node;
    }
    vector<TrieNode *> node_vec_;
    TrieNode root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
