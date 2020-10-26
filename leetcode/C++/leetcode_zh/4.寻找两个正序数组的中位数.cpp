/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() != 0 && nums2.size() == 0)
            return ComputeMedianNum(nums1);

        if (nums1.size() == 0 && nums2.size() != 0)
            return ComputeMedianNum(nums2);

        vector<int> nums(nums1.size() + nums2.size(), 0);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
                nums[k++] = nums1[i++];
            else
                nums[k++] = nums2[j++];
        }

        if (i < nums1.size())
            while (i < nums1.size())
                nums[k++] = nums[i++];
        if (j < nums2.size())
            while (j < nums2.size())
                nums[k++] = nums2[j++];

        return ComputeMedianNum(nums);
    }

private:
    double ComputeMedianNum(vector<int> &nums)
    {
        int n = nums.size();
        if (n % 2 == 0)
            return double(nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        else
            return double(nums[n / 2]);
    }
};

// 88ms runtime 12.68% 时间复杂度不符合要求
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nums;
        for (int e : nums1)
            nums.push_back(e);
        for (int e : nums2) 
            nums.push_back(e);

        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n % 2 == 0)
            return double(nums[n / 2 - 1] + nums[n / 2]) / 2;
        else
            return double(nums[n / 2]);
    }
};
// @lc code=end
