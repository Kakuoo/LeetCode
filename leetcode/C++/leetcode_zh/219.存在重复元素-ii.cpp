/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 对整个nums建立哈希表
// 维护一段长度为k的滑动窗口，对窗口内的元素进行查表
// 维护时如果是map则需要更新index，而set不用

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> record;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (record.find(nums[i]) != record.end())
                return true;

            record.insert(nums[i]);

            if (record.size() == k + 1)
                record.erase(nums[i - k]);
        }
        return false;
    }
};

// 滑动窗口 + 维护长度为k的查找表
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++)
        {
            if (record.find(nums[i]) != record.end())
            {
                return true;
            }

            record[nums[i]] = i; // record.insert(make_pair(nums[i], i));

            if (record.size() > k)
            {
                record.erase(nums[i - k]);
            }
        }
        return false;
    }
};

// 对整个nums建立查找表
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> record;

        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = record.find(nums[i]);
            if (iter != record.end())
            {
                if (abs(iter->second - i) <= k)
                {
                    return true;
                }
                else
                {
                    // 查找表的find()函数每次只会搜索到第一个key的value，因此需要更新
                    iter->second = i; // 更新元素nums[i]所在的最新位置i
                }
            }
            else
            {
                record[nums[i]] = i;
            }
        }
        return false;
    }
};

// 暴力解法 Time Limit Exceeded
// class Solution
// {
// public:
//     bool containsNearbyDuplicate(vector<int> &nums, int k)
//     {
//         for (int i = 0;i  < nums.size(); i++)
//         {
//             for (int j = i + 1; j <= i + k && j < nums.size(); j++)
//             {
//                 if (nums[i] == nums[j] && abs(i - j) <= k)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };
// @lc code=end
