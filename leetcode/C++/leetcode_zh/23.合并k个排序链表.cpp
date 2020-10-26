/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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

#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 方案一
//采用21题的方法，每两个链表合并再和第三个链表合并，以此进行
//时间复杂度：O(n*k*(k - 1) / 2) = O(n*k^2)过于复杂

// 方法二
// 将k*n个节点放入vector中，再将vector排序，再将节点按顺序相连
// 已知排序最优复杂度为O(nlogn)，则该方法时间复杂度： kN*logkN + kN = O(kN*logkN)
// 本题要求多链表合并，即k < N，所以一般情况下：k > logkN （例如k = 100，N = 10000）

bool cmp(const ListNode *a, const ListNode *b)
{
    return a->val < b->val;
}

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) // 传进来lists的引用
    {
        // 提取所有节点至一个vector中
        vector<ListNode *> node_vec;
        for (ListNode *dummy : lists)
        {
            while (dummy != nullptr)
            {
                node_vec.emplace_back(dummy);
                dummy = dummy->next;
            }
        }
        // for (int i = 0; i < lists.size(); i++)
        // {
        //     ListNode *dummy = lists[i];
        //     while (dummy != nullptr)
        //     {
        //         node_vec.emplace_back(dummy);
        //         dummy = dummy->next;
        //     }
        // }

        if (node_vec.size() == 0)
            return nullptr;

        // 对所有节点进行排序
        sort(node_vec.begin(), node_vec.end(), cmp);

        // 排序之后，将所有节点连接成一个链表
        ListNode dummy(0);
        ListNode *curr = &dummy;
        for (ListNode *node : node_vec)
        {
            curr->next = node;
            curr = curr->next;
        }
        curr->next = nullptr; // 注意尾指针置空，很重要！！！

        return dummy.next;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) // 传进来lists的引用
    {
        vector<ListNode *> node_vec;
        // 遍历所有链表，将所有链表都添加至node_vec中
        // for (vector<ListNode *>::iterator it = node_vec.begin(); it != node_vec.end(); it++)
        // {
        //     ListNode *head = *it;
        //     while (head)
        //     {
        //         node_vec.push_back(head);
        //         head = head->next;
        //     }
        // }

        for (vector<ListNode *>::size_type i = 0; i < lists.size(); i++)
        {
            ListNode *head = lists[i];
            while (head)
            {
                node_vec.push_back(head);
                head = head->next;
            }
        }

        if (node_vec.size() == 0)
        {
            return NULL; // 返回空链表
        }
        // 对node_vec进行排序
        sort(node_vec.begin(), node_vec.end(), cmp);

        // 连接所有节点

        // for (vector<ListNode *>::iterator it = node_vec.begin(); it != node_vec.end(); it++)
        // {
        //     (*it)->next = *(it+1);
        // }
        // node_vec[node_vec.size() - 2]->next = NULL;

        for (vector<ListNode *>::size_type i = 0; i < node_vec.size() - 1; i++) // 注意 node_vec.size() - 1
        {
            node_vec[i]->next = node_vec[i + 1];
        }
        node_vec[node_vec.size() - 1]->next = NULL;
        return node_vec[0];
    }
};

// 方法三
// 迭代的思想，对K个链表做分治，两两进行合并
// 第一轮进行k/2次，每次处理2n个数字，第二轮，进行k/4次，每次处理4n个数字
// 最后一轮，进行k/(2^logk)次，每次处理2^logk*N个值。
// 时间复杂度：2N * k/2 + 4N * k/4 + 8N * k/8 + ...+ (2^logk * N) * k/(2^logk) = Nk+Nk+...+Nk = O(kNlogk)

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // 递归终止条件
        if (lists.size() == 0)
            return nullptr;

        if (lists.size() == 1)
            return lists[0];
        
        if (lists.size() == 2)
            return mergeTwoLists(lists[0], lists[1]);

        // 递归返回方式
        // int mid = lists.size() >> 1;
        vector<ListNode *> sub_list1;
        vector<ListNode *> sub_list2;
        for (int i = 0; i < lists.size() >> 1; i++)
        {
            sub_list1.emplace_back(lists[i]);
        }
        for (int i = lists.size() >> 1; i < lists.size(); i++)
        {
            sub_list2.emplace_back(lists[i]);
        }

        ListNode *l1 = mergeKLists(sub_list1);
        ListNode *l2 = mergeKLists(sub_list2);
        
        return mergeTwoLists(l1, l2);
    }

private:
    // 合并两个有序链表
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        while (l1 && l2)
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

        if (l1)
            curr->next = l1;
        if (l2)
            curr->next = l2;

        return dummy.next;
    }
};

class Solution
{
public:
    // 合并K个有序链表
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;

        if (lists.size() == 1)
            return lists[0];
        
        if (lists.size() == 2)
            return mergeTwoLists(lists[0], lists[1]);

        vector<ListNode *> sub1_lists;
        vector<ListNode *> sub2_lists;
        int mid = lists.size() / 2;

        for (vector<ListNode *>::size_type i = 0; i < mid; i++)
        {
            sub1_lists.push_back(lists[i]);
        }
        for (vector<ListNode *>::size_type i = mid; i < lists.size(); i++)
        {
            sub2_lists.push_back(lists[i]);
        }
        ListNode *l1 = mergeKLists(sub1_lists);
        ListNode *l2 = mergeKLists(sub2_lists);

        return mergeTwoLists(l1, l2);
    }

private:
    // 合并两个有序链表
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        while (l1 && l2)
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

        if (l1)
            curr->next = l1;
        if (l2)
            curr->next = l2;
        return dummy.next;
    }
};

// @lc code=end