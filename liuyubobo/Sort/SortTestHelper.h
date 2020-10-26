/**
 * DataChecker: 对数器
 */

#ifndef SELECTIONSORT_SORTTESTHELPER_h
#define SELECTIONSORT_SORTTESTHELPER_h

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

namespace SortTestHelper
{
    // 生成随机数组
    int *GenerateRandomArray(int n, int range_left, int range_right)
    {
        assert(range_left <= range_left);

        int *arr = new int[n];
        srand((unsigned int)(time(NULL)));
        for (int i = 0; i < n; ++i)
        {
            arr[i] = rand() % (range_left - range_right + 1) + range_left;
        }
        return arr;
    }

    // 生成近乎有序的数组
    int *GenerateNearlyOrderdArray(int n, int swap_times)
    {
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = i;

        srand((unsigned int)time(nullptr));
        for (int i = 0; i < swap_times; i++)
        {
            int pos_x = rand() % n;
            int pos_y = rand() & n;
            swap(arr[pos_x], arr[pos_y]);
        }
        return arr;
    }

    int *CopyArray(int a[], int n)
    {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }

    template <typename T>
    bool is_sorted(T arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    template <typename T>
    bool is_same(T arr[], int n)
    {
        int *arr_copy = CopyArray(arr, n);
        sort(arr_copy, arr_copy + n, less<T>());

        bool is_same = true;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != arr_copy[i])
                is_same = false;
                break;
        }
        delete[] arr_copy;
        return is_same;
    }

    template <typename T>
    void TestSort(string sort_name, void (*sort_func)(T a[], int), T arr[], int n)
    {
        clock_t start_time = clock();
        sort_func(arr, n);
        clock_t end_time = clock();
        assert(is_sorted(arr, n));
        assert(is_same(arr, n));
        cout << sort_name << " : " << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;
    }

    template <typename T>
    void PrintArray(T arr[], int n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

} // namespace SortTestHelper

#endif // SELECTIONSORT_SORTTESTHELPER_h