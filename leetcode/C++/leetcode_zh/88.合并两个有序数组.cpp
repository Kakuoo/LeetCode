/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

// 从后往前排序，填充数字
// 特别的对于nums1中无元素，即为[0],其中0为给nums2的空位，需注意
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        assert(nums1.capacity() >= (m + n));

        int last = m + n - 1;
        while (m && n)
        {
            if (nums1[m - 1] <= nums2[n - 1])
            {
                nums1[last] = nums2[n - 1];
                last--;
                n--;
            }
            else if (nums1[m - 1] > nums2[n - 1])
            {
                nums1[last] = nums1[m - 1];
                last--;
                m--;
            }
        }

        while (m - 1 >= 0)
        {
            nums1[last] = nums1[m - 1];
            last--;
            m--;
        }

        while (n - 1 >= 0 )
        {
            nums1[last] = nums2[n - 1];
            last--;
            n--;
        }
    }
};

// C++ 标准库排序
// class Solution
// {
// public:
//     void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//     {
//         assert(nums1.capacity() >= (m + n));

//         for (int i = 0; i < n; i++)
//         {
//             nums1[i + m] = nums2[i];
//         }

//         sort(nums1.begin(), nums1.begin() + m + n);
//     }
// };
// @lc code=end
