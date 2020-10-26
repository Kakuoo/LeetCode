#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int partition(vector<int> &nums, int left, int right)
// {
//     swap(nums, randRange(left, right), right);  // 随机选择一个数作为基准值，nums[hi] 就是基准值
//     int i, j;
//     for (i = left, j = left; j < right; ++j)
//     {
//         if (nums[j] <= nums[right])
//             swap(nums, i++, j);
//     }
//     swap(nums, i, j);
//     return i;
// }

int partition2_1(vector<int> &nums, int left, int right)
{
    int pivot = nums[left]; // 取基准值
    int mark = left;        // mark初始化为起始下标
    for (int i = left + 1; i <= right; ++i)
    {
        if (nums[i] < pivot)
        {
            // 小于基准值则mark+1， 并交换位置
            mark++;
            swap(nums[mark], nums[i]);
        }
    }
    // 基准值与mark对应元素调换位置
    swap(nums[left], nums[mark]);
    return mark;
}

int partition2_2(vector<int> &nums, int left, int right)
{
    int pivot = nums[right]; // 取右边为基准值
    int mark = left - 1;
    for (int i = left; i < right; ++i)
    {
        if (nums[i] < pivot)
        {
            mark++;
            swap(nums[mark], nums[i]);
        }
    }
    swap(nums[mark + 1], nums[right]);
    return (mark + 1);
}


int partition3(vector<int> &nums, int left, int right)
{
    int pivot = nums[left]; // 将left作为基准
    while (left < right)
    {
        while (left < right && nums[right] >= pivot)
            right--;
        nums[left] = nums[right];
        while (left < right && nums[left] <= pivot)
            left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}


void QuickSort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        // if (left >= right)
        //     return;
        int pivot_idx = partition3(nums, left, right);
        QuickSort(nums, left, pivot_idx - 1);
        QuickSort(nums, pivot_idx + 1, right);
    }
}

void display(vector<int> &nums)
{
    for (auto e : nums)
    {
        cout << e << ' ';
    }
    cout << endl;
}

bool check(vector<int> &nums, vector<int> &sorted_nums)
{
    vector<int> copy = nums;
    sort(copy.begin(), copy.end());
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != sorted_nums[i])
        {
            return false;
        }
    }
    return true;
}

void SelectSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] > nums[j])
                swap(nums[i], nums[j]);
        }
    }
}

void InsertionSort(vector<int> &nums)
{
    for (int i = 1, j, value; i < nums.size(); ++i)
    {
        value = nums[i];
        for (j = i - 1; j >= 0 && nums[j] > value; j--)
        {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = value;
    }
}

void ShellSort(vector<int> &nums)
{
    for (int gap = nums.size() >> 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < nums.size(); i++)
        {
            for (int j = i; j > gap - 1; j -= gap)
            {
                if (nums[j - gap] > nums[j])
                    swap(nums[j - gap], nums[j]);
                else
                    break;
            }
        }
    }
}

void merge_two_sub_vec(vector<int> &nums, int left, int mid, int right)
{
    vector<int> copy = nums;
    int i = left, j = mid + 1, k = left;
    while (k <= right)
    {
        if (i > mid)
        {
            nums[k++] = copy[j++];
        }
        else if (j > right)
        {
            nums[k++] = copy[i++];
        }
        else if (copy[i] <= copy[j])
        {
            nums[k++] = copy[i++];
        }
        else if (copy[i] > copy[j])
        {
            nums[k++] = copy[j++];
        }
    }
}

void MergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);
    merge_two_sub_vec(nums, left, mid, right);
}

void test_nums(vector<int> &nums)
{
    display(nums);
    cout << "============" << endl;
    QuickSort(nums, 0, 7);
    // ShellSort(nums);
    // QuickSort(nums5, 0, nums5.size() - 1);
    cout << "============" << endl;
    display(nums);
}

int main()
{
    vector<int> nums = {2, 1, 7, 9, 5, 8};
    vector<int> nums2 = {9, 8, 7, 1, 5, 3};
    vector<int> nums3 = {1, 2, 3, 7, 8, 9};
    vector<int> nums4 = {5, 2, 7, 8, 3, 0, 6, 4};
    vector<int> nums5 = {5, 2, 7, 8, 3, 5, 6, 4};
    vector<int> nums6 = {5, 2, 6, 8, 6, 0, 6, 4};

    test_nums(nums4);
    // vector<int> copy = nums5;
    // cout << "排序结果正确(true)/错误(false)；" << check(copy, nums5) << endl;
    return 0;
}