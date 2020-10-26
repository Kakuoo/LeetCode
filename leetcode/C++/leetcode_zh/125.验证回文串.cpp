/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
/**
 * 1.判断空字符
 * 2.判断字符的定义
 * 3.判断大小写
 */

// runtime 8ms 84.79 %
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right)
        {
            if (!isalnum(s[left]))
            {
                left++;
                continue;
            }

            if (!isalnum(s[right]))
            {
                right--;
                continue;
            }

            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

// 自写判断回文序列
// runtime 16ms 22%
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            if (isalnum(s[i]))
            {
                str += tolower(s[i]);
            }
        }

        // Reverse
        int len = str.size();
        for (int i = 0; i < len >> 1; i++)
        {
            if (str[i] != str[len - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};

// runtime 8ms 84.79 %
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str;
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
            {
                str += tolower(s[i]);
            }
        }

        string str_cmp(str);
        reverse(str_cmp.begin(), str_cmp.end());

        if (str_cmp == str)
        {
            return true;
        }
        return false;
    }
};


// runtime 24s 6.34%
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 48 && s[i] <= 57) str += s[i];
            if (s[i] >= 65 && s[i] <= 90) str += (s[i] + 32);
            if (s[i] >= 97 && s[i] <= 122) str += s[i];
        }

        int l = 0; 
        int r = str.size() - 1;
        while (l < r)
        {
            if (str[l] != str[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
// @lc code=end
