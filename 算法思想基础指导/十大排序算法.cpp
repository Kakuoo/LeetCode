/**
 * 排序中心思想：
 * 
 * 根据具体问题所处的情况讨论具体的方法
 * 
 * 数组有何特征：
 * 1.是否包含大量重复元素？  // 三路快排
 *      例如：若此数据中都是独特的，则普通快排就足够了
 * 2.是否大量数据都距离正确位置很近？ // 插入排序
 *      例如：银行业务，按照发生时间排序，大量业务完成时存入库中，近乎有序
 * 3.是否数据的取值范围非常有限？  // 计数排序
 *      例如：对学生高考成绩排序，满分750分
 * 4.对排序是否有额外要求？
 *      例如：快排不稳定，归并排序可能更好
 * 5.数据具体的存储状况？
 *      例如：快排依赖于数据的随机存取，若数据为链表结构，快排可能就不适用了，归并排序更为合适
 * 6.数据大小是否可以装载在内存中？
 *      例如：数据量很大，内存很小，不足以装载在内存里，需要使用 外部排序算法（例如：多路归并TimSort()）
 * 7.大量数据都是否近乎有序？   // 快排随机选取标定点  
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

/**
1.基本的排序算法

冒泡排序（Bubble Sort）：基本不用，太慢
选择排序：基本不用，不稳
插入排序（Insertion Sort）：样本小且基本有序时效率较高

2.常考的排序算法

希尔排序
归并排序（Merge Sort）
快速排序（Quick Sort）

拓扑排序（Topological Sort）

3.其他排序算法

堆排序（Heap Sort）
桶排序（Bucket Sort)
计数排序
基数排序
*/

/**
 * 冒泡排序
 * 
 * 时刻保持右端的数组是有序的
 */

// 优化代码简洁版
void BubbleSort(vector<int> &nums)
{
    bool is_change = true; //定义is_change，用于标记每轮遍历中是否发生了交换
    for (int i = 0; i < nums.size() - 1 && is_change; ++i)
    {
        is_change = false; //每轮遍历开始，将is_change设置为 false
        for (int j = 0; j < nums.size() - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                is_change = true;
            }
        }
    }
}

// 优化版
void BubbleSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        bool is_change = false;
        for (int j = 0; j < nums.size() - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                is_change = true;
            }
        }
        if (!is_change)
            break;
    }
}

// 直观版
void BubbleSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

/**
 * 选择排序
 * 
 * 思想：
 * 每次从待排序的数字中找出最值，将最值放在待排序数组的前面
 * n个数字只需要重复n-1趟
 * 
 * 简单且实用，不稳定
 */

// 更优化版
// 在优化版的基础上，同时找到数组中的最小值和最大值，同时进行放置操作

// 优化版 避免了多次swap
void SelectSort(vector<int> &nums)
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
        swap(nums[i], nums[min_idx]);
    }
}

// 直观版
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

/**
 * 插入排序
 * 
 * 思想：
 * 不断的将待排序的数插入到已经排好序的部分中
 * 可以提前终止内层循环
 * 
 * 时刻保持前端的数组是有序的
 * 对于基本有序的数组最好用 
 */

// 简洁优化版
void InsertionSort(vector<int> &nums)
{
    for (int i = 1, j, value; i < nums.size(); ++i)
    {
        value = nums[i];
        for (j = i - 1; j >= 0 && nums[j] > value; --j)
        {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = value;
    }
}

// 优化版，不够简洁
void InsertionSort(vector<int> &nums)
{
    for (int i = 1, j, value; i < nums.size(); ++i)
    {
        value = nums[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (nums[j] > value)
                nums[j + 1] = nums[j]; // 平移左边的有序数据
            else
                break;
        }
        nums[j + 1] = value; //插入数据
    }
}

// 直观版
void InsertionSort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (nums[j] > nums[i])
                swap(nums[j], nums[i]);
            else
                break;
        }
    }
}

/**
 * 对于10w个随机数的数组进行排序，
 * 直观版的InsertionSort算法用时135s
 * 优化版的SelectionSort算法用时为7.725s
 * 优化版的InsertionSort算法用时为4.594s
 */

/**
 * 对于近乎有序的10w个数的数组进行排序
 * 直观版的InsertionSort算法用时0.118s
 * 优化版的SelectionSort算法用时为7.731s
 * 优化版的InsertionSort算法用时为0.00215s
 * 
 * 对于近乎有序的数组进行排序，插入排序的性能甚至超过了nlogn复杂度的排序算法
 */

