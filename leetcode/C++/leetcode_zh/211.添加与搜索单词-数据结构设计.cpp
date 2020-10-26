/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 *
 * https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (42.63%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 22.4K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 设计一个支持以下两种操作的数据结构：
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。
 * 
 * 示例:
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * 说明:
 * 
 * 你可以假设所有单词都是由小写字母 a-z 组成的。
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

#define TRIE_CHAR_NUM 26

struct TrieNode
{
    TrieNode *child[TRIE_CHAR_NUM];
    bool is_end;
    TrieNode() : is_end(false)
    {
        for (int i = 0; i < TRIE_CHAR_NUM; ++i)
        {
            child[i] = nullptr;
        }
    }
};

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary() {}
    ~WordDictionary()
    {
        for (auto i : node_vec_)
        {
            delete i;
        }
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *ptr = &root_;
        for (auto c : word)
        {
            if (ptr->child[c - 'a'] == nullptr)
            {
                ptr->child[c - 'a'] = new_word();
            }
            ptr = ptr->child[c - 'a'];
        }
        ptr->is_end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return search_trie(root(), word.c_str());
    }
    TrieNode *root()
    {
        return &root_;
    }

private:
    bool search_trie(TrieNode *node, const char *word)
    {
        if (*word == '\0')
        {
            return node->is_end;
        }
        if (*word == '.')
        {
            for (int i = 0; i < TRIE_CHAR_NUM; ++i)
            {
                if (node->child[i] &&
                    search_trie(node->child[i], word + 1))
                {
                    return true;
                }
            }
        }
        else
        {
            int pos = *word - 'a';
            if (node->child[pos] &&
                search_trie(node->child[pos], word + 1))
            {
                return true;
            }
        }
        return false;
    }

    TrieNode *new_word()
    {
        TrieNode *node = new TrieNode();
        node_vec_.push_back(node);
        return node;
    }
    vector<TrieNode *> node_vec_;
    TrieNode root_;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
