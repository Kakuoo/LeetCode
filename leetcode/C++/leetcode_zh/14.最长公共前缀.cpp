/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 4ms runtime 91.67%
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string res = "";
        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                    return res;
            }
            res += strs[0][i];
        }
        return res;
    }
};

// // Time Limit Exceeded
// class Solution
// {
// public:
//     string longestCommonPrefix(vector<string> &strs)
//     {
//         sort(strs.begin(), strs.end());

//         string res = "";
//         for (int i = 0; i < strs[0].size(); i++)
//         {
//             char tmp = strs[0][i];
//             int j = 1;
//             while (j < strs.size())
//             {
//                 if (strs[j][i] != tmp)
//                     return res;
//             }
//             res += tmp;
//         }

//         return res;
//     }
// };
// @lc code=end
