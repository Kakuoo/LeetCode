/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * 1.直接的可以使用四重for循环，但是复杂度过高O(n^4)
 * 
 * 2.根据a哈希表，利用target - nums[a]，对b，c，d查表
 * 
 * 3.根据a，b制作哈希表，利用target - nums[a] - nums[b]，对c，d查表
 * 
 */

// 两层for循环 + 双指针 O(n^3)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;
        if (nums.size() < 4)
            return ret;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = nums.size() - 1;
                int new_target = target - nums[i] - nums[j];
                while (left < right)
                {
                    if (nums[left] + nums[right] == new_target)
                    {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                    else if (nums[left] + nums[right] < new_target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return ret;
    }
};

// 四重for循环 复杂度 O(n^4) Time Limited
// class Solution
// {
// public:
//     vector<vector<int>> fourSum(vector<int> &nums, int target)
//     {
//         vector<vector<int>> ret;
//         if (nums.size() < 4)
//             return ret;

//         sort(nums.begin(), nums.end());

//         for (int i = 0; i < nums.size() - 3; i++)
//         {
//             if (i != 0 && nums[i] == nums[i - 1])
//                 continue;
//             for (int j = i + 1; j < nums.size() - 2; j++)
//             {
//                 if (j != i + 1 && nums[j] == nums[j - 1])
//                     continue;
//                 for (int k = j + 1; k < nums.size() - 1; k++)
//                 {
//                     if (k != j + 1 && nums[k] == nums[k - 1])
//                         continue;
//                     for (int q = k + 1; q < nums.size(); q++)
//                     {
//                         if (q != k + 1 && nums[q] == nums[q - 1])
//                             continue;
//                         if (nums[i] + nums[j] + nums[k] + nums[q] == target)
//                         {
//                             ret.push_back({nums[i], nums[j], nums[k], nums[q]});
//                         }
//                     }
//                 }
//             }
//         }
//         return ret;
//     }
// };

// 方法三：编译报错 overflow
// class Solution
// {
// public:
//     vector<vector<int>> fourSum(vector<int> &nums, int target)
//     {
//         vector<vector<int>> ret;
//         unordered_multimap<int, int> record;
//         if (nums.size() < 4)
//             return ret;

//         sort(nums.begin(), nums.end());

//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = 0; j < nums.size(); j++)
//             {
//                 if (i == j)
//                     continue;
//                 record.insert(make_pair(nums[i] + nums[j], i));
//                 record.insert(make_pair(nums[i] + nums[j], j));
//             }
//         }

//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = 0; j < nums.size(); j++)
//             {
//                 if (i == j)
//                     continue;
//                 auto it = record.equal_range(target -nums[i] + nums[j]);
//                 if (it.first != end(record))
//                 {
//                     for (auto p = it.first; p != it.second; p++)
//                     {
//                         ret.push_back({nums[i], nums[j], nums[p->first], nums[p->second]});
//                     }
//                 }
//             }
//         }

//         return ret;
//     }
// };

// @lc code=end
