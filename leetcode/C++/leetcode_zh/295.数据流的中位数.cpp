/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start

#include <queue>
using namespace std;

// 动态维护一个最大堆和一个最小堆
// 最大堆最小堆各存储一半数据，维持最大堆的堆顶比最小堆的堆顶小
// 则中位数为两个堆顶的其中一个，或是取平均的结果
class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (big_heap.empty())
        {
            big_heap.push(num);
            return;
        }

        if (big_heap.size() == small_heap.size())
        {
            if(num <= big_heap.top())
            {
                big_heap.push(num);
            }
            else
            {
                small_heap.push(num);
            }
        }
        else if(big_heap.size() > small_heap.size())
        {
            if(num > big_heap.top())
            {
                small_heap.push(num);
            }
            else
            {
                small_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(num);
            }
        }
        else if(big_heap.size() < small_heap.size())
        {
            if (num < small_heap.top())
            {
                big_heap.push(num);
            }
            else
            {
                big_heap.push(small_heap.top());
                small_heap.pop();
                small_heap.push(num);
            }
        }
    }

    double findMedian()
    {
        if (small_heap.size() == big_heap.size())
        {
            return (small_heap.top() + big_heap.top())/2.0;
        }
        else if (small_heap.size() < big_heap.size())
        {
             return big_heap.top();
        }
        else
        {
            return small_heap.top();
        }
        
    }

private:
    priority_queue<int, vector<int>, greater<int>> small_heap; //最小堆
    priority_queue<int, vector<int>, less<int>> big_heap;      //最大堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
