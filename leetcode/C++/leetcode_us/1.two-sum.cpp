/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++)
        {
            if (record.find(target - nums[i]) != record.end())
            {
                return {record[target - nums[i]], i};
            }

            record[nums[i]] = i;
        }
        
        return {};
    }
};

// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         vector<int> res;
//         for (int i = 0; i < nums.size() - 1; i++)
//         {
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 if (nums[i] + nums[j] == target)
//                 {
//                     res.push_back(i);
//                     res.push_back(j);
//                 }
//             }
//         }

//         return res;
//     }
// };
// @lc code=end
