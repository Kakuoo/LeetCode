/*
 * @lc app=leetcode id=1297 lang=cpp
 *
 * [1297] Maximum Number of Occurrences of a Substring
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
        unordered_map<string, int> record;
        int res = 0;
        for (int i = 0; i + minSize <= s.size(); i++)
        {
            string curr = s.substr(i, minSize);

            unordered_set<char> char_set(curr.begin(), curr.end());
            if (char_set.size() <= maxLetters)
                res = max(res, ++record[curr]);
        }
        
        return res;
    }
};
// @lc code=end
