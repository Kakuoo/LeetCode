// 方法一 就地逆置法
// prev指针初始化为空指针（链表尾），curr指针（head），next指针（head->next）
// return的时候，prev指针指向以前的链表的最后一个节点（新链表的头节点）

// 方法二 虚拟头指针做法
// ListNode *dummy_head = new ListNode(0);
// ListNode *ret_node = dummy_head->next;
// delete dummy_head;
// return ret_node;

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 通过数组构建链表
ListNode *CreateLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);

    ListNode *curr = head;
    for (int i = 1; i < n; ++i)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

// 打印链表
void DisplayList(ListNode *const head)
{
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val << " ->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

void DeleteLinkedList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        ListNode *next = curr->next;
        delete curr;
        curr = next;
    }

    head = nullptr;
}

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = CreateLinkedList(arr, n);
    DisplayList(head);

    ListNode *head2 = Solution().reverseList(head);
    DisplayList(head2);

    DeleteLinkedList(head2);

    return 0;
}