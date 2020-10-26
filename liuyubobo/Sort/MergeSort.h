
#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

#include "InsertionSort.h"

template <typename T>
void __MergeTwoSubVec(T arr[], int left, int mid, int right)
{
    // aux == auxiliary 辅助的空间
    T aux[right - left + 1];
    for (int i = left; i <= right; i++)
    {
        aux[i - left] = arr[i];
    }
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++)
    {
        if (i > mid)
        {
            arr[k] = aux[j - left];
            j++;
        }
        else if (j > right)
        {
            arr[k] = aux[i - left];
            i++;
        }
        else if (aux[i - left] <= aux[j - left])
        {
            arr[k] = aux[i - left];
            i++;
        }
        else if (aux[i - left] > aux[j - left])
        {
            arr[k] = aux[j - left];
            j++;
        }
    }
}

template <typename T>
void __MergeSort(T arr[], int left, int right)
{
    // if (left >= right)
    //     return;

    // 当递归至数组内元素数量较少时，可以转而使用插入排序
    int INSERTION_SORT_THRESHOLD = 15;
    if (right - left <= INSERTION_SORT_THRESHOLD)
    {
        InsertionSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    __MergeSort(arr, left, mid);
    __MergeSort(arr, mid + 1, right);
    // 如果nums[mid] <= nums[mid + 1]，且已知数组前半部分，后半部分分别有序，则可以不需要归并
    if (arr[mid] > arr[mid + 1])
        __MergeTwoSubVec(arr, left, mid, right);
}

template <typename T>
void MergeSort(T arr[], int n)
{
    __MergeSort(arr, 0, n - 1);
}


// 自底向上的归并排序 Bottom-Up
template <typename T>
void MergeSortBU(T arr[], int n)
{
    for (int sz = 1; sz <= n; sz += sz)
    {
        for (int i = 0; i + sz < n; i += sz + sz)
        {
            // 对 arr[i, ..., i+sz-1] 和 arr[i+sz, ..., i+2*sz-1] 进行归并
            __MergeTwoSubVec(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
        }
    }
}

#endif  // MERGESORT_MERGESORT_H

