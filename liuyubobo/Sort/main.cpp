#include "SortTestHelper.h"
#include "Student.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "../Heap/MaxHeap.h"

using namespace std;

template <typename T>
void HeapSort_1(T arr[], int n)
{
    MaxHeap<T> max_heap = MaxHeap<T>(n);
    for (int i = 0; i < n; i++)
    {
        max_heap.insert(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = max_heap.extract_max();
    }
}

template <typename T>
void HeapSort_2(T arr[], int n)
{
    MaxHeap<T> max_heap = MaxHeap<T>(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = max_heap.extract_max();
    }
}

// 原地堆排序
// 从0开始索引

template <typename T>
void __shift_down(T arr[], int n, int k)
{
    while (2 * k + 1 < n)   // 左孩子不越界
    {
        int swap_idx = 2 * k + 1;
        if (swap_idx + 1 < n && arr[swap_idx + 1] > arr[swap_idx])
        {
            swap_idx += 1;
        }

        if (arr[k] >= arr[swap_idx])
            break;
        swap(arr[swap_idx], arr[k]);
        k = swap_idx;
    }
}

template <typename T>
void HeapSort_3(T arr[], int n)
{
    // Heapify 将arr数组构建成堆
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        __shift_down(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        __shift_down(arr, i, 0);
    }
}



int main()
{
    // 改进测试用例
    int n = 100000;
    int *arr = SortTestHelper::GenerateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::CopyArray(arr, n);
    int *arr3 = SortTestHelper::CopyArray(arr, n);
    int *arr4 = SortTestHelper::CopyArray(arr, n);
    int *arr5 = SortTestHelper::CopyArray(arr, n);
    int *arr6 = SortTestHelper::CopyArray(arr, n);

    cout << "随机数组：元素数量 " << n << " 个" << endl;
    SortTestHelper::TestSort("InsertionSort", InsertionSort, arr, n);
    SortTestHelper::TestSort("MergeSort", MergeSort, arr2, n);
    SortTestHelper::TestSort("QuickSort", QuickSort, arr3, n);
    SortTestHelper::TestSort("HeapSort_1", HeapSort_1, arr4, n);
    SortTestHelper::TestSort("HeapSort_2", HeapSort_2, arr5, n);
    SortTestHelper::TestSort("HeapSort_3", HeapSort_3, arr6, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    cout << endl;

    int swap_times = 1000;
    arr = SortTestHelper::GenerateNearlyOrderdArray(n, swap_times);
    arr2 = SortTestHelper::CopyArray(arr, n);
    arr3 = SortTestHelper::CopyArray(arr, n);
    arr4 = SortTestHelper::CopyArray(arr, n);
    arr4 = SortTestHelper::CopyArray(arr, n);
    arr5 = SortTestHelper::CopyArray(arr, n);
    arr6 = SortTestHelper::CopyArray(arr, n);

    cout << "近乎有序的数组：元素数量 " << n << " 个"
         << "swap_times: " << swap_times << " 个" << endl;
    SortTestHelper::TestSort("InsertionSort", InsertionSort, arr, n);
    SortTestHelper::TestSort("MergeSort", MergeSort, arr2, n);
    SortTestHelper::TestSort("QuickSort", QuickSort, arr3, n);
    SortTestHelper::TestSort("HeapSort_1", HeapSort_1, arr4, n);
    SortTestHelper::TestSort("HeapSort_2", HeapSort_2, arr5, n);
    SortTestHelper::TestSort("HeapSort_3", HeapSort_3, arr6, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    cout << endl;

    arr = SortTestHelper::GenerateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::CopyArray(arr, n);
    arr3 = SortTestHelper::CopyArray(arr, n);
    arr4 = SortTestHelper::CopyArray(arr, n);
    arr5 = SortTestHelper::CopyArray(arr, n);
    arr6 = SortTestHelper::CopyArray(arr, n);

    cout << "含有大量相同元素的数组：元素数量 " << n << " 个" << endl;
    SortTestHelper::TestSort("InsertionSort", InsertionSort, arr, n);
    SortTestHelper::TestSort("MergeSort", MergeSort, arr2, n);
    SortTestHelper::TestSort("QuickSort", QuickSort, arr3, n);
    SortTestHelper::TestSort("HeapSort_1", HeapSort_1, arr4, n);
    SortTestHelper::TestSort("HeapSort_2", HeapSort_2, arr5, n);
    SortTestHelper::TestSort("HeapSort_3", HeapSort_3, arr6, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    cout << endl;

    // SortTestHelper::PrintArray(arr, n);

    // 简单测试用例
    // int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // float b[5] = {3.6, 2.5, 1.0, 123, 5.6};
    // InsertionSort(b, 5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;

    // string str[4] = {"A", "C", "B", "D"};
    // SelectionSort(str, 4);
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << str[i] << " ";
    // }
    // cout << endl;

    // Student d[4] = {{"Li Ming", 90}, {"Zhang Hua", 100}, {"ABC", 95}, {"Wang", 80}};
    // SelectionSort(d, 4);
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << d[i];
    // }
    // cout << endl;

    return 0;
}