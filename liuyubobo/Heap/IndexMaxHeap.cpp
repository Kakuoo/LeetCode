#include <iostream>
#include <cassert>
using namespace std;

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