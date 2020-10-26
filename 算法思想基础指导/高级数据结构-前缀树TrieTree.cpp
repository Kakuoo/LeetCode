/**
 * Trie树（前缀树、字典树）
 * 
 * 适合稠密的字典存储，不适合稀疏字典的存储
 * 应用于字典查找中 O(M)，其中暴力搜索复杂度为O(M*N)
 * 例如：
 * 搜索框输入搜索文字，以搜索词开头的相关搜索
 * 汉语拼音输入法，联想输出功能
 * 代码补全
 * 
 * 重要性质：
 * 每个节点至少包含两个基本属性
 * - children：数组或集合，罗列出每个分支当中包含的所有字符
 * - isEnd：布尔值，表示该节点是否为某个字符串的结尾
 * 
 * 
 */

#include <vector>
#include <string>
using namespace std;

#define TRIE_MAX_CHAR_NUM 26 // 假设只考虑小写字母（暂不考虑大写字母或是ASCII码字符）

struct TrieNode
{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode() : is_end(false)
    {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i)
        {
            child[i] = nullptr;
        }
    }
};

// 前序遍历
void preorder_trie(TrieNode *node, int layer)
{
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i)
    {
        if (node->child[i])
        {
            for (int j = 0; j < layer; ++j)
            {
                printf("---");
            }
            printf("%c", i + 'a');
            if (node->child[i]->is_end)
            {
                printf("(end)");
            }
            printf("\n");
            preorder_trie(node->child[i], layer + 1);
        }
    }
}

// 深度优先遍历，Trie树获取全部单词
void get_all_word_from_trie(TrieNode *node, string &word,
                            vector<vector<string>> &word_list)
{
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i)
    {
        if (node->child[i])
        {
            word.push_back(i + 'a');
            if (node->child[i]->is_end)
            {
                word_list.push_back(word);
            }
            get_all_word_from_trie(node->child[i], word, word_list);
            word.erase(word.length() - 1, 1); // 相当于弹出栈顶字符的操作，删除最后一个字符
        }
    }
}

// 构建Trie树
// 字符串：abc, abcd, abd, b, bcd, efg
int main()
{
    TrieNode root;
    TrieNode n1;
    TrieNode n2;
    TrieNode n3;
    root.child['a' - 'a'] = &n1;
    root.child['b' - 'a'] = &n2;
    root.child['e' - 'a'] = &n3;
    n2.is_end = true;

    TrieNode n4;
    TrieNode n5;
    TrieNode n6;
    n1.child['b' - 'a'] = &n4;
    n2.child['c' - 'a'] = &n5;
    n3.child['f' - 'a'] = &n6;

    TrieNode n7;
    TrieNode n8;
    TrieNode n9;
    TrieNode n10;
    n4.child['c' - 'a'] = &n7;
    n4.child['d' - 'a'] = &n8;
    n5.child['d' - 'a'] = &n9;
    n6.child['g' - 'a'] = &n10;
    n7.is_end = true;
    n8.is_end = true;
    n9.is_end = true;
    n10.is_end = true;

    TrieNode n11;
    n7.child['d' - 'a'] = &n11;
    n11.is_end = true;

    preorder_trie(&root, 0);
    return 0;
}

/*
 * Trie树的整体功能实现
 * 
 */

class TrieTree
{
public:
    TrieTree() {}
    ~TrieTree()
    {
        for (int i = 0; i < node_vec_.size(); ++i)
        {
            delete node_vec_[i];
        }
    }
    // 将word插入至TrieTree中
    void Insert(const char *word);
    // 搜索TrieTree中是否存在word
    bool Search(const char *word);
    // 确认TrieTree中是否有前缀为prefix的单词
    bool StartsWith(const char *prefix);
    // 返回根节点root
    TrieNode *root()
    {
        return &root_;
    }

private:
    TrieNode *new_node() // 便于析构new的堆区内容
    {
        TrieNode *node = new TrieNode();
        node_vec_.push_back(node);
        return node;
    }
    vector<TrieNode *> node_vec_;
    TrieNode root_;
};

void TrieTree::Insert(const char *word)
{
    /*
     * 使用ptr指针指向root：
     * 逐个遍历待插入的字符串中的各个字符：
     *      计算下标pos = 正在遍历字符 - 'a'
     *      如果ptr指向的节点的第pos个孩子为假：
     *          创建该节点的第pos个孩子
     *      prt指向该节点的第pos个孩子
     * 标记ptr指向的节点的is_end为true
     * 
     */

    TrieNode *ptr = &root_;
    while (*word)
    {
        int pos = *word - 'a';
        if (!ptr->child[pos])
        {
            ptr->child[pos] = TrieTree::new_node();
        }
        ptr = ptr->child[pos];
        word++;
    }
    ptr->is_end = true;
}

bool TrieTree::Search(const char *word)
{
    /*
     * 使用ptr指针指向root
     * 逐个遍历待搜索的字符串中的各个字符：
     *      计算下标pos = 正在遍历的字符 - 'a'
     *      如果ptr指向的节点的第pos个孩子为假：
     *          返回假
     *      ptr指向该节点的第pos个孩子
     * 返回ptr指向的节点的is_end
     * 
     */

    TrieNode *ptr = &root_;
    while(*word)
    {
        int pos = *word - 'a';
        if (!ptr->child[pos])
        {
            return false;
        }
        ptr = ptr->child[pos];
        word++;
    }
    return ptr->is_end;
}

bool TrieTree::StartsWith(const char *prefix)
{
    TrieNode *ptr = &root_;
    while (*prefix)
    {
        int pos = *prefix - 'a';
        if (!ptr->child[pos])
        {
            return false;
        }
        ptr = ptr->child[pos];
        prefix++;   
    }
    return true;
}