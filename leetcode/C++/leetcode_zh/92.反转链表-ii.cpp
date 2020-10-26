/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 思想：curr始终在主链上移动，并且new_prev是初始化为空指针的逆置后的链表头，next用于备份curr>next
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
         // 最终转化的链表头节点，非特殊情况即为head（特殊情况：从第一个节点开始逆置）
        ListNode *result = head; 
         
        int change_len = n - m + 1;
        ListNode *prev = nullptr;  // 就地逆置法的临时变量
        ListNode *curr = head;

        // 链表前移m个节点，用于寻找并存储curr指针前一个位置prev
        while (curr != nullptr && --m)
        {
            prev = curr;
            curr = curr->next;
        }

        // 逆置之后的n-m+1个节点
        ListNode *new_prev = nullptr;  // 就地逆置法的临时变量
        ListNode *modify_tail = curr;  // 此时curr为待逆置的链表段的头指针，亦是逆置后链表段的尾指针
        while (curr != nullptr && change_len--)
        {
            ListNode *next = curr->next;

            curr->next = new_prev;
            new_prev = curr;
            curr = next;
        }
        modify_tail->next = curr;  // 将逆置后的链表尾与原始的链表尾进行链接

        if (prev)  // 如果prev不为空的情况下，说明m>1，即不是从第一个节点开始逆置
        {
            prev->next = new_prev;  // 将原始链表尾与逆置的链表头进行链接
        }
        else
        {
            result = new_prev;
        }
        return result;
    }
};
// @lc code=end
