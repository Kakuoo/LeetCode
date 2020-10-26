/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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

#include <set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

// 最巧妙的方法
// 栈向上增长，增长方式由高地址到低地址，上方意味着低地址
// 堆的地址从低到高，LeetCode的链表内存是顺序申请的，如果有环，head->next一定小于或等于head
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        while (head)
        {
            if (!less<ListNode *>()(head, head->next))
            {
                return head->next;
            }
            head = head->next;
        }
        return nullptr;
    }
};

// 方法一 快慢指针
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        bool has_cycle = false;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            if (slow == fast)
            {
                has_cycle = true;
                break;
            }
        }

        if (has_cycle)
        {
            ListNode *enter_node = head;
            while (slow != enter_node)
            {
                slow = slow->next;
                enter_node = enter_node->next;
            }
            return enter_node;
        }
        else
        {
            return nullptr;
        }
    }
};

// 方法二
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        set<ListNode *> node_set;
        while (head)
        {
            if (node_set.find(head) != node_set.end())
            {
                return head;
            }
            node_set.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

// 方法三  快慢指针
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = NULL;
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
            if (!fast)
            {
                return NULL;
            }
            fast = fast->next;
            if (fast == slow)
            {
                meet = fast;
                break;
            }
        }
        // if (meet == NULL)
        // {
        //     return NULL; // 无环
        // }
        while (head && meet) // 可证明从head头节点或从meet相遇节点到环的起始节点的距离相等
        {
            if (head == meet)
            {
                return head;
            }
            head = head->next;
            meet = meet->next;
        }
        return NULL;
    }
};

// @lc code=end
