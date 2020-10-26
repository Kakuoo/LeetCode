/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start

#include <stack>
using namespace std;

// 复杂方法：每次遍历查找栈中最小值
// 简单方法：希望使用O(1)复杂度，另外申请一个栈用于记录栈中各个状态的最小值实现该功能

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        _data_stack.push(x);
        if (_min_stack.empty())
        {
            _min_stack.push(x);
        }
        else
        {
            if (x < getMin())
            {
                _min_stack.push(x);
            }
            else
            {
                _min_stack.push(getMin());
            }
        }
    }

    void pop()
    {
        _data_stack.pop();
        _min_stack.pop();
    }

    int top()
    {
        return _data_stack.top();
    }

    int getMin()
    {
        return _min_stack.top();
    }

private:
    stack<int> _data_stack;
    stack<int> _min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