/**
 * 希尔排序
 * 
 * 可由插入排序改编得到
 * 例如：使用gap = 4的插入排序排完一遍，再以gap = 2的插入排序排完一遍
 * 最后必须再使用gap = 1的插入排序完成一遍
 * 
 * 优势：
 * 在间隔较大时，元素移动的次数较少，在间隔较少时，例如为1时所需移动的距离就比较短
 * 比普通的插入排序效率高
 * 
 * 劣势：
 * 跳着排序，不稳定
 * 
 * 工程上有的人说如果遇到问题先用希尔排序排一遍，如果效果较好，就不要再使用别的方法了
 */

// 举例：gap = 4时，下列序列可划分如下，分别对于每组相同索引的元素应用插入排序
// [9, 6, 11, 3, 5, 12, 8, 7, 10, 15, 14, 4, 1, 13, 2]
// [9, 6, 11, 3], [5, 12, 8, 7], [10, 15, 14, 4], [1, 13, 2]
// 

// knuth序列 h = 1; h = 3*h + 1
// 修改了h和j的表达方式
void ShellSort(vector<int> &nums)
{
    int h = 1;
    int h_res = 1;
    while (h <= nums.size() / 3)
    {
        h_res = h;
        h = h * 3 + 1;
    }

    for (int gap = h_res; gap > 0; gap = (gap - 1) / 3)
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

void ShellSort(vector<int> &nums)
{
    int h = 1;
    while (h <= nums.size() / 3)
    {
        h = h * 3 + 1;
    }

    for (int gap = h; gap > 0; gap = (gap - 1) / 3)
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

// 修改了j的表达方式
void ShellSort(vector<int> &nums)
{
    for (int gap = nums.size() >> 2; gap > 0; gap >> 1)
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

// gap为 nums.size() >> 2的希尔排序
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

/**
 * 归并排序
 * 
 * Java中：
 * 纯数字型（numerical）数组排序可用快排
 * 调用：
 * array.sort() ---> DualPivotQuickSort() 双轴快排
 * 
 * 对象（object）排序一般要求稳定
 * 调用: 
 * 若未提供Comparator（比较器），则默认调用array.sort()
 * 否则：使用 LegacyMergeSort()，或者根据 userRequested，使用 TimSort()
 * 
 * TimSort()是改进的归并排序
 * 算法思想：
 * 多路归并，将待排序数组分成多块，然后直接两两归并
 * 若给定值 < MIN_RANGE，即数组较小的情况:
 *      使用 binarySort()，二分插入排序
 * 否则：
 *      使用 TimSort()，将其中每一小块按照二分插入排好顺序，再将所有块两两归并
 * 
 * 
 */

// 方法一
void MergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    // int mid = (left + right) / 2
    int mid = left + (right - left) / 2; // 相比于上式要好，可以避免数值溢出
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);
    // 如果nums[mid] <= nums[mid + 1]，且已知数组前半部分，后半部分分别有序，则可以不需要归并
    if (nums[mid] > nums[mid + 1])
        merge_two_sub_vec(nums, left, mid, right);
}

void merge_two_sub_vec(vector<int> &nums, int left, int mid, int right)
{
    vector<int> copy = nums;
    int i = left, j = mid + 1;
    int k = left;
    while (k <= right)
    {
        if (i > mid) // 前两步与后两步的顺序不可颠倒
        {
            nums[k++] = copy[j++];
        }
        else if (j > right)
        {
            nums[k++] = copy[i++];
        }
        else if (copy[i] <= copy[j]) // 归并排序，稳定算法 <=
        {
            nums[k++] = copy[i++];
        }
        else if (copy[i] > copy[j])
        {
            nums[k++] = copy[j++];
        }
    }
}

// 方法二
void MergeSort_2(vector<int> &nums)
{
    if (nums.size() < 2)
        return;

    int mid = nums.size() / 2;
    vector<int> sub_vec1;
    vector<int> sub_vec2;
    for (int i = 0; i < mid; ++i)
    {
        sub_vec1.push_back(nums[i]);
    }
    for (int i = mid; i < nums.size(); ++i)
    {
        sub_vec2.push_back(nums[i]);
    }
    MergeSort_2(sub_vec1);
    MergeSort_2(sub_vec2);
    nums.clear();
    merge_sort_two_vec_2(sub_vec1, sub_vec2, nums);
}

void merge_sort_two_vec_2(vector<int> &sub_vec1, vector<int> &sub_vec2, vector<int> &nums)
{
    int i = 0;
    int j = 0;
    while (i < sub_vec1.size() && j < sub_vec2.size())
    {
        if (sub_vec1[i] <= sub_vec2[j])
        {
            nums.push_back(sub_vec1[i]);
            i++;
        }
        else
        {
            nums.push_back(sub_vec2[j]);
            j++;
        }
    }
    // 将sub_vec1或sub_vec2中剩余元素push进入vec中
    for (; i < sub_vec1.size(); ++i) // while (i++ != sub_vec1.size())
    {
        nums.push_back(sub_vec1[i]);
    }
    for (; j < sub_vec2.size(); ++j) // while (j++ != sub_vec2.size())
    {
        nums.push_back(sub_vec2[j]);
    }
}

// 方法三
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

// 方法四
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

/**
 * 快速排序
 * 
 * 工程上遇到任何问题都可以先试用快速排序排一遍
 * 
 * 为了避免快排在处理单调有序数列中复杂度过高的问题：
 * 
 * 1.Java中的DualPivotQuickSort（双轴排序），首先会判断数组是否单调递增或递减，
 * 如果是单调序列，则不用快速排序，直接使用MergeSort
 * 
 * 2.pivot选择从数组中随机选取，然后放在left或者right的位置上，再开始快速排序
 * 
 */

void QuickSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    int pivot_idx = partition2_1(nums, left, right);
    QuickSort(nums, left, pivot_idx - 1);
    QuickSort(nums, pivot_idx + 1, right);
}

