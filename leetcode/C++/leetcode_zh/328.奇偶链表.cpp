/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode odd_head(-1);
        ListNode even_head(-1);
        ListNode *odd_curr = &odd_head;
        ListNode *even_curr = &even_head;
        
        int count = 1;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            if (count % 2== 1)
            {
                odd_curr->next = curr;
                odd_curr = odd_curr->next;
            }
            else
            {
                even_curr->next = curr;
                even_curr = even_curr->next;
            }
            count++;
            curr = curr->next;
        }
        odd_curr->next = even_head.next;
        even_curr->next = nullptr;
        return odd_head.next;
    }
};
// @lc code=end
