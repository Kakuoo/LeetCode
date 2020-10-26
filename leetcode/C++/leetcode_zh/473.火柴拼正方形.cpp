/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 *
 * https://leetcode-cn.com/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (36.55%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 16.8K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * 
 * 还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。
 * 
 * 输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,1,2,2,2]
 * 输出: true
 * 
 * 解释: 能拼成一个边长为2的正方形，每边两根火柴。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,3,3,3,4]
 * 输出: false
 * 
 * 解释: 不能用所有火柴拼成一个正方形。
 * 
 * 
 * 注意:
 * 
 * 
 * 给定的火柴长度和在 0 到 10^9之间。
 * 火柴数组的长度不超过15。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 尝试探索类问题 适合使用递归、回溯、深度优先搜索
 * 求最短问题 适合使用宽度优先搜索
 * 
 * 若是遍历树，遍历地图所有节点，没有什么特殊的情况下，深搜和宽搜复杂度相同
 * 
 */

// 方法一：深度优先搜索
//
// class Solution
// {
// public:
//     bool makesquare(vector<int> &nums)
//     {
//         if (nums.size() < 4)
//         {
//             return false; // 不够四条边
//         }
//         int total_len = 0;
//         for (auto i : nums)
//         {
//             total_len += i;
//         }
//         if (total_len % 4 != 0)
//         {
//             return false; // 周长不能整除4
//         }
//         sort(nums.rbegin(), nums.rend()); // 降序排序，大边在前，小边在后
//         int side_len = total_len / 4;
//         for (auto i : nums)
//         {
//             if (i > side_len)
//             {
//                 return false; // 若单值大于边长side_len，一定不行
//             }
//         }
//         int bucket[4] = {0};
//         return generate(0, nums, side_len, bucket);
//     }

// private:
//     bool generate(int i, vector<int> &nums, int target, int bucket[])
//     {
//         if (i >= nums.size()) // i == nums.size() - 1 结果错误
//         {
//             return bucket[0] == target && bucket[1] == target &&
//                    bucket[2] == target && bucket[3] == target;
//         }
//         for (int k = 0; k < 4; k++)
//         {
//             if (bucket[k] + nums[i] > target)
//             {
//                 continue;
//             }
//             bucket[k] += nums[i];
//             if (generate(i + 1, nums, target, bucket))
//             {
//                 return true;
//             }
//             else
//             {
//                 // 若前面都不成功，说明以前的桶内放错了，需要减去前面的数
//                 bucket[k] -= nums[i];
//             }
//         }
//         return false;
//     }
// };

/*
 * 方法二：位运算
 * 1.构造出所有和为target的子集，存储在向量ok_subset中，这些是候选的边组合
 * 2.遍历所有的ok_subset，两两对比，如果ok_sebset[i]和ok_sebset[j]进行**与运算**的结果为0，
 * 则说明ok_sebset[i]和ok_sebset[j]表示的是无交集的两个集合（没有选择相同的火柴棍），
 * 这两个集合可以代表两个可同时存在的满足条件的边；
 * 将ok_sebset[i]与ok_sebset[i]**求或**，结果存储在ok_half中，它代表所有满足一半结果的情况
 * 3.遍历所有ok_half，两两对比，如果ok_half[i]和ok_half[j]进行**与运算**的结果为0，
 * 则返回true（说明有4个满足条件的边即可组成正方形）；否则，返回false；
 * 
 */

class Solution
{
public:
    bool makesquare(vector<int> &nums)
    {
        if (nums.size() < 4)
        {
            return false;
        }
        int total_len = 0;
        for (auto i : nums)
        {
            total_len += i;
        }
        if (total_len % 4 != 0)
        {
            return false;
        }
        int side_len = total_len / 4;
        for (auto i : nums)
        {
            if (i > side_len)
            {
                return false;
            }
        }

        vector<int> ok_subset; // 所有满足一条边代表的集合
        vector<int> ok_half;   // 所有满足两条边代表的集合
        // 例如：[1, 1, 2, 2, 2]
        int all = 1 << nums.size(); // all = 32
        /* 
         * 元素有5位，则对2^5=32种可能进行遍历，例如[1, 0 ,0 ,0 ,0 ,0] = 32， [0, 0 ,1 ,1 ,0 ,0] = 9等
         * 每位0或者1代表这意味对应的元素是否参与其中
         *
         */
        for (int i = 0; i < all; i++)   
        {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++)
            {   
                /*
                 * i和(1<<0)=1=[0, 0, 0, 0, 1],(1<<1)=2=[0, 0, 0, 1, 0],(1<<2)=4=[0, 0, 1, 0, 0],
                 * (1<<3)=8=[0, 1, 0, 0, 0],(1<<4)=16=[1, 0, 0, 0, 0]分别进行与运算
                 * 若不为0，说明两组元素有交集，则累加sum，判断sum和target是否相等，若相等，则融合其元素为一组ok_subset
                 * 
                 * 例如：
                 * 当i=[1, 1, 0, 0, 0]=16+8=24时, int sum = 0，对应的子集为[1, 1, 2, 2, 2]的前两位
                 * 当 j=0 时，i&(1<<0) = 0 
                 * 当 j=1 时，i&(1<<1) = 0 
                 * 当 j=2 时，i&(1<<2) = 0 
                 * 当 j=3 时，i&(1<<3) = 1, sum = sum + nums[j] = 0 +1 = 1
                 * 当 j=4 时，i&(1<<4) = 1, sum = sum + nums[j] = 1 +1 = 2 = target
                 * 则ok_subset.push_back(i) = ok_subset.push_back(24) ---> ok_subset.push_back([1, 1, 0, 0, 0]) 
                 */ 
                if (i & (1 << j))
                {
                    sum += nums[j];
                }
            }
            if (sum == side_len)
            {
                ok_subset.push_back(i);
            }
        }
        for (int i = 0; i < ok_subset.size(); i++)
        {
            for (int j = i + 1; j < ok_subset.size(); j++)
            {
                if ((ok_subset[i] & ok_subset[j]) == 0)
                {
                    ok_half.push_back(ok_subset[i] | ok_subset[j]);
                }
            }
        }
        for (int i = 0; i < ok_half.size(); i++)
        {
            for (int j = i + 1; j < ok_half.size(); j++)
            {
                if ((ok_half[i] & ok_half[j]) == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
