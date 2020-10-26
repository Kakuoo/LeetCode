/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>  // __gcd() 求最大公约数
#include <functional> // hash<K>
using namespace std;

// 思考：两点确定一条直线，而直线的斜率与截距不相同，
// 可以固定一点，然后根据其他点与该点所连直线的斜率建立哈希表，作为中间参考
// 使用斜率时需注意：
//     1.除数：首先注意被除数不能为0，其次，double有精度问题，以下测试案例不通过，斜率计算为1：[[0,0],[94911151,94911150],[94911152,94911151]]
//     2.最大公约数(gcd)：把他化成最简形式, 3/6 == 2/4 == 1/2

class Solution
{
public:
    // MyHash使用异或运算判断两个hash值是否相同，若相同,则异或值为0；若不同，则值不为0
    struct MyHash
    {
        size_t operator()(const pair<int, int> &x) const
        {
            return hash<size_t>()(hash<int>()(x.first)) ^ hash<int>()(x.second); // ^ 异或运算
        }
    };

    int maxPoints(vector<vector<int>> &points)
    {
        int res = 0;
        unordered_map<pair<int, int>, int, MyHash> record;

        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = __gcd(dy, dx); // 最大公约数

                if (g)
                    dx /= g, dy /= g;
                
                // 统一之后，便于建表及查表
                if (dx > 0 && dy < 0)
                    dx = -dx, dy = -dy;
                record[pair<int, int>(dx, dy)]++;
            }
            int base = record[pair<int, int>(0, 0)];
            res = max(res, base);
            for (auto const &e : record)
            {
                if (e.first != pair<int, int>(0, 0))
                    res = max(res, e.second + base);
            }
            record.clear();
        }
        return res;
    }
};

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        //两点确定一条直线
        if (points.size() < 3)
            return points.size();

        int Max = 0;
        for (int i = 0; i < points.size(); ++i) //i表示数组中的第i+1个点
        {
            //same用来表示和i一样的点
            int same = 1;
            for (int j = i + 1; j < points.size(); ++j)
            {
                int count = 0;
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                {
                    // i、j是重复点，计数
                    same++;
                }
                else
                {
                    //i、j不是重复点，则计算和直线ij在一条直线上的点
                    count++;
                    int dx = (int)(points[i][0] - points[j][0]); //Δx1
                    int dy = (int)(points[i][1] - points[j][1]); //Δy1

                    // Δy1/Δx1=Δy2/Δx2 => Δx1*Δy2=Δy1*Δx2，计算和直线ji在一条直线上的点
                    for (int k = j + 1; k < points.size(); k++)
                        if (dx * (points[i][1] - points[k][1]) == dy * (points[i][0] - points[k][0]))
                            count++;
                }
                Max = max(Max, same + count);
            }
            if (Max > points.size() / 2)
                return Max; //若某次最大个数超过所有点的一半，则不可能存在其他直线通过更多的点
        }
        return Max;
    }
};

// class Solution
// {
// public:
//     int maxPoints(vector<vector<int>> &points)
//     {
//         if (points.size() < 3)
//             return points.size();

//         int res = 0;
//         for (int i = 0; i < points.size() - 1; i++)
//         {
//             int count = 0;
//             int same_point = 0;
//             // 根据该点及下一个点所连直线的斜率建表
//             unordered_map<float, int> record;
//             for (int j = i + 1; j < points.size(); j++)
//             {
//                 if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
//                     same_point++;
//                 else
//                 {
//                     count++;
//                     // record[get_slope(points[i], points[j])]++;
//                     int dx = points[j][0] - points[i][0];
//                     int dy = points[j][1] - points[i][1];

//                     res = max(res, same_point + count);
//                 }
//             }
//             if (res > points.size() / 2)
//                 return res;
//         }
//         return res;
//     }

// private:
//     // 注意0为分母的情况
//     float get_slope(vector<int> &points1, vector<int> &points2)
//     {
//         return (points1[1] - points2[1]) / (points1[0] - points2[0]);
//     }
// };


// @lc code=end
