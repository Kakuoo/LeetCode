/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 考虑对齐，进位
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode head(-1);
        ListNode *head_ptr = &head;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int l1_val = l1 != nullptr ? l1->val : 0;
            int l2_val = l2 != nullptr ? l2->val : 0;
            int sum_val = l1_val + l2_val + carry;
            carry = sum_val / 10;

            ListNode *node = new ListNode(sum_val % 10);
            head_ptr->next = node;
            head_ptr = head_ptr->next;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        return head.next;
    }
};


// @lc code=end
