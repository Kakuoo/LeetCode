/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start

#include <stack>
using namespace std;

// 方法一 算法复杂度O(n^2)
class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stack<int> temp_stack;
        while (!_data_stack.empty())
        {
            int &tmp = _data_stack.top();
            _data_stack.pop();
            temp_stack.push(tmp);
        }
        temp_stack.push(x);
        while (!temp_stack.empty())
        {
            int &tmp = temp_stack.top();
            temp_stack.pop();
            _data_stack.push(tmp);
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (_data_stack.empty())
            return -1;

        int x = _data_stack.top();
        _data_stack.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        if (_data_stack.empty())
            return -1;

        return _data_stack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return _data_stack.empty();
    }

private:
    stack<int> _data_stack;
};

// 方法二 双栈法 算法复杂度O(n)
// 采用adjust调整input栈和output栈
class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        _input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        adjust();
        int &x = _output.top();
        _output.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        adjust();
        return _output.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        // if (_input.empty() && _output.empty())
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }

        // return (_input.empty() && _output.empty());

        return (_input.empty() && _output.empty()) ? true : false;
    }

private:
    void adjust()
    {
        if (!_output.empty())
        {
            return;
        }
        else
        {
            while (!_input.empty())
            {
                int &tmp = _input.top();
                _output.push(tmp);
                _input.pop();
            }
        }
    }

    stack<int> _input;
    stack<int> _output;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
