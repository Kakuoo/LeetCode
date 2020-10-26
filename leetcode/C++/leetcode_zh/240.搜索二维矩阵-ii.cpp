/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;

// 从右上角至左下角
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int x = 0;
        int y = matrix[0].size() - 1;
        while (x < matrix.size() && y >= 0)
        {
            if (matrix[x][y] < target)
            {
                x++;
            }
            else if (matrix[x][y] > target)
            {
                y--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

// // 内部循环采用二分搜索 296ms 13.78%
// class Solution
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         for (int i = 0; i < matrix.size(); i++)
//         {
//             // 进入每一行后再采用二分搜索
//             int left = 0;
//             int right = matrix[0].size() - 1;
//             while (left <= right)
//             {
//                 int mid = left + (right - left) / 2;
//                 if (matrix[i][mid] < target)
//                 {
//                     left = mid + 1;
//                 }
//                 else if (matrix[i][mid] > target)
//                 {
//                     right = mid - 1;
//                 }
//                 else
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// // Time Limit Exceeded
// class Solution
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         for (int i = 0; i < matrix.size(); i++)
//         {
//             for (int j = 0; j < matrix[0].size(); j++)
//             {
//                 if (matrix[i][j] == target)
//                     return true;
//             }
//         }
//         return false;
//     }
// };
// @lc code=end
