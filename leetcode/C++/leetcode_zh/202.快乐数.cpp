/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <unordered_map>
#include <cmath>
using namespace std;

// 使用哈希表map或者set检查是否有数字出现循环

// 快慢指针
class Solution
{
public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;
        do
        {
            slow = BitSquareSum(slow);
            fast = BitSquareSum(fast);
            fast = BitSquareSum(fast);
        } while (slow != fast);
        return slow == 1;
    }

private:
    int BitSquareSum(int n)
    {
        int bit = 0;
        int sum = 0;
        while (n > 0)
        {
            bit = n % 10;
            sum += bit * bit;
            n /= 10;
        }
        return sum;
    }
};

// 暴力解法 100次循环
class Solution
{
public:
    bool isHappy(int n)
    {
        int sum;
        int tmp = 0;
        for (int i = 0; i < 100; i++)
        {
            sum = 0;
            while (n > 0)
            {
                tmp = n % 10;
                n /= 10;
                sum += pow(tmp, 2);
            }
            n = sum;
            if (n == 1)
                return true;
        }
        return false;
    }
};
// @lc code=end
