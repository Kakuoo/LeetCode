#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;

/**
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

    // Heapify的过程
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

// int main()
// {
//     MaxHeap<int> max_heap = MaxHeap<int>(100);
//     cout << "max_heap.size() : " << max_heap.size() << endl;

//     srand((unsigned int)time(nullptr));
//     for (int i = 0; i < 15; i++)
//     {
//         max_heap.insert(rand() % 100);
//     }
//     cout << "max_heap.size() : " << max_heap.size() << endl;

//     while (!max_heap.is_empty())
//     {
//         cout << max_heap.extract_max() << " " << endl;
//         cout << "max_heap.size() : " << max_heap.size() << endl;
//     }

//     return 0;
// }