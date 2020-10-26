/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> record(nums1.begin(), nums1.end());
        
        set<int> res;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (record.find(nums2[i]) != record.end())
            {
                res.insert(nums2[i]);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

// class Solution
// {
// public:
//     vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
//     {

//         // 构建set
//         set<int> record;
//         for (int i = 0; i < nums1.size(); i++)
//         {
//             record.insert(nums1[i]);
//         }

//         // 构建res_set
//         set<int> res_set;
//         for (int i = 0; i < nums2.size(); i++)
//         {
//             if (record.find(nums2[i]) != record.end())
//             {
//                 res_set.insert(nums2[i]);
//             }
//         }

//         vector<int> res;
//         for (set<int>::iterator it = res_set.begin(); it != res_set.end(); it++)
//         {
//             res.push_back(*it);
//         }


//         return res;
//     }
// };
// @lc code=end
