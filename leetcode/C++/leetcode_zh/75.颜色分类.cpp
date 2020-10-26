/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

// 三路快排的思想，但是最慢 runtime 5%
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int left = -1;   // nums[0...left] = 0
        int right = nums.size();    // nums[right...n-1] = 2

        for (int i = 0; i < right;)
        {
            if (nums[i] == 1)
            {
                i++;
            }
            else if (nums[i] == 2)
            {
                right--;
                swap(nums[i], nums[right]);
            }
            else if (nums[i] == 0)
            {
                assert(nums[i] == 0);
                left++;
                swap(nums[i], nums[left]);
                i++;  
            }    
        }
    }
};

// 计数排序 简洁版 runtime 50%
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count[3] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            assert(nums[i] >= 0 && nums[i] <= 2);
            count[nums[i]]++;
        }

        int index = 0;
        for (int k = 0; k <= 2; k++)
        {
            for (int i = 0; i < count[k]; i++)
            {
                nums[index++] = k;
            }
        }
    }
};

// 计数排序 较繁琐版 最快 runtime 100%
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> num_cnt(3, 0);
        for (auto e : nums)
        {
            if (e == 0)
            {
                num_cnt[0]++;
            }
            else if (e == 1)
            {
                num_cnt[1]++;
            }
            else if (e == 2)
            {
                num_cnt[2]++;
            }
        }

        for (int i = 0; i < num_cnt[0]; i++)
        {
            nums[i] = 0;
        }
        for (int i = num_cnt[0]; i < num_cnt[0] + num_cnt[1]; i++)
        {
            nums[i] = 1;
        }
        for (int i = num_cnt[0] + num_cnt[1]; i < num_cnt[0] + num_cnt[1] + num_cnt[2]; i++)
        {
            nums[i] = 2;
        }
    }
};

// runtime 50%
// class Solution
// {
// public:
//     void sortColors(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end(), less<int>());
//     }
// };
// @lc code=end
