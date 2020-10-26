/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

// n最大为500，提示了可以使用O(n^2)的算法，不会超时
// 点的坐标在[-10000, 10000]，计算距离时使用int已经足够

// 观察到i是一个枢纽，对于每个点i，遍历其余点到i的距离
// 可以制作查找表来查找距离i有相同距离的点有多少个
// 以point i为基础，距离为key，距离相同的点个数为value

// 时间复杂度O(n^2)，空间复杂度O(n)
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int res = 0;
        for (int i = 0; i < points.size(); i++)
        {
            // <int, int> 第一个int指距离当前点的距离，第二个int指与当前点距离相同的点的个数
            unordered_map<int, int> record;
            for (int j = 0; j < points.size(); j++)
            {
                if (j != i)
                {
                    record[dist(points[i], points[j])]++;
                }
            }
            for (auto it = record.begin(); it != record.end(); it++)
            {
                if (it->second == 1)
                    continue;
                res += (it->second) * (it->second - 1);
            }
        }
        return res;
    }

private:
    int dist(const vector<int> &points1, const vector<int> &points2)
    {
        return (points1[0] - points2[0]) * (points1[0] - points2[0]) 
             + (points1[1] - points2[1]) * (points1[1] - points2[1]);
    }
};

// class Solution
// {
// public:
//     int numberOfBoomerangs(vector<vector<int>> &points)
//     {
//         int res = 0;
//         for (int i = 0; i < points.size() - 2; i++)
//         {
//             for (int j = i + 1; j < points.size() - 1; j++)
//             {
//                 for (int k = j + 1; k < points.size(); k++)
//                 {
//                     if (is_equal_distance(points[i], points[j], points[k]))
//                     {
//                         res++;
//                     }
//                     if (is_equal_distance(points[i], points[k], points[j]))
//                     {
//                         res++;
//                     }
//                     if (is_equal_distance(points[j], points[i], points[k]))
//                     {
//                         res++;
//                     }
//                     if (is_equal_distance(points[j], points[k], points[i]))
//                     {
//                         res++;
//                     }
//                     if (is_equal_distance(points[k], points[i], points[j]))
//                     {
//                         res++;
//                     }
//                     if (is_equal_distance(points[k], points[j], points[i]))
//                     {
//                         res++;
//                     }
//                 }
//             }
//         }
//         return res;
//     }

// private:
//     bool is_equal_distance(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
//     {
//         float dist1 = pow(nums1[0] - nums2[0], 2) + pow(nums1[1] - nums2[1], 2);
//         float dist2 = pow(nums1[0] - nums3[0], 2) + pow(nums1[1] - nums3[1], 2);
//         if (dist1 == dist2)
//         {
//             return true;
//         }
//         return false;
//     }
// };
// @lc code=end