// // 方法一 原理思想
// int partition1(vector<int> &nums, int left, int right)
// {
//     // swap(nums, randRange(left, right), right);  // 随机选择一个数作为基准值，nums[hi] 就是基准值
    
//     int i, j;
//     for (i = left, j = left; j < right; ++j)
//     {
//         if (nums[j] <= nums[right])
//             // swap_(nums, i++, j);
//     }
//     // swap_(nums, i, j);
//     return i;
// }

// 方法一 快排——单边循环
// 1.1  较好理解的版本
int partition1_1(vector<int> &nums, int left, int right)
{
    int pivot = nums[right]; // 取右边为基准值
    int mark = left;        // mark用于标记返回时的轴的下标位置
    for (int i = left; i < right; ++i)
    {
        if (nums[i] < pivot)
        {
            swap(nums[mark], nums[i]);
            mark++;
        }
    }

    swap(nums[mark], nums[right]);
    return mark;
}

// 1.2
int partition1_2(vector<int> &nums, int left, int right)
{
    int pivot = nums[left]; // 取左边为基准值，pivot为轴的值
    int mark = left;        // mark用于标记返回时的轴的下标位置
    for (int i = left + 1; i <= right; ++i)
    {
        if (nums[i] < pivot)
        {
            // 小于基准值则mark+1， 并交换位置
            mark++;  // 由于i从left + 1开始，所以此行在下一行的前面
            swap(nums[mark], nums[i]);
        }
    }

    // 基准值与mark对应元素调换位置
    swap(nums[left], nums[mark]);
    return mark;
}

