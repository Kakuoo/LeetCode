/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] ç›¸äº¤é“¾è¡¨
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

// 方法一 使用set时间复杂度O(nlogn)
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        set<ListNode *> node_set;
        while (headA)
        {
            node_set.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (node_set.find(headB) != node_set.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};

// 方法二 使用O(n)
class Solution
{
public:
    int getListLen(ListNode *head) // 获取链表长度
    {
        int len = 0;
        while (head)
        {
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode *forwardListPtr(int long_len, int short_len, ListNode *longHead) // 前移较长的链表的头指针
    {
        int delta = long_len - short_len;
        while (longHead && delta--)
        {
            longHead = longHead->next;
        }
        return longHead;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = getListLen(headA);
        int lenB = getListLen(headB);

        if (lenA > lenB)
        {
            headA = forwardListPtr(lenA, lenB, headA);
        }
        else
        {
            headB = forwardListPtr(lenB, lenA, headB);
        }

        while (headA && headB) 
        {
            if (headA == headB)
            {
                return headA;   // 返回headA或者headB都可以，两个的值相同
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

// @lc code=end
