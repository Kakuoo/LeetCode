/** 
 * 二分查找——折半查找
 * 首先，假设表中元素按升序排列，将表中间位置的关键字和查找关键字比较
 * 1.如果两者相等，则查找成功
 * 2.否则利用中间位置将表分成前、后两个子表：
 *  1).如果中间位置的关键字大于查找关键字，则进一步查找前一子表
 *  2).否则进一步查找后一子表
 * 重复以上过程，直到找到满足条件的记录，则查找成功，或直到子表不存在为止，此时查找不成功
 * 
 * 
 * 特别的：
 * 有floor()， ceil()方法
 * 
 */

/**
 * 有分治思想的问题易于使用循环解决
 * 有回溯思想的问题易于使用递归解决(例如：N皇后问题)
 */

#include <vector>
using namespace std;

// 模板template方式

// 迭代方法
template <typename T>
int binary_search(T arr[], int n, T target)
{
    int left = 0, right = n - 1; // 在[left, right]之中查找target
    while (left <= right)
    {
        // int mid = (left + right) / 2;  // 就是这句话让二分查找思想1946年诞生，但第一个没有bug的出现于1962年，时间相差了十五年
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
    }
    return -1;
}

// 递归方法
// 递归方法相对于迭代方法的性能略差
template <typename T>
int binary_search(T arr[], int left, int right, T target)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;
    if (target == arr[mid])
    {
        return mid;
    }
    else if (target < arr[mid])
    {
        return binary_search(arr, left, mid - 1, target);
    }
    else if (target > arr[mid])
    {
        return binary_search(arr, mid + 1, right, target);
    }
}


// 经典vector方式

// 递归方式
bool binary_search(vector<int> &sort_array, int begin, int end, int target)
{
    if (begin > end)
    {
        return false;
    }
    // int mid = (begin + end) / 2;
    int mid = begin + (end - begin) / 2;
    if (target == sort_array[mid])
    {
        return true;
    }
    else if (target < sort_array[mid])
    {
        return binary_search(sort_array, begin, mid - 1, target);
    }
    else if (target > sort_array[mid])
    {
        return binary_search(sort_array, mid + 1, end, target);
    }
}

// 循环方式
bool binary_search(vector<int> &sort_array, int target)
{
    int begin = 0;
    int end = sort_array.size() - 1;
    while (begin <= end)
    {
        // int mid = (begin + end) / 2;
        int mid = begin + (end - begin) / 2;
        if (target == sort_array[mid])
        {
            return true;
        }
        else if (target < sort_array[mid])
        {
            end = mid - 1;
        }
        else if (target > sort_array[mid])
        {
            begin = mid + 1;
        }
    }
    return false;
}

// 测试代码
vector<int> search_array(vector<int> &sort_array, vector<int> &random_array)
{
    vector<int> result;
    for (int i = 0; i < random_array.size(); i++)
    {
        int res = binary_search(sort_array, 0, sort_array.size() - 1, random_array[i]);
        // int res = binary_search(sort_array, random_array[i]);
        result.push_back(res);
    }
    return result;
}