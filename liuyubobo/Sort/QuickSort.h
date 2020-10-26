#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H

#include "InsertionSort.h"

template <typename T>
int partition(T arr[], int left, int right)
{
    swap(arr[rand() % (right - left + 1) + left], arr[left]);

    T pivot = arr[left];
    int mark = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[mark + 1], arr[i]);
            mark++;
        }
    }
    swap(arr[mark], arr[left]);
    return mark;
}

template <typename T>
int partition2(T arr[], int left, int right)
{
    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    T pivot = arr[left];

    int i = left + 1, j = right;
    while (true)
    {
        while (i <= right && arr[i] < pivot)
            i++;
        while (j >= left + 1 && arr[j] > pivot)
            j--;
        if (i > j)
            break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[j], arr[left]);
    return j;
}

template <typename T>
void __QuickSort(T arr[], int left, int right)
{
    if (left >= right)
        return;

    int pos = partition(arr, left, right);
    __QuickSort(arr, left, pos - 1);
    __QuickSort(arr, pos + 1, right);
}

template <typename T>
void QuickSort(T arr[], int n)
{
    srand((unsigned int)(time(nullptr)));
    __QuickSort(arr, 0, n - 1);
}

template <typename T>
void __QuickSort3Ways(T arr[], int left, int right)
{
    int INSERTION_SORT_THRESHOLD = 15;
    if (right - left <= INSERTION_SORT_THRESHOLD)
    {
        InsertionSort(arr, left, right);
        return;
    }

    // partition部分代码
    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    T pivot = arr[left];

    int left_pos = left;   // arr[left + 1, ..., left_pos] < pivot
    int right_pos = right; // arr[right_pos, ..., right] > pivot
    int i = left + 1;      // arr[left + 1, ..., i) == pivot  前闭后开区间
    while (i < right_pos)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[left_pos + 1]);
            left_pos++;
            i++;
        }
        else if (arr[i] > pivot)
        {
            swap(arr[i], arr[right_pos - 1]);
            right_pos--;
        }
        else if (arr[i] == pivot)
        {
            i++;
        }
    }
    swap(arr[left_pos], arr[left]);

    __QuickSort3Ways(arr, left, left_pos - 1);
    __QuickSort3Ways(arr, right_pos, right);
}

template <typename T>
void QuickSort3Ways(T arr[], int n)
{
    srand((unsigned int)time(nullptr));
    __QuickSort3Ways(arr, 0, n - 1);
}

#endif // QUICKSORT_QUICKSORT_H