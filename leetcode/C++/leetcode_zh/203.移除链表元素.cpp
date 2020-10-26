/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {

        // // 方法一：
        // ListNode *dummy_head = new ListNode(0);
        // dummy_head->next = head;
        // ListNode *curr = dummy_head;

        // 方法二：
        ListNode dummy(-1);
        ListNode *curr = &dummy;
        curr->next = head;

        while (curr->next != nullptr)
        {
            if (curr->next->val == val)
            {
                ListNode *del_node = curr->next;
                curr->next = del_node->next;
                delete del_node;
            }
            else
            {
                curr = curr->next;
            }
        }

        // // 方法一：
        // ListNode *ret_node = dummy_head->next;
        // delete dummy_head;
        // return ret_node;

        // 方法二：
        return dummy.next;
    }
};

// // 单独处理头结点，考虑复杂
// class Solution
// {
// public:
//     ListNode *removeElements(ListNode *head, int val)
//     {
//         // if (head == nullptr)
//         //     return nullptr;

//         while (head != nullptr && head->val == val)
//         {
//             ListNode *del_node = head;
//             head = del_node->next;
//             delete del_node;
//         }

//         if (head == nullptr)
//             return nullptr;

//         ListNode *curr = head;
//         while (curr->next != nullptr)
//         {
//             if (curr->next->val == val)
//             {
//                 // 删除cur->next
//                 ListNode *del_node = curr->next;
//                 curr->next = del_node->next;
//                 delete del_node;
//             }
//             else
//             {
//                 curr = curr->next;
//             }
//         }
//         return head;
//     }
// };
// @lc code=end
