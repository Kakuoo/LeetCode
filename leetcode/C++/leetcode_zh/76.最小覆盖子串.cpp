/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.34%)
 * Likes:    421
 * Dislikes: 0
 * Total Accepted:    33.1K
 * Total Submissions: 93K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        
    }
};

/*
 * 方法：双指针扫描字符串（双指针维护窗口/滑块）
 * 在整个过程中，使用begin与i维护一个窗口，该窗口中的子串满足题目条件（包含T中所有字符），窗口线性向前滑动，整体时间复杂度为O(n)
 * 
 */

/*
 * 1.设置两个字符哈希数组，map_s与map_t，map_s代表当前处理的窗口区间中的字符数量
 *  map_t代表子串T的字符数量
 * 2.设置两个指针（记作指针i与指针begin）指向字符串的第一个字符
 * 3.指针向后逐个扫描字符串中的字符，在这个过程中， 循环检查begin指针是否可以向前移动：
 *   如果当前begin指向的字符T中没出现，直接前移beign
 *   如果begin指向的字符T中出现了，但是当前区间窗口中的该字符数量足够，向前移动begin，并更新map_s；
 *   否则不能移动begin，跳出检查。
 * 4.指针i每向前扫描一个字符，即检查一下是否可以更新最终结果（找到最小的包含T中各个字符的窗口）
 * 
 */

class Solution
{
public:
    string minWindow(string s, string t)
    {
        const int MAX_ARRAY_LEN = 128;
        int map_s[MAX_ARRAY_LEN] = {0};
        int map_t[MAX_ARRAY_LEN] = {0};

        vector<int> vec_t; // 记录t字符串中有哪些字符
        for (int i = 0; i < t.length(); i++)
        {
            map_t[t[i]]++; // 遍历t，记录s字符串中的字符个数
        }
        for (int i = 0; i < MAX_ARRAY_LEN; i++)
        {
            if (map_t[i] > 0)
            {
                vec_t.push_back(i); // 遍历，将字符串t中出现的字符存储到vec_t中
            }
        }

        int window_begin = 0;                // 最小窗口的起始指针
        string result;                       // 最小窗口对应的字符串
        for (int i = 0; i < s.length(); i++) // i代表了窗口的尾指针
        {
            map_s[s[i]]++; // 将尾指针指向的字符添加到表示窗口的map中
            while (window_begin < i)
            {
                char begin_ch = s[window_begin];
                if (map_t[begin_ch] == 0) // 若当前头指针指向的字符没有在字符串t中出现
                {
                    window_begin++; // 窗口头指针前移
                }
                // 头指针指向的字符出现在T中，窗口内有超过T中该字符个数的字符
                else if (map_s[begin_ch] > map_t[begin_ch])
                {
                    map_s[begin_ch]--; // 头指针前移，指向的字符减少1个
                    window_begin++;
                }
                else
                {
                    break;
                }
            }
            if (is_in_window(map_s, map_t, vec_t))
            {
                int new_window_len = i - window_begin + 1;
                if (result == "" || result.length() > new_window_len)
                {
                    result = s.substr(window_begin, new_window_len); // 替换窗口对应字符
                }
            }
        }

        return result;
    }

private:
    bool is_in_window(int map_s[], int map_t[], vector<int> &vec_t)
    {
        for (int i = 0; i < vec_t.size(); i++) // 利用vec_t遍历t中出现的字符
        {
            if (map_s[vec_t[i]] < map_t[vec_t[i]])
            {
                return false; // 如果s中出现的字符数量小于t中该字符出现的数量
            }
        }
        return true;
    }
};
// @lc code=end
