/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

// 递归方法
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *curr = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return curr;
    }
};

// 迭代方法

// 方法一 就地逆置法
// prev指针初始化为空指针（链表尾），curr指针（head），next指针（head->next）
// return的时候，prev指针指向以前的链表的最后一个节点（新链表的头节点）
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// 方法二 头插法
// 临时头节点 dummy
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode dummy(0);
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next_bak = curr->next;
            curr->next = dummy.next;
            dummy.next = curr;
            curr = next_bak;
        }

        return dummy.next;
    }
};

// @lc code=end
