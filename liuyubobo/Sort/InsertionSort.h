#ifndef INSERTIONSORT_INSERTIONSORT_H
#define INSERTIONSORT_INSERTIONSORT_H

using namespace std;

template <typename T>
void SelectionSort(T arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        // 寻找[i, n)区间里的最小值
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

template <typename T>
void InsertionSort(T arr[], int n)
{
    for (int i = 1, j; i < n; i++)
    {
        T value = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > value; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = value;
    }
}

template <typename T>
void InsertionSort(T arr[], int left, int right)
{
    for (int i = left + 1, j; i <= right; i++)
    {
        T value = arr[i];
        for (j = i - 1; j >= left && arr[j] > value; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = value;
    }
}

#endif  // INSERTIONSORT_INSERTIONSORT_H