/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int s_idx = 0;
        int t_idx = 0;
        vector<bool> flag(s.size(), false);

        while (s_idx < s.size() && t_idx < t.size())
        {
            if (s[s_idx] == t[t_idx])
            {
                flag[s_idx] = true;
                s_idx++;
                t_idx++;
            }
            else
            {
                t_idx++;
            }
        }

        for (const bool e : flag)
        {
            if (e == false)
                return false;
        }
        return true;
    }
};


// @lc code=end
