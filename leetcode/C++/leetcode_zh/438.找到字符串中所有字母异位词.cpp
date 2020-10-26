/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.size() < p.size())
            return {};

        vector<int> res;
        vector<int> freq_s(26);
        vector<int> freq_p(26);
        int l = 0;
        int r = -1;

        for (int i = 0; i < p.size(); i++)
        {
            freq_p[p[i] - 'a']++;
        }

        while (l < s.size())
        {
            if (r + 1 < s.size() && freq_s[s[r + 1] - 'a'] < freq_p[s[r + 1] - 'a'])
            {
                r++;
                freq_s[s[r] - 'a']++;
            }
            else
            {
                freq_s[s[l] - 'a']--;
                l++;
            }

            if (freq_s == freq_p)
            {
                res.push_back(l);
            }
        }
        return res;
    }
};
// @lc code=end
