/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
    assert(a.size() == 2 && b.size() == 2);

    if (a[0] != b[0])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}


// 贪心算法
// 区间结尾最早的越有可能不重叠，留给后面更大的空间，后面越有可能容纳更多空间
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(), compare);

        int res = 1;
        int prev = 0;  // 用于记录上一个区间
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[prev][1] <= intervals[i][0])
            {
                res++;
                prev = i;
            }
        }

        return intervals.size() - res;
    }
};


// 动态规划
bool compare(const vector<int> &a, const vector<int> &b)
{
    assert(a.size() == 2 && b.size() == 2);

    if (a[0] != b[0])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
        if (intervals.empty())
            return 0;
            
        sort(intervals.begin(), intervals.end(), compare);

        vector<int> memo(intervals.size(), 1);

        for (int i = 1; i < intervals.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (intervals[i][0] >= intervals[j][1])
                {
                    memo[i] = max(memo[i], 1 + memo[j]);
                }
            }
        }

        int res = 0;
        for (const int &e : memo)
        {
            res = max(res, e);
        }

        return intervals.size() - res;
    }
};


// liuyubobo
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(const Interval &a, const Interval &b)
{
    if (a.start != b.start)
        return a.start < b.start;
    else
        return a.end < b.end;
}

// 动态规划，借鉴最长上升子序列
// 区间结尾最早的越有可能不重叠，留给后面更大的空间，后面越有可能容纳更多空间
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        vector<Interval> res;
        for (int i = 0; i < intervals.size(); i++)
        {
            Interval tmp;
            tmp.start = intervals[i][0];
            tmp.end = intervals[i][1];
            res.push_back(Interval(tmp));
        }
        // return eraseOverlap(vec_intervals);
        return eraseOverlap(res);
    }

    int eraseOverlap(vector<Interval> &intervals)
    {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(), compare);

        vector<int> memo(intervals.size(), 1);
        for (int i = 1; i < intervals.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (intervals[i].start >= intervals[j].end)
                {
                    memo[i] = max(memo[i], 1 + memo[j]);
                }
            }
        }

        int res = 0;
        for (const int &e : memo)
        {
            res = max(res, e);
        }

        return intervals.size() - res;
    }
};
// @lc code=end
