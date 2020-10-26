/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int votes = 0;
        int tmp = 0;
        for (int e : nums)
        {
            if (votes == 0)
                tmp = e;
            
            if (e == tmp)
                votes += 1;
            else
                votes += -1;
        }

        return votes > 0;
    }
};

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++)
        {
            record[nums[i]]++;
        }

        int res = -1;
        int cnt = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (record[nums[i]] >= cnt)
            {
                cnt = record[nums[i]];
                res = nums[i];
            }
        }

        return res;
    }
};
// @lc code=end
