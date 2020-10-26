#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort
void BubbleSort(vector<int> &nums)
{
    bool is_changed = true;
    for (int i = 0; i < nums.size() - 1 && is_changed; ++i)
    {
        is_changed = false;
        for (int j = 0; j < nums.size() - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                is_changed = true;
            }
        }
    }

    // for (int i = 0; i < nums.size() - 1; ++i)
    // {
    //     bool is_changed = false;
    //     for (int j = 0; j < nums.size(); ++j)
    //     {
    //         if (nums[j] > nums[j + 1])
    //         {
    //             swap(nums[j], nums[j + 1]);
    //             is_changed = true;
    //         }
    //     }
    //     if (!is_changed)
    //         break;
    // }

    // for (int i = 0; i < nums.size() - 1; ++i)
    // {
    //     for (int j = 0; j < nums.size(); ++j)
    //     {
    //         if (nums[j] > nums[j + 1])
    //             swap(nums[j], nums[j + 1]);
    //     }
    // }
}

// SelectionSort
void SelectionSort(vector<int> nums)
{
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[min_idx] > nums[j])
            {
                min_idx = j;
            }
        }
        swap(nums[min_idx], nums[i]);
    }

    // for (int i = 0; i < nums.size() - 1; ++i)
    // {
    //     for (int j = i + 1; j < nums.size(); ++j)
    //     {
    //         if (nums[i] > nums[j])
    //             swap(nums[i], nums[j]);
    //     }
    // }
}

// InsertionSort
void InsertionSort(vector<int> &nums)
{
    for (int i = 1, value, j; i < nums.size(); ++i)
    {
        value = nums[i];
        for (j = i - 1; j >= 0 && value < nums[j]; --j)
        {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = value;
    }

    // for (int i = 1; i < nums.size(); ++i)
    // {
    //     for (int j = i; j >= 1; --j)
    //     {
    //         if (nums[j - 1] > nums[j])
    //             swap(nums[j], nums[j - 1]);
    //         else
    //             break;
    //     }
    // }
}

void InsertionSort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] > nums[j])
                swap(nums[j], nums[j]);
            else
                break;
        }
    }
}

void ShellSort(vector<int> &nums)
{
    int h = 1;
    int h_bak = 1;
    while (h <= nums.size() / 3)
    {
        h_bak = h;
        h = h * 3 + 1;
    }

    for (int gap = h_bak; gap > 0; gap = (gap - 1) / 3)
    {
        for (int i = gap; i < nums.size(); i++)
        {
            for (int j = i - gap; j >= 0; j -= gap)
            {
                if (nums[j] > nums[i])
                    swap(nums[j], nums[i]);
                else
                    break;
            }
        }
    }
}

template <typename T>
void InsertionSort(T arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        T value = arr[i];
        for (int j = i - 1; j >= left; j--)
        {
            if (arr[j] > value)
                arr[j + 1] = arr[j];
        }
        arr[j + 1] = value;
    }
}

template <typename T>
void MergeTwoSubVec__(T arr[], int left, int mid, int right)
{
    T aux[right - left + 1];
    for (int i = left; i <= right; i++)
    {
        aux[i - left] = arr[i];
    }

    int i = left;
    int j = mid + 1;
    for (int k = left; k <= right; k++)
    {
        if (i > mid)
        {
            arr[k] = aux[j++ - left];
        }
        else if (j > right)
        {
            arr[k] = aux[i++ - left];
        }
        else if (aux[i - left] <= aux[j - left])
        {
            arr[k] = aux[i++ - left];
        }
        else if (aux[i - left] > aux[j - left])
        {
            arr[k] = aux[j++ - left];
        }
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

template <typename T>
void MergeSort__(T arr[], int left, int right)
{
    // if (left >= right)
    //     return;

    int INSERTION_SORT_THRESHOLD = 15;
    if ((right - left) <= INSERTION_SORT_THRESHOLD)
    {
        InsertionSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) >> 1;
    MergeSort__(arr, left, mid);
    MergeSort__(arr, mid + 1, right);

    if (arr[mid] > arr[mid + 1])
        MergeTwoSubVec(arr, left, mid, right);
}

template <typename T>
void MergeSort(T arr[], int arr_size)
{
    MergeSort__(arr, 0, arr_size - 1);
}

// 单向循环
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
            swap(arr[i], arr[mark + 1]);
            mark++;
        }
    }

    swap(arr[mark], arr[left]);
    return mark;
}

// 双向循环
template <typename T>
int partition2(T arr[], int left, int right)
{
    swap(arr[rand() % (right - left + 1) + left], arr[left]);

    T pivot = nums[left];
    int i = left + 1;
    int j = right;
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
int partition(T nums[], int left, int right)
{
    swap(nums[left], nums[rand() % (right - left + 1) + left]);

    T pivot = nums[left];
    int mark = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (nums[i] < pivot)
        {
            swap(nums[i], nums[mark + 1]);
            mark++;
        }
    }

    swap(nums[left], nums[mark]);
    return mark;
}

