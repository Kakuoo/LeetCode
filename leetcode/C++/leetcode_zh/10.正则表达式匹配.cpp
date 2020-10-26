/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
            return s.empty();

        bool is_first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');

        if (p.length() >= 2 && p[1] == '*')
        {
            return isMatch(s, p.substr(2)) || (is_first_match && isMatch(s.substr(1), p));
        }
        else
        {
            return is_first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};
// @lc code=end
