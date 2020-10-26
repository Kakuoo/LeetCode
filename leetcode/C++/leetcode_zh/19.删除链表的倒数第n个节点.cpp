/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        
        if (fast == nullptr)
            return head->next;

        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *del_node = slow->next;
        slow->next = del_node->next;
        delete del_node;

        return head;
    }
};

// 正确但是逻辑混乱
// class Solution
// {
// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         if (head == nullptr)
//             return head;

//         ListNode *curr = head;
//         int len = 1;
//         while (curr->next != nullptr)
//         {
//             len++;
//             curr = curr->next;
//         }

//         if (len == 0)
//             return nullptr;
//         if (len == n)
//             return head->next;

//         curr = head;
//         int start = 0;
//         int end = len - n - 1;
//         while (start < end)
//         {
//             start++;
//             curr = curr->next;
//         }

//         ListNode *del_node = curr->next;
//         curr->next = del_node->next;
//         delete del_node;
//         del_node = nullptr;

//         return head;
//     }
// };
// @lc code=end
