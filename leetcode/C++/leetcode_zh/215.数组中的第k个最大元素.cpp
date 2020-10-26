/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start

#include <vector>
#include <queue>
using namespace std;


// 快速排序
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
    }
};


// 优先级队列
// runtime 24ms 54%
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> small_heap;

        for (vector<int>::size_type i = 0; i < nums.size(); i++)
        {
            if (small_heap.size() < k)
            {
                small_heap.push(nums[i]);
            }
            else if (small_heap.size() >= k)
            {
                if (small_heap.top() < nums[i])
                {
                    small_heap.pop();
                    small_heap.push(nums[i]);
                }
                else if (small_heap.top() >= nums[i])
                {
                    continue;
                }
            }
        }
        return small_heap.top();
    }
};


// runtime 32 ms
// class Solution
// {
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         priority_queue<int, vector<int>, less<int>> heap;

//         for (auto e : nums)
//         {
//             heap.push(e);
//         }

//         while (--k)
//         {
//             heap.pop();
//         }
//         return heap.top();
//     }
// };



// 维护K大小的最小堆，时间复杂度为O(N*logK)
// class Solution
// {
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         priority_queue<int, vector<int>, greater<int>> small_heap;
//         for (vector<int>::size_type i = 0; i< nums.size(); i++)
//         {
//             if (small_heap.size() < k)
//             {
//                 small_heap.push(nums[i]);
//             }
//             else if (nums[i] < small_heap.top())
//             {
//                 continue;
//             }
//             else
//             {
//                 small_heap.pop();
//                 small_heap.push(nums[i]);
//             }
//         }
//         return small_heap.top();
//     }
// };

// @lc code=end
