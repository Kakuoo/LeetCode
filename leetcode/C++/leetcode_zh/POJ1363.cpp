/*
 * poj
 * [1363] 合法的出栈序列 Medium
 * 
 * 
 * 问题：
 * 已知从1至n的数字序列，按顺序入栈，每个数字入栈后即可出栈，
 * 也可在栈中停留，等待后面的数字入栈后出栈，该数字再出栈，
 * 求该数字序列的出栈序列是否合法？
 * 
 */

#include <stack>
#include <queue>
using namespace std;

bool check_is_valid_order(queue<int> &order)
{
    stack<int> S; // 模拟栈
    for (queue<int>::size_type i = 0; i < order.size(); i++)
    {
        S.push(i);
        while (!S.empty() && S.top() == order.front())
        {
            S.pop();
            order.pop();
        }
        if (!S.empty())
        {
            return false;
        }
        return true;
    }
}
