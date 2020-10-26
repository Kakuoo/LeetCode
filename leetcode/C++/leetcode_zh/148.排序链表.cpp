/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }

private:
    ListNode *mergeSort(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
            return node;
        
    }

    ListNode *mergeLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }
};

// class Solution
// {
// public:
//     ListNode *sortList(ListNode *head)
//     {
//         ListNode dummy(0);
//         dummy.next = head;

//         // 统计链表长度
//         ListNode *p = &dummy;
//         int len = 0;
//         while (p)
//         {
//             ++len;
//             p = p->next;
//         }

//         // 自底向上的归并方法
//         for (int step = 1; step < len; step <<= 1)
//         {
//             ListNode *curr = dummy.next;
//             ListNode *tail = &dummy;

//             while (curr)
//             {
//                 // left->@->@->@->@->@->@->null
//                 ListNode *left = curr;

//                 // left->@->@->null   right->@->@->@->@->null
//                 ListNode *right = cut(left, step); // 将 current 切掉前 step 个头切下来

//                 // left->@->@->null   right->@->@->null   curr->@->@->null
//                 curr = cut(right, step); // 将 right 切掉前 step 个头切下来

//                 tail->next = merge(left, right);
//                 while (tail->next)
//                 {
//                     tail = tail->next; // 保持 tail 为尾部
//                 }
//             }
//         }
//         return dummy.next;
//     }

// private:
//     ListNode *cut(ListNode *node, int n)
//     {
//         ListNode *p = node;
//         while (--n && p)
//         {
//             p = p->next;
//         }

//         if (!p)
//             return nullptr;

//         // 断链
//         ListNode *next_bak = p->next;
//         p->next = nullptr;
//         return next_bak;
//     }

//     ListNode *merge(ListNode *l1, ListNode *l2)
//     {
//         ListNode dummy(0);
//         ListNode *curr = &dummy;
//         while (l1 && l2)
//         {
//             if (l1->val < l2->val)
//             {
//                 curr->next = l1;
//                 l1 = l1->next;
//             }
//             else
//             {
//                 curr->next = l2;
//                 l2 = l2->next;
//             }
//             curr = curr->next;
//         }

//         curr->next = l1 ? l1 : l2;

//         return dummy.next;
//     }
// };
// // @lc code=end
