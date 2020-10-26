/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a.front() < b.front();
}

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
        {
            return 0;
        }
        // 对每个区间对的左端点由小至大排序，方便后续的排序逻辑
        sort(points.begin(), points.end(), cmp);

        int shoot_num = 1;
        int shoot_front = points[0].front();
        int shoot_back = points[0].back();
        for(int i = 1; i< points.size();i++)
        {
            if (shoot_back >= points[i].front())
            {
                shoot_front = points[i].front();
                if (shoot_back >= points[i].back())
                {
                    shoot_back = points[i].back();
                }
            }
            else
            {
                shoot_num++;
                shoot_front = points[i].front();
                shoot_back = points[i].back();
            }
        }
    return shoot_num;
    }
};
// @lc code=end
