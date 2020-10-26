/**
 * 哈希表
 * 
 * 哈希表，平均时间复杂度：插入，查找，删除操作均为 O(1)
 * 二分搜素树（平衡树），平均时间复杂度：插入，查找，删除操作均为 O(nlogn)
 * 
 * 但是哈希表有一个缺点：
 * 失去了数据的顺序性
 * 
 * 二分搜索树可以实现如下操作：
 * 1.数据集中的最大最小值
 * 2.某个元素的前驱和后继
 * 3.某个元素的floor和ceil
 * 4.某个元素的排位rank
 * 5.选择某个排位的元素select
 * 
 * C++中map和set的底层实现为平衡二叉树
 * unordered_map和unordered_set的底层实现为哈希表
 * 
 */ 

#include <iostream> 

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// table_len 取为质数，冲突会比其他数字少
int hash_func(int key, int table_len)
{
    return key % table_len; // 整数哈希函数，直接取余
}

void Insert(ListNode *hash_table[], ListNode *node, int tabel_len)
{
    int hash_key = hash_func(node->val, tabel_len);
    node->next = hash_table[hash_key];    // 使用头插法插入节点
    hash_table[hash_key] = node;
}

bool Search(ListNode *hash_table[], int value, int tabel_len)
{
    int hash_key = hash_func(value, tabel_len);
    ListNode *head = hash_table[hash_key];
    while (head)
    {
        if (head->val == value)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}