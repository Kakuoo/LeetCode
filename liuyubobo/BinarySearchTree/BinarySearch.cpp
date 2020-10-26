/**
 * 二分查找
 * 对于有序序列，才能使用二分查找法（排序的作用）
 * 
 * 特别的：
 * 有floor()， ceil()方法
 * 
 */

// 迭代方法
template <typename T>
int binary_search(T arr[], int n, T target)
{
    int left = 0, right = n - 1; // 在[left, right]之中查找target
    while (l <= right)
    {
        // int mid = (left + right) / 2;  // 就是这句话让二分查找思想的诞生，和最后真正的实现之间，时间相差了二十年
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
