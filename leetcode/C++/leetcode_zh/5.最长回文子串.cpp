/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <limits.h>
using namespace std;

// 中心扩展的代码简洁优化版
// 但是申请中间变量太多，影响运行速度 runtime 60%
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;

        string res;
        for (int i = 0; i < s.size(); i++)
        {
            string s1 = Palindrome(s, i, i);
            string s2 = Palindrome(s, i, i + 1);

            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }

        return res;
    }

private:
    string Palindrome(string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return s.substr(left + 1, right - 1 - (left + 1) + 1);
    }
};

// 中心扩展 runtime 90%
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;

        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            CenterDilation(s, i, i, start, end);     // 奇数对称
            CenterDilation(s, i, i + 1, start, end); // 偶数对称
        }
        return s.substr(start, end - start + 1);
    }

private:
    void CenterDilation(const string &s, int left, int right, int &start, int &end)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        // 判断回文子串的长度
        if ((end - start + 1) < ((right - 1) - (left + 1) + 1)) // 主要考虑上面while最后一次循环改变了left，right的值
        {
            start = left + 1;
            end = right - 1;
        }
    }
};

// // 暴力解法
// // Time Limit Exceeded 92/103
// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         if (s.empty())
//             return "";

//         int l = 0;
//         int tmp_l = 0;
//         int r = s.size() - 1;

//         int res[2] = {0, 0};
//         int len = 0;
//         while (l < r)
//         {
//             while (tmp_l < r && s[tmp_l] != s[r])
//                 tmp_l++;

//             if (tmp_l < r)
//             {
//                 if (IsPaliandrome(s, tmp_l, r))
//                 {
//                     int new_len = r - tmp_l + 1;
//                     if (len <= new_len)
//                     {
//                         res[0] = tmp_l;
//                         res[1] = r;
//                         len = new_len;
//                     }
//                 }
//                 tmp_l++;
//             }
//             else
//             {
//                 tmp_l = 0;
//                 r--;
//             }
//         }

//         return s.substr(res[0], res[1] - res[0] + 1);
//     }

// private:
//     bool IsPaliandrome(string &s, int l, int r)
//     {
//         while (l <= r)
//         {
//             if (s[l] == s[r])
//             {
//                 l++;
//                 r--;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// @lc code=end
