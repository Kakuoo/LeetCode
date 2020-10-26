/**
 * 普通队列：先进先出，后进后出
 * 优先队列：出队顺序和入队顺序无关；和优先级相关
 * 
 * 例如：
 * 操作系统动态挑选优先级较高的任务执行
 * 人工智能中，游戏内的角色动态根据ROI（感兴趣区域）选择敌人攻击
 * 
 */

/**
 * 
 * 二叉堆
 * 
 * 性质：
 * 堆总是一个完全二叉树（最大堆）
 * 二叉树（堆）中任何一个子节点总不大于他的父节点
 * 
 * 使用数组存储二叉堆（因为堆是一个完全二叉树）
 * 若根节点的索引为1，则第i个节点访问他的左孩子为(2*i)，右孩子为(2*i + 1)
 * 若根节点的索引为0，则第i个节点访问他的左孩子为(2*i + 1)，右孩子为(2*i + 2)
 *  
 * 常用的为将根节点索引设置为0
 * parent(i) = i / 2
 * left_child(i) = 2 * i
 * right_child(i) = 2 * i + 1
 * 
 */

// 实现最大堆
#include <iostream>
#include <cassert>
#include <ctime>
using namespace std;

template <typename Item>
class MaxHeap
{
private:
    Item *data;
    int count;

public:
    MaxHeap(int capacity) : count(0)
    {
        data = new Item[capacity + 1];
    }

    ~MaxHeap()
    {
        delete[] data;
    }

    int size()
    {
        return count;
    }

    bool is_empty()
    {
        return count == 0;
    }
};

int main()
{
    MaxHeap<int> max_heap = MaxHeap<int>(100);
    cout << max_heap.size() << endl;

    return 0;
}