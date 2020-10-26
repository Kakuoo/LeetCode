/*
 * @lc app=leetcode.cn id=25 lang=cpp   ``  
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (56.10%)
 * Likes:    456
 * Dislikes: 0
 * Total Accepted:    51.9K
 * Total Submissions: 89.3K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
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

// 递归
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dummy(0);
        ListNode *prev = &dummy;
        ListNode *curr = &dummy;

        // 统计链表长度
        int cnt = 0;
        while (curr) // 此处若为curr = curr->next，则下一个while中条件为>=
        {
            ++cnt; // 统计链表长度
            curr = curr->next;
        }

        while (cnt > k) // 包含临时头节点
        {
            int n = k;
            curr = prev->next;

            // for (int i = 1; i < n; i++)  // i=1 若k=3，则只需循环两次
            while (curr && curr->next && --n > 0) // --n 若k=3，则只需循环两次，此处不可以是 n--
            {
                ListNode *next_bak = curr->next;
                curr->next = next_bak->next;
                next_bak->next = prev->next;  // 必须为prev->next，不能用curr替代
                prev->next = next_bak;
            }
            prev = curr;
            cnt -= k;
        }
        return dummy.next;
    }
};

// 双层递归
// 太巧妙了
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 统计链表长度
        int count = 0;
        ListNode *curr = head; // 记录每K个递归单位的起始节点
        while (curr && count < k)
        {
            ++count;
            curr = curr->next;
        }

        if (count < k)
            return head;

        ListNode *dummy = reverse(head, k); // 以K个为单位进行递归
        head->next = reverseKGroup(curr, k);
        return dummy;
    }

private:
    ListNode *reverse(ListNode *node, int k)
    {
        if (k == 1)
            return node;
            
        ListNode *curr = reverse(node->next, k - 1); // 用于在小层递归中返回
        node->next->next = node;
        node->next = nullptr;
        return curr;
    }
};

// @lc code=end
