/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start

#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end(), greater<int>()); // 胃口最大的小朋友在前
        sort(s.begin(), s.end(), greater<int>()); // 最大尺寸的比饼干在前

        int res = 0;
        int g_idx = 0;
        int s_idx = 0;
        while (g_idx < g.size() && s_idx < s.size())
        {
            if (s[s_idx] >= g[g_idx])
            {
                res++;
                g_idx++;
                s_idx++;
            }
            else
            {
                g_idx++;
            }
        }
        return res;
    }
};

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;  // child代表满足了几个孩子
        int cookie = 0; // cookie代表尝试了几个糖果
        while (cookie < s.size() && child < g.size())
        {
            if (g[child] <= s[cookie])
            {
                child++;
            }
            cookie++;
        }
        return child; // 最终child即为得到满足的孩子个数
    }
};
// @lc code=end
