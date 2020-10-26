/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (64.23%)
 * Likes:    474
 * Dislikes: 0
 * Total Accepted:    95.8K
 * Total Submissions: 146.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
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

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;

        while (prev->next != nullptr && prev->next->next != nullptr)
        {
            ListNode *node1 = prev->next;
            ListNode *node2 = node1->next;
            ListNode *next_bak = node2->next;

            prev->next = node2;
            node2->next = node1;
            node1->next = next_bak;

            // update
            prev = node1;
        }

        return dummy.next;
    }
};

// 方法一：迭代
// 代码不够简化
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode new_head(0);
        ListNode *new_head_ptr = &new_head;
        new_head_ptr->next = head;
        // 新建和new_head_ptr相同的curr节点，两个指向相同内存的不同名节点
        // 一个是当前做改变的节点，一个是保持不动用来返回的节点
        ListNode *curr = new_head_ptr;
        while (head != nullptr && head->next != nullptr)
        {
            ListNode *first_node = head;
            ListNode *second_node = head->next;
            curr->next = first_node->next;
            first_node->next = second_node->next;
            second_node->next = first_node;
            // 交换完成后，改变curr和head的位置
            //由于每次循环curr节点都指向每次循环的前一节点，所以要再次把curr节点指向新循环的前一节点
            //每次移动都是由head节点来赋值操作，所以head应向右移动两格，即新循环的第一个节点
            curr = first_node;
            head = first_node->next; // head = head->next;亦可
        }
        return new_head_ptr->next; // return new_head.next;亦可
    }
};

// 方法二 ：递归
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // 递归结束条件
        if (head == nullptr || head->next == nullptr)
            return head;

        ///递归单元内两个节点做交换
        //定义一个p结点为head->next(该递归单元内第二个节点)
        //记录下一次递归的head
        ListNode *p = head->next;
        ListNode *recursion_head = p->next;

        p->next = head;
        head->next = swapPairs(recursion_head);

        return p;
    }
};
// @lc code=end
