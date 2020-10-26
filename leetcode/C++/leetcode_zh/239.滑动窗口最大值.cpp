/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (43.65%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    43.9K
 * Total Submissions: 93.6K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回滑动窗口中的最大值。
 * 
 * 
 * 
 * 进阶：
 * 
 * 你能在线性时间复杂度内解决此题吗？
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7] 
 * 解释: 
 * 
 * ⁠ 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

// 自己写的 runtime 5% 584ms
// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         deque<int> q;
//         vector<int> res;
//         for (int i = 0; i < nums.size() - k + 1; ++i)
//         {
//             auto max_num = max_element(nums.begin() + i, nums.begin() + i + k);
//             res.push_back(*max_num);
//         }
//         return res;
//     }
// };

// runtime 60% 28ms
class Solution
{
public:
    /** 
     * 需要找到滑动窗口内的最大值，滑动窗口是个先进先出的队列，在最大值滑出窗口后
     * 原来第二大的元素就要变成最大的元素，因此可以维护一个单调递减双端队列，
     * 队首存最大值，每次入队都要维护队列的单调递减性质。
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> q; // 存储nums的值
        vector<int> res(nums.size() - k + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            while (!q.empty() && nums[i] > q.back())
            { // 维护递减
                q.pop_back();
            }
            q.push_back(nums[i]);
            if (i >= k - 1)
            {
                res[i - k + 1] = q.front();
                if (q.front() == nums[i - k + 1])
                    q.pop_front(); // 最大值出队
            }
        }
        return res;
    }
};

// 不是很好理解
// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         deque<int> deque; // 存储nums的下标
//         vector<int> res(nums.size(), 0);
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             if (!deque.empty() && deque.front() == i - k)
//                 deque.pop_front();
//             while (!deque.empty() && nums[i] > nums[deque.back()])
//                 deque.push_back(i);
//             if (i >= k - 1)
//                 res.push_back(nums[deque.front()]);
//         }
//         return res;
//     }
// };
// @lc code=end
