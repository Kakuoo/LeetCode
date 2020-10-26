/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
#include <stack>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1;
        ListNode *q = l2;
        stack<int> s1;
        stack<int> s2;
        while (p != nullptr)
        {
            s1.push(p->val);
            p = p->next;
        }
        while (q != nullptr)
        {
            s2.push(q->val);
            q = q->next;
        }

        ListNode head(NULL);
        ListNode *head_ptr = nullptr;
        int carry = 0;
        int p_val = 0;
        int q_val = 0;
        while (!s1.empty() || !s2.empty() || carry)
        {
            if (s1.empty())
            {
                p_val = 0;
            }
            else
            {
                p_val = s1.top();
                s1.pop();
            }

            if (s2.empty())
            {
                q_val = 0;
            }
            else
            {
                q_val = s2.top();
                s2.pop();
            }

            int sum_val = p_val + q_val + carry;
            carry = sum_val / 10;
            ListNode *node = new ListNode(sum_val % 10);
            node->next = head_ptr;
            head_ptr = node;
        }

        return head_ptr;
    }
};
// @lc code=end
