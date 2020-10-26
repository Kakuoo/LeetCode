/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <vector>
#include <stack>
using namespace std;

class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// 栈实现
class NestedIterator
{
public:
    stack<NestedInteger const*> st;

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        // 逆序入栈
        for (int i = nestedList.size() - 1; i >= 0; i--)
        {
            st.push(&nestedList[i]);
        }
    }

    int next()
    {
        int ret = st.top()->getInteger();
        st.pop();
        return ret;
    }

    //遍历nestList，直到栈顶元素为Integer
    bool hasNext()
    {
        if (st.empty())
            return false;

        NestedInteger const *tmp = st.top();
        while (!tmp->isInteger())
        {
            st.pop();
            vector<NestedInteger> const &sub_list = tmp->getList();
            for (int i = sub_list.size() - 1; i >= 0; i--)
            {
                st.push(&sub_list[i]);
            }
            // 列表可能为空
            if (st.empty())
                return false;
            tmp = st.top();
        }
        return true;
    }
};

// 一次取出，非迭代器版本
class NestedIterator
{
public:
    vector<int> vec;
    int index;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        this->index = 0;
        dfs(nestedList);
    }

    int next()
    {
        return vec[index++];
    }

    bool hasNext()
    {
        return index == vec.size() ? false : true;
    }

    void dfs(vector<NestedInteger> const &nested_list)
    {
        for (auto const &e : nested_list)
        {
            if (e.isInteger())
            {
                vec.push_back(e.getInteger());
            }
            else
            {
                dfs(e.getList());
            }
        }
    }
};

// 迭代器版本
// 遇到List内部还是List就再创建一个Iterator去遍历内部的List

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
