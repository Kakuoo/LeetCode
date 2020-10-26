/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <map>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//题目要求深拷贝，则需使用new堆区开辟内存，深度拷贝链表
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, int> node_map;
        vector<Node *> node_vec; // 存储待返回的新链表，用于保留链表next指针的连接顺序
        Node *ptr = head;
        int i = 0; // 记录vector中的连接顺序
        while (ptr)
        {
            node_vec.push_back(new Node(ptr->val));
            node_map[ptr] = i; // 记录原始链表的地址的映射关系
            ptr = ptr->next;
            i++;
        }
        node_vec.push_back(0); // 插入新链表的尾结点，省略很多特殊情况的处理工作

        i = 0;      // i置0，重新遍历原始链表生成新链表
        ptr = head; // ptr置head，重新遍历原始链表生成新链表
        while (ptr)
        {
            node_vec[i]->next = node_vec[i+1];  //通过node_vec的next指针连接各个节点 
            // 在刚刚生成的链表上添加random信息
            if (ptr->random)
            {
                int id = node_map[ptr->random]; // 取出在node_map中对应的vector的id，vector[id]
                node_vec[i]->random = node_vec[id];  // 补充新链表上的random信息
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];
    }
};
// @lc code=end
