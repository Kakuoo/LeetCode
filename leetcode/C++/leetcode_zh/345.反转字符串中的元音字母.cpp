/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

// runtime 12ms 69%
class Solution
{
public:
    string reverseVowels(string s)
    {
        string tools = "aeiouAEIOU";
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (tools.find(s[left]) == tools.npos && left < right)
            {
                left++;
            }
            while (tools.find(s[right]) == tools.npos && left < right)
            {
                right--;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

// runtime 8ms 92% 
class Solution
{
private:
    bool IsVowels(char ch)
    {
        bool condition = (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U');
        if (condition)
        {
            return true;
        }
        return false;
    }

public:
    string reverseVowels(string s)
    {
        vector<char> vec;
        for (int i = 0; i < s.size(); i++)
        {
            if (IsVowels(s[i]))
            {
                vec.push_back(s[i]);
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (IsVowels(s[i]))
            {
                s[i] = vec.back();
                vec.pop_back();
            }
        }
        return s;
    }
};
// @lc code=end