template <typename T>
int partition(vector<T> &nums, int left, int right)
{
    swap(nums[left], nums[rand() % (right - left + 1) + left]);

    T pivot = nums[left];
    int i = left + 1;
    int j = right;
    while (true)
    {
        while (i <= right && nums[i] < pivot)
            i++;
        while (j >= left + 1 && nums[j] > pivot)
            j--;

        if (i > j)
            break;

        swap(nums[i], nums[j]);
        i++;
        j--;
    }

    swap(nums[j], nums[left]);
    return j;
}

template <typename T>
void QuickSort__(T arr[], int left, int right)
{
    if (left >= right)
        return;

    int pivot_idx = partition(arr, left, right);
    QuickSort__(nums, left, pivot_idx - 1);
    QuickSort__(nums, pivot_idx + 1, right);
}

template <typename T>
void QuickSort(T arr[], int n)
{
    srand((unsigned int)(time(nullptr)));
    QuickSort__(arr, 0, n - 1);
}


void MergeSort(vector<int> &nums)
{
    if (nums.size() < 2)
        return;

    int mid = nums.size() / 2;
    vector<int> sub_vec1;
    vector<int> sub_vec2;
    for (int i = 0; i < mid; i++)
        sub_vec1.push_back(nums[i]);
    for (int i = mid + 1; i < nums.size(); i++)
        sub_vec2.push_back(nums[i]);
    
    MergeSort(sub_vec1);
    MergeSort(sub_vec2);
    nums.clear();
    MergeTwoSubVec(sub_vec1, sub_vec2, nums); 
}

void MergeTwoSubVec(vector<int> &sub_vec1, vector<int> &sub_vec2, vector<int> &nums)
{
    int i = 0;
    int j = 0;
    while (i < sub_vec1.size() && j < sub_vec2.size())
    {
        if (sub_vec1[i] <= sub_vec2[j])
            nums.push_back(sub_vec1[i++]);
        else
            nums.push_back(sub_vec2[j++]);
    }

    for ( ; i < sub_vec1.size(); i++)
        nums.push_back(sub_vec1[i]);
    for ( ; j < sub_vec2.size(); j++)
        nums.push_back(sub_vec2[j]);
}

template <typename T>
void TotalMergeSort(T arr[], int n)
{
    MergeSort(arr, 0, n - 1);
}

template <typename T>
void MergeSort(T arr[], int left, int right)
{
    int INSERTION_THRESHOLD = 15;
    if (right - left <= INSERTION_THRESHOLD)
    {
        InsertionSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    if (arr[mid] > arr[mid + 1])
        MergeTwoSubVec(arr, left, mid, right);
}

template <typename T>
void InsertionSort(T arr[], int left, int right)
{
    for (int i = 1; i < right; i++)
    {
        T value = arr[i];
        for (int j = i - 1; j >= left; j--)
        {
            if (arr[j] > arr[i])
                arr[j + 1] = arr[j];
        }
        arr[j + 1] = value;
    }
}

template<typename T>
void MergeTwoSubVec(T arr[], int left, int mid, int right)
{
    T aux[right - left + 1];
    for (int i = left; i <= right; i++)
        aux[i - left] = arr[i];

    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++)
    {
        if (i > mid)
            arr[k] = aux[j++ - left];
        else if (j > right)
            arr[k] = aux[i++ - left];
        else if (aux[i - left] <= aux[j - left])
            arr[k] = aux[i++ - left];
        else if (aux[i - left] > aux[j - left])
            arr[k] = aux[j++ - left];
    }
}


void QucikSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    int pivot = partition(nums, left, right);
    QucikSort(nums, left, pivot - 1);
    QucikSort(nums, pivot + 1, right);
}

int partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[right];
    int mark = left;
    for (int i = left; i < right; i++)
    {
        if (nums[i] < pivot)
        {
            swap(nums[i], nums[mark]);
            mark++;
        }
    }
    
    swap(nums[mark], nums[right]);
    return mark;
}

int partition2(vector<int> &nums, int left, int right)
{
    int pivot = nums[left];
    int mark = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (nums[i] < pivot)
            swap(nums[i], nums[++mark]);
    }

    swap(nums[mark], nums[left]);
    return mark;
} 

int partition3(vector<int> &nums, int left, int right)
{
    int pivot = nums[right];
    int mark = left - 1;
    for (int i = left; i < right; i++)
    {
        if (nums[i] < pivot)
            swap(nums[++mark], nums[i]);
    }

    swap(nums[++mark], nums[right]);
    return mark;
}

