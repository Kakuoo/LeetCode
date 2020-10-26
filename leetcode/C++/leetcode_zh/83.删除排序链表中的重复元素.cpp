/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        int record = INT_MAX;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            if (curr->val == record)
            {
                // 删除该节点
                ListNode *next = curr->next;
                delete curr;
                prev->next = next;
                curr = next;
            }
            else
            {
                record = curr->val;
                prev = curr;
                curr = curr->next;
            }
            
        }
        return head;
    }
};
// @lc code=end
