/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

// 52ms 92%
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // char tmp;
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            Reverse(s, left++, right--);
        }
    }

    void Reverse(vector<char> &str, int left, int right)
    {
        char tmp;
        tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
    }
};

// runtime 48ms  97%
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        char tmp;
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};

// class Solution
// {
// public:
//     void reverseString(vector<char> &s)
//     {
//         reverse(s.begin(), s.end());
//     }
// };
// @lc code=end