// 1.3
int partition1_3(vector<int> &nums, int left, int right)
{
    int pivot = nums[right]; // 取右边为基准值
    int mark = left - 1;    // mark用于标记返回时的轴的下标位置
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

// 方法二 快排——双边循环：
/**
 * 双指针法
 * 
 * 此方法针对于类似nums有10w个数字，但是都位于[0, 10]之间，如果采用上述方法，
 * 则每次需要swap大量元素实现小于区和大于区的平移，过于复杂，故进行改进，平移过程类似下图：
 * [[小于区]...[大于区]...[待处理区]]
 * 
 * 下面的方法采用
 * [[小于等于区]...[待处理区]...[大于等于区]]，合理降低了时间复杂度，在面对此种情况时，更为高效
 * 
 */

// // 有问题的代码
// int partition2(vector<int> &nums, int left, int right)
// {
//     int pivot = nums[right];
//     int l = left;
//     int r = right - 1;
//     while (l < r)
//     {
//         while (l <= r && nums[l] <= pivot)
//             l++;
//         while (l <= r && nums[r] > pivot)
//             r--;
        
//         if (l < r)
//             swap_(nums, l, r);
//     }
//     swap_(nums, l, right);
//     return l;
// }

// void swap_(vector<int> &nums, int left, int right)
// {
//     int tmp = nums[left];
//     nums[left] = nums[right];
//     nums[right] = tmp;
// }

// // 有问题的代码
// int partition3(vector<int> &nums, int left, int right)
// {
//     int pivot = nums[left]; // 将left作为基准
//     while (left < right)
//     {
//         while (left < right && nums[left] <= pivot)
//             left++;

//         nums[right] = nums[left];

//         while (left < right && nums[right] >= pivot)
//             right--;

//         nums[left] = nums[right];
//     }

//     nums[left] = pivot;
//     return left;
// }

// 方法三
// 当随机选取pivot时，可以使快排的时间复杂度的期望为O(nlogn)，相比于在数组元素单调变化时，退化为O(n^2)，已经速度很快了

// 单向循环
template <typename T>
int partition3_1(T arr[], int left, int right)
{
    swap(arr[left + rand() % (right - left + 1)], arr[left]);

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

// 双向循环
template <typename T>
int partition3_2(T arr[], int left, int right)
{
    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    
    T pivot = arr[left];
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

    swap(arr[j], arr[left]);  // j 或者 (i - 1)
    return j;  // j 或者 (i - 1)
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

/**
 * 双轴快速排序
 * 
 * 分为四个区域，less区，mid区，more区，以及中台区
 * 两个轴（保证轴1小于轴2），小于轴1的放左边，大于轴1小于轴2的放中间，大于轴2的放右边
 * 
 * 算法思想：
 * 若数组长度小于QUICKSORT_THRESHOLD，则使用原始的sort算法（即单轴排序）
 * 否则：
 *      调用归并排序（TimSort），将数组分成多块
 *      如果 少于67块，则使用TimSort
 *      否则 说明该数组不是高度结构化的（高度结构化适合做归并排序），使用QuickSort代替MergeSort
 *      ...至此进入QuickSort排序...
 *      if 数组长度小于INSERTION_SORT_THRESHOLD，使用插入排序（此处是优化的插入排序——PairInsertionSort（双插入排序），即一次性插入两个数）
 *      否则 使用双轴快排
 *      ...至此进入双轴快排...
 *      通过中点向左向右分别移两格，找出五个点，并对五个点的值进行排序，五个点均不相等时，使用第二个和第四个点作为轴
 *      否则 说明五个点中有几个点相等，则使用第三个点进行快排，属于Dutch National flag（荷兰国旗问题）
 *      
 * 
 */

/**
 * 
 * 三轴快速排序
 * 
 * 算法思想：
 * 分为四个区，[[小于区]...[等于区]...[待处理区]...[大于区]]
 * 之后递归小于区，大于区两部分继续进行三路快速排序
 * 
 */

template <typename T>
void __QuickSort3Ways(T arr[], int left, int right)
{
    int INSERTION_SORT_THRESHOLD = 15;
    if (right - left <= INSERTION_SORT_THRESHOLD)
    {
        InsertionSort(arr, 0, n - 1);
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

/**
 * 堆排序
 * 
 * 拓展1：
 * 使用堆实现优先队列，在1,000,000个元素中选出前100名，
 * 相对于O(nlogn)的排序算法，只维护一个容量为100的堆，
 * 从n个数中取出m个数，复杂度可降低至O(nlogm)
 * 
 * 拓展2：
 * 对于多路归并问题，若分成d路归并，可维护一个容量为d的堆，
 * d的大小影响算法的复杂度，的越大，归并的层数越少，
 * 可每层归并的过程中需要比较的元素就最多
 * 极端情况下，原待排序数组的容量为n，做n路归并排序，
 * 则只归并一层，该层中每个子数组都只有一个元素，
 * 使用堆对这n个元素进行排序，堆排序退化为归并排序
 * 
 *
 * 堆的实现细节优化方案：
 * 
 * shift_up和shift_down中使用复制操作代替swap操作
 * 表示堆的数组从0开始索引
 * 没有capacity的限制，动态的调整堆中数组的大小 
 *
 */

template <typename Item>
class MaxHeap
{
private:
    Item *data_;
    int count_;
    int capacity_;

    void shift_up(int k)
    {
        while (k > 1 && data_[k / 2] < data_[k])
        {
            swap(data_[k / 2], data_[k]);
            k /= 2;
        }
    }

    void shift_down(int k)
    {
        while (2 * k <= count_) // 只要有左孩子就可以进行交换操作
        {
            int swap_idx = 2 * k; // 此轮循环中，data_[swap_idx]和data_[k]交换位置
            if (swap_idx + 1 <= count_ && data_[swap_idx + 1] > data_[swap_idx])
            {
                swap_idx += 1;
            }
            if (data_[k] >= data_[swap_idx])
                break;
            swap(data_[k], data_[swap_idx]);
            k = swap_idx;
        }
    }

public:
    MaxHeap(int capacity) : count_(0)
    {
        data_ = new Item[capacity + 1];
        this->capacity_ = capacity;
    }

    // Heapify 将arr数组构建成堆
    MaxHeap(Item arr[], int n)
    {
        data_ = new Item[n + 1];
        capacity_ = n;
        for (int i = 0; i < n; i++)
        {
            data_[i + 1] = arr[i];
        }
        count_ = n;

        for (int i = count_ / 2; i >= 1; i--)
        {
            shift_down(i);
        }
    }

    ~MaxHeap()
    {
        delete[] data_;
    }

    int size()
    {
        return count_;
    }

    bool is_empty()
    {
        return count_ == 0;
    }

    void insert(Item item)
    {
        assert(count_ + 1 <= capacity_);

        data_[count_ + 1] = item;
        count_++;
        shift_up(count_);
    }

    Item extract_max()
    {
        assert(count_ > 0);

        Item ret = data_[1];

        swap(data_[1], data_[count_]);
        count_--;
        shift_down(1);
        return ret;
    }
};

// 方法一
// 时间复杂度O(nlogn)
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

// 方法二
// 时间复杂度O(n)
// 配合构造函数 MaxHeap(Item arr[], int n);
// 从最后一个非叶子节点开始shift_down，省去了n/2的叶子节点的运算，速度更快
template <typename T>
void HeapSort_2(T arr[], int n)
{
    MaxHeap<T> max_heap = MaxHeap<T>(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = max_heap.extract_max();
    }
}

// 方法三
/**
 * 
 * 原地堆排序，不需要开辟额外的空间，在arr数组上原地操作
 * 
 * 从0开始索引
 * parent(i) = (i - 1) / 2
 * left_child(i) = 2 * i + 1
 * right_child(i) = 2 * i + 2
 * 最后一个非叶子节点的索引: (count - 1) / 2
 * 
 */

template <typename T>
void HeapSort_3(T arr[], int n)
{
    // Heapify 将arr数组构建成最大堆
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

template <typename T>
void __shift_down(T arr[], int n, int k)
{
    while (2 * k + 1 < n) // 左孩子不越界
    {
        int swap_idx = 2 * k + 1;
        if (swap_idx + 1 < n && arr[swap_idx + 1] > arr[swap_idx])
        {
            swap_idx += 1;
        }

        if (arr[k] >= arr[swap_idx])
            break;
        swap(arr[swap_idx], arr[0]);
        k = swap_idx;
    }
}


/**
 * 索引堆（Index Heap）
 * 
 * 从0开始索引
 * parent(i) = (i - 1) / 2
 * left_child(i) = 2 * i + 1
 * right_child(i) = 2 * i + 2
 * 最后一个非叶子节点的索引: (count - 1) / 2
 * 
 */

/**
 * 优势：
 * 若data的数据类型很复杂，则可以只交换int类型的索引，交换效率很高
 * 并且可以方便对堆中数据的进行操作并维护
 * 
 * 排序前：
 *    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10
 * index  1,  2,  3,  4,  5,  6,  7,  8,  9,  10
 * data  15, 17, 19, 13, 22, 16, 28, 30, 41, 62
 * 
 * 排序后：
 *    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10
 * index  10,  9,  7,  8,  5,  6,  3,  1,  4,  2
 * data  15, 17, 19, 13, 22, 16, 28, 30, 41, 62
 * rev   8,  10,  7,  9,  5,  6,  3,  4,  2,  1
 * 其中:
 * index[i] 表示索引i在data堆中的位置 
 * reverse[i]表示索引i在data堆中的位置
 * index[i] = j
 * reverse[j] = i
 * index[reverse[i]] = i
 * reverse[index[i]] = i
 * 
 */

template <typename Item>
class IndexMaxHeap
{
private:
    Item *data_;
    int *index_;
    int *reverse_;
    int count_;
    int capacity_;

    void shift_up_(int k)
    {
        while (k > 1 && data_[index_[k / 2]] < data_[index_[k]])
        {
            swap(index_[k / 2], index_[k]);
            reverse_[index_[k / 2]] = k / 2;
            reverse_[index_[k]] = k;
            k /= 2;
        }
    }

    void shift_down_(int k)
    {
        while (2 * k <= count_)
        {
            int swap_idx = k;
            if (swap_idx + 1 <= count_ && data_[index_[k]] < data_[index_[k + 1]])
            {
                swap_idx += 1;
            }

            if (data_[index_[k]] >= data_[index_[swap_idx]])
                break;
            swap(index_[k], index_[swap_idx]);
            reverse_[index_[k]] = k;
            reverse_[index_[swap_idx]] = swap_idx;
            k = swap_idx;
        }
    }

public:
    IndexMaxHeap(int capacity) : count_(0), capacity_(capacity)
    {
        data_ = new Item[capacity + 1];
        index_ = new int[capacity + 1];
        reverse_ = new int[capacity_ + 1];
        for (int i = 0; i < capacity_; i++)
        {
            reverse_[i] = 0;
        }
    }

    ~IndexMaxHeap()
    {
        delete[] data_;
        delete[] index_;
        delete[] reverse_;
    }

    int size()
    {
        return count_;
    }

    bool is_empty()
    {
        return count_ == 0;
    }

    // 传入的索引对用户来说是从0开始计算的，但是真实data_[]是从1开始索引的
    void insert(int i, Item item) // 由于是索引堆，可以按照索引i插入
    {
        assert(this->count_ + 1 <= this->capacity_);
        assert(i + 1 >= 1 && i + 1 <= capacity_);

        i += 1;
        data_[i] = i;
        index_[count_ + 1] = item;
        reverse_[i] = count_ + 1;

        count_++;
        shift_up_(count);
    }

    Item extract_max()
    {
        assert(count_ > 0);

        Item ret = data_[index_[1]];

        swap(data_[index_[1]], data_[index_[count_]]);
        reverse_[index_[1]] = 1;
        reverse_[index_[count_]] = 0;
        count_--;
        shift_down_(1);
        return ret;
    }

    int extract_max_idx()
    {
        assert(count_ > 0);

        int ret = index_[1] - 1;
        swap(index_[1], index_[count_]);
        reverse_[index_[1]] = 1;
        reverse_[index_[count_]] = 0;
        count_--;
        shift_down_(1);
        return ret;
    }

    Item get_item(int i)
    {
        return data_[i + 1];
    }

    bool is_contain(int i)
    {
        assert(i + 1 >= 1 && i + 1 <= capacity_);
        return reverse_(i + 1) != 0;
    }

    void change_item(int i, Item new_item)
    {
        // 确定i的索引确实在堆中，而不能只是单纯的小于等于capacity_
        assert(is_contain(i));
        
        i += 1;
        data_[i] = new_item;

        /* 若没有reverse数组时 */
        // // 找到index_[j] = i，j代表data[i]在堆中的位置
        // // 之后再shift_up_(), shift_down_()
        // for (int j = 1; j <= count_; j++)
        // {
        //     if (index_[j] == i)
        //     {
        //         shift_up_(j);
        //         shift_down_(j);
        //     }
        // }

        /* 若没有reverse数组时 */
        int j = reverse_[i];
        shift_up_(j);
        shift_down_(j);
    }
};


/**
 * 排序算法的稳定性
 * 
 * 可以通过自定义比较函数，让排序算法不存在稳定性的问题
 */

struct Student
{
    string name;
    int score;

    bool operator<(const Student &other_student)
    {
        // return score < other_student.score;
        return score != other_student.score ? score < other_student.score : name < other_student.name;
    }

    friend ostream &operator<<(ostream &os, const Student &student)
    {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }
};


/**
 * 进阶问题：
 * 
 * 如果给定的数组已经排好序呢？你将如何优化你的算法：
 * 排序 + 双指针
 * 
 * 如果 nums1 的大小比 nums2 小很多，哪种方法更优：
 * 哈希表（较小的数组进行哈希计数，然后在另一数组中根据哈希来寻找）
 * 
 * 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中： 
 * 通过归并外排将两个数组排序后再使用排序双指针查找
 * 
 * 对应进阶问题三，如果内存十分小，不足以将数组全部载入内存，
 * 那么必然也不能使用哈希这类费空间的算法，只能选用空间复杂度最小的算法，即解法一。
 * 但是解法一中需要改造，一般说排序算法都是针对于内部排序，一旦涉及到跟磁盘打交道（外部排序），
 * 则需要特殊的考虑。归并排序是天然适合外部排序的算法，可以将分割后的子数组写到单个文件中，
 * 归并时将小文件合并为更大的文件。当两个数组均排序完成生成两个大文件后，
 * 即可使用双指针遍历两个文件，如此可以使空间复杂度最低。
 */