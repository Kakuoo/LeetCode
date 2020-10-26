/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start

#include <deque>
#include <queue>
using namespace std;

// 单queue实现
class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        int q_size = data_queue.size();

        data_queue.push(x);
        while (q_size--)
        {
            int &tmp = data_queue.front();
            data_queue.pop();
            data_queue.push(tmp);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        if (data_queue.empty())
            return -1;

        int tmp = data_queue.front();
        data_queue.pop();
        return tmp;
    }

    /** Get the top element. */
    int top()
    {
        if (data_queue.empty())
            return -1;

        return data_queue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return data_queue.empty();
    }

private:
    queue<int> data_queue;
};

// 双queue实现
class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        queue<int> tmp_queue;
        while (!data_queue.empty())
        {
            int &tmp = data_queue.front();
            data_queue.pop();
            tmp_queue.push(tmp);
        }
        data_queue.push(x);
        while (!tmp_queue.empty())
        {
            int &tmp = tmp_queue.front();
            tmp_queue.pop();
            data_queue.push(tmp);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        if (data_queue.empty())
            return -1;

        int tmp = data_queue.front();
        data_queue.pop();
        return tmp;
    }

    /** Get the top element. */
    int top()
    {
        if (data_queue.empty())
            return -1;

        return data_queue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return data_queue.empty();
    }

private:
    queue<int> data_queue;
};

// 可以轻微作弊的手法，双端队列deque
class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        deque<int> temp_queue;
        temp_queue.push_back(x);
        while (!_data_queue.empty())
        {
            temp_queue.push_back(_data_queue.front());
            _data_queue.pop_front();
        }
        while (!temp_queue.empty())
        {
            _data_queue.push_back(temp_queue.front());
            temp_queue.pop_front();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int x = _data_queue.front();
        _data_queue.pop_front();
        return x;
    }

    /** Get the top element. */
    int top()
    {
        return _data_queue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return _data_queue.empty();
    }

private:
    deque<int> _data_queue;
};

// /**
//  * Your MyStack object will be instantiated and called as such:
//  * MyStack* obj = new MyStack();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->top();
//  * bool param_4 = obj->empty();
//  */
// // @lc code=end
