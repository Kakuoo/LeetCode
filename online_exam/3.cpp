#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 合并两个有序链表
ListNode *Merge2Lists(ListNode *node1, ListNode *node2)
{
    if (!node1 || !node2)
        return node1 ? node1 : node2;
    
    ListNode head(-1);
    ListNode *head_bak = &head;
    ListNode *ptr1 = node1;
    ListNode *ptr2 = node2;

    while (ptr1 && ptr2)
    {
        if (ptr1->val < ptr2->val)
        {
            head_bak->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            head_bak->next = ptr2;
            ptr2 = ptr2->next;
        }
        head_bak = head_bak->next;
    }
    head_bak->next = ptr1 ? ptr1 : ptr2;
    return head.next;
}

// 合并K个有序链表
ListNode *MergeLists(vector<ListNode *> lists)
{
    ListNode *ret = nullptr;
    for (int i = 0; i < lists.size(); i++)
    {
        ret = Merge2Lists(ret, lists[i]);
    }
    return ret;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<ListNode *> node_vec(n, 0);

    for (int i = 0; i < n; i++)
    {
        int num = NULL;
        while (cin >> num)
        {

        }
    }

    MergeLists(node_vec);
    
    // output nodes
    for (auto e : node_vec)
    {
        cout << e->val;
    }

    return 0;
}
