/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start

#include <vector>
using namespace std;

// 使用贪心配合状态机的思想解决问题
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return nums.size(); // 少于两个数字的序列也为摇摆序列
        }
        const int BEGIN = 0;
        const int UP = 1;
        const int DOWN = 2;
        int STATE = BEGIN;
        int max_len = 1; // 摇摆序列最小长度为1
        // 从第二个元素开始扫描
        for (int i = 1; i < nums.size(); i++)
        {
            switch (STATE)
            {
            case BEGIN:
                if (nums[i - 1] == nums[i])
                {
                    continue;
                }
                else if (nums[i - 1] > nums[i])
                {
                    STATE = DOWN;
                    max_len++;
                }
                else
                {
                    STATE = UP;
                    max_len++;
                }
                break;
            case UP:
                if (nums[i - 1] > nums[i])
                {
                    STATE = DOWN;
                    max_len++;
                }
                break;
            case DOWN:
                if (nums[i - 1] < nums[i])
                {
                    STATE = UP;
                    max_len++;
                }
                break;
            }
        }
        return max_len;
    }
};
// @lc code=end
