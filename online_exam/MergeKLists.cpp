#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *MergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode head(-1);
    ListNode *ptr_head = &head;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            ptr_head->next = l1;
            l1 = l1->next;
        }
        else if (l1->val > l2->val)
        {
            ptr_head->next = l2;
            l2 = l2->next;
        }
        ptr_head = ptr_head->next;
    }
    if (l1)
    {
        ptr_head->next = l1;
    }
    if (l2)
    {
        ptr_head->next = l2;
    }
    return head.next;
}

ListNode *MergeLists(vector<ListNode *> &lists)
{
    // 归并
    if (lists.size() == 0)
    {
        return nullptr;
    }
    if (lists.size() == 1)
    {
        return lists[0];
    }
    if (lists.size() == 2)
    {
        return MergeTwoLists(lists[0], lists[1]);
    }

    vector<ListNode *> sub_list_1;
    vector<ListNode *> sub_list_2;
    int mid = lists.size() / 2;

    for (int i = 0; i < mid; i++)
    {
        sub_list_1.push_back(lists[i]);
    }

    for (int i = mid; i < lists.size(); i++)
    {
        sub_list_2.push_back(lists[i]);
    }
    ListNode *l1 = MergeLists(sub_list_1);
    ListNode *l2 = MergeLists(sub_list_2);

    return MergeTwoLists(l1, l2);

    //// 之前写的巨慢的方法
    // ListNode *ret = nullptr;
    // for (int i = 0; i < lists.size(); i++)
    // {
    //     MergeTwoLists(ret, lists[i]);
    // }
    // return ret;
}

void DeleteNodeLists(ListNode *node)
{
    ListNode *prev = node;
    while (node)
    {
        prev = prev->next;
        delete node;
        node = prev;
    }
}

int main()
{
    int n = 0;
    cin >> n;

    // Input
    ListNode head(-1);
    vector<ListNode *> node_vec(n);
    for (int i = 0; i < n; i++)
    {
        // 构建n个链表
        int num = 0;
        ListNode *ptr_head = &head;
        while (cin >> num)
        {
            ListNode *tmp = new ListNode(num);
            ptr_head->next = tmp;
            ptr_head = ptr_head->next;

            if (cin.get() == '\n')
            {
                break;
                node_vec[i] = head.next;
            }
        }
    }

    // Merge n lists
    ListNode *res = nullptr;
    res = MergeLists(node_vec);

    // Output
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    // Delete n个链表
    DeleteNodeLists(res);

    return 0;
}