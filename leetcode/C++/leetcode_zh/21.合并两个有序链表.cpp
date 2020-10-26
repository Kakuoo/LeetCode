/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *ptr = &dummy;

        ListNode *p = l1;
        ListNode *q = l2;
        while (p != nullptr && q != nullptr)
        {
            if (p->val <= q->val)
            {
                ptr->next = p;
                p = p->next;
            }
            else
            {
                ptr->next = q;
                q = q->next;
            }
            ptr = ptr->next;
        }

        if (p != nullptr)
            ptr->next = p;
        if (q != nullptr)
            ptr->next = q;

        return dummy.next;
    }
};
// @lc code=end
