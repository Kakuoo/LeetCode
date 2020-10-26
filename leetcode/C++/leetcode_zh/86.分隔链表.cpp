/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode(int x) : val(x), next(NULL){};
};

// 快速排序的子过程
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode less_head(-1);
        ListNode more_head(-1);
        ListNode *less_curr = &less_head;
        ListNode *more_curr = &more_head;

        ListNode *curr = head;
        while (curr != nullptr)
        {
            if (curr->val < x)
            {
                less_curr->next = curr;
                less_curr = less_curr->next;
            }
            else
            {
                more_curr->next = curr;
                more_curr = more_curr->next;
            }
            curr = curr->next;
        }
        less_curr->next = more_head.next;
        more_curr->next = nullptr;
        return less_head.next;
    }
};

// @lc code=end
