/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 方法一：12ms
// hash map 统计次数，返回新构建的链表
// 时间复杂度：O(n) > - 空间复杂度：O(n)
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        unordered_map<int, int> record;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            record[curr->val]++;
            curr = curr->next;
        }

        ListNode dummy(-1);
        ListNode *dummy_ptr = &dummy;
        curr = head;
        while (curr != nullptr)
        {
            if (record[curr->val] != 1)
            {
               curr = curr->next;
            }
            else
            {
                ListNode *node = new ListNode(curr->val);
                dummy_ptr->next = node;
                dummy_ptr = dummy_ptr->next;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};


// 方法二：12ms
// 时间复杂度：O(n) > - 空间复杂度：O(1)
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode dummy(-1);
        dummy.next = head;

        ListNode *prev = &dummy;
        ListNode *curr = head;

        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->val == curr->next->val)
            {
                while (curr->next != nullptr && curr->val == curr->next->val)
                {
                    curr = curr->next;
                }
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end
