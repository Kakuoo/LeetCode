/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
#include <vector>
#include <set>
#include <cmath>
using namespace std;

// 使用 long long 解决溢出问题，测试样例： [0,2147483647], 1, 2147483647
// 找到 [v-t, ..., v, ..., v + t]中使lower_bound(v - t) <= v + t，即可实现差的绝对值在t的范围内
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        typedef long long ll;
        set<ll> record; // 红黑树，有序性，可以使用lower_bound
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = record.lower_bound((ll)nums[i] - (ll)t);
            if (it != record.end() && *it <= (ll)nums[i] + (ll)t)
                return true;

            record.insert(nums[i]);

            if (record.size() == k + 1)
                record.erase(nums[i - k]);
        }
        return false;
    }
};
// @lc code=end
