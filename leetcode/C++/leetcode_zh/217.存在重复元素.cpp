/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        if (!nums.size())
            return false;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return false;
    }
};

// 利用map的性质
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> record;
        for (int e : nums)
            if (record[e]++)
                return true;
        return false;


        // 或者
        // for (int i = 0; i < nums.size(); ++i)
        //     record[nums[i]] = i;
        // return nums.size() > record.size() ? true : false;
    }
};
// @lc code=end
