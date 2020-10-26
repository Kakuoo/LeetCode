/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = nullptr;  // 构建一个prev指针用于确定插入位置

        while (head && head->next)
        {
            if (head->val < head->next->val)
            {
                head = head->next;
                continue;
            }
           
            // 确定插入位置
            prev = &dummy;
            while (prev->next->val < head->next->val)
                prev = prev->next;

            ListNode *next_bak = head->next;
            head->next = next_bak->next;
            next_bak->next = prev->next;
            prev->next = next_bak;
        }
        return dummy.next;
    }
};
// @lc code=end
