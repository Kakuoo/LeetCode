/**
 * 二分搜索树
 * 
 * 对于有序序列，才能使用二分查找法（排序的作用）
 * 
 * 优势：
 * 高效的增删查改，动态维护数据
 * 方便回答数据之间的关系问题
 * min, max, floor, ceil, rank, select
 * 
 * 二叉树遍历的复杂度为O(n)
 * 
 * 快速排序在大多数情况下都是高效的，但是在特别的情况下，
 * 二分查找法会退化为O(n^2)的复杂度
 * 二分搜索树亦可能退化成为一个链表，一般的，搜索的复杂度与层的高度相关O(logn)，
 * 而此时，树的高度为n，二分搜索树的相关操作都从O(logn)退化为O(n^2)
 * 
 * 
 */

/**
 * 若数据以近乎有序的方式构建为二叉搜索树，
 * 则可能导致二叉搜索树退化为链表，
 * 因此，可以改造二叉树的实现，使二叉树无法退化为链表
 * 
 * 平衡二叉树：
 * 有左右两颗字数，并且左右两颗子树的高度差不会超过1，
 * 可以保证整个二叉树的高度一定为O(logn)级别的，
 * 
 * 平衡二叉树的其中几种著名的实现是：
 * 红黑树、2-3树、AVL树、Splay树（伸展树）
 * 
 * 平衡二叉树和堆的结合：Treap
 * 
 * 前缀树：TrieTree（前缀树）
 * 
 * KD树、区间树、哈夫曼树
 * 
 */

/**
 * 二分搜索树 
 * 
 * 深度优先遍历 前中后序遍历
 * 广度优先遍历 层序遍历
 * 
 * 前序遍历：当前节点 ---> 递归访问左子树 ---> 递归访问右子树
 * 中序遍历：递归访问左子树 ---> 访问当前节点 ---> 递归访问右子树
 * 后序遍历：递归访问左子树 ---> 递归访问右子树 ---> 访问当前节点
 * 
 * 二分搜索树 中序遍历 由小到大排序
 * 
 */

#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

template <typename Key, typename Value>
class BST
{
private:
    struct Node
    {
        Key key;     // 例如 string，统计词频
        Value value; // 例如 int，统计词频
        Node *left;
        Node *right;

        Node(Key k, Value val) : key(k), value(val), left(nullptr), right(nullptr) {}
        // 拷贝构造函数
        Node(Node *node) : key(node->key), value(node->value), left(node->left), right(node->right) {}
    };

    Node *root_;
    int count_;

public:
    BST(Key k, Value val) : root_(nullptr), count_(0) {}

    ~BST()
    {
        // TODO: ~BST()
        destroy_(root_); // 使用后序遍历的方式释放每个节点
    }

    int size()
    {
        return count_;
    }

    bool is_empty()
    {
        return count_ == 0;
    }

    void insert(Key key, Value value)
    {
        root_ = insert(root_, key, value);
    }

    bool contain(Key key) // 查看是否包含有key这个元素
    {
        return contain(root_, key);
    }

    // 返回类型的选择
    // Node *search(Key key, Value value) // 如果这样做，则需要Node为public，但是对于数据封装不够完备
    // Value search(Key key, Value value)  // 要求调用search之前，要肯定key存在，但是如果用户忘记查找contain，则可能search一个不存在的值
    Value *search(Key key) // 如果查找失败，则返回空，若查找到，则返回一个指向元素的指针
    {
        return search(root_, key);
    }

    void pre_order()
    {
        pre_order(root_);
    }

    void in_order()
    {
        in_order(root_);
    }

    void post_order()
    {
        post_order(root_);
    }

    void level_order()
    {
        queue<Node *> q;
        q.push(root_);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            cout << node->key << endl;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    Key minimum()
    {
        assert(count_ != 0);
        Node *min_node = minimum(root_);
        return min_node->key;
    }

    void remove_min()
    {
        if (root_ != nullptr)
            root_ = remove_min(root_);
    }

    void remove_max()
    {
        if (root_ != nullptr)
            root_ = remove_max(root_);
    }

    // 删除左右都孩子的节点d时，删除d，替换d为其右子树中最小值 s = mid(d->right)
    // s->right = remove_min(d->right)
    // s->left = d->left
    // 删除d，s是新的子树的根
    void remove(Key key)
    {
        root_ = remove(root_, key);
    }

private:
    Node *insert(Node *node, Key key, Value value)
    {
        if (node == nullptr)
        {
            count_++;
            return new Node(key, value);
        }

        if (key == node->key)
        {
            node->value = value;
        }
        else if (key < node->key)
        {
            node->left = insert(node->left, key, value);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key, value);
        }
        return node;
    }

    bool contain(Node *node, Key key)
    {
        if (node == nullptr)
            return false;

        if (key == node->key)
        {
            return true;
        }
        else if (key < node->key)
        {
            return contain(node->left, key);
        }
        else if (key > node->key)
        {
            return contain(node->right, key);
        }
    }

    Value *search(Node *node, Key key)
    {
        if (node == nullptr)
            return nullptr;

        if (key == node->key)
        {
            return &(node->value);
        }
        else if (key > node->key)
        {
            return search(node->left, key);
        }
        else if (key < node->key)
        {
            return search(node->right, key);
        }
    }

    void pre_order(Node *node)
    {
        if (node == nullptr)
            return;

        cout << node->value << endl;
        pre_order(node->left);
        pre_order(node->right);
    }

    void in_order(Node *node)
    {
        if (node == nullptr)
            return;

        in_order(node->left);
        cout << node->value << endl;
        in_order(node->right);
    }

    void post_order(Node *node)
    {
        if (node == nullptr)
            return;

        post_order(node->left);
        post_order(node->right);
        cout << node->value << endl;
    }

    void destroy(Node *node)
    {
        if (node == nullptr)
            return;

        destroy(node->left);
        destroy(node->right);

        delete node;
        count_--;
    }

    Node *minimum(Node *node)
    {
        if (node->left != nullptr)
        {
            return minimum(node->left);
        }
        else
        {
            return node;
        }
    }

    Node *maxmum(Node *node)
    {
        if (node->right != nullptr)
        {
            return maxmum(node->right);
        }
        else
        {
            return node;
        }
    }

    Node *remove_min(Node *node)
    {
        if (node->left == nullptr)
        {
            Node *node_right = node->right;
            delete node;
            count_--;
            return node_right;
        }
        else
        {
            node->left = remove_min(node->left);
            return node;
        }
    }

    Node *remove_max(Node *node)
    {
        if (node->right == nullptr)
        {
            Node *node_left = node->left;
            delete node;
            count_--;
            return node_left;
        }
        else
        {
            node->right = remove_max(node->right);
            return node;
        }
    }

    // 删除任意一个节点：（两个版本）
    // 当该节点左右子树都存在时：
    // 1.找到右子树的最小值 （下面的实现）
    // 2.找到左子树的最大值 （尚未实现）
    Node *remove(Node *node, Key key)
    {
        if (node == nullptr)
            return nullptr;

        if (key < node->key)
        {
            node->left = remove(node->left, key);
            return node->left;
        }
        else if (key > node->key)
        {
            node->right = remove(node->right, key);
            return node;
        }
        else if (node->key = key)
        {
            if (node->left == nullptr)
            {
                Node *node_tmp = node->right;
                delete node;
                count_--;
                return node_tmp;
            }
            else if (node->right == nullptr)
            {
                // 每个node都是new出来的，不可以偷懒让两个指针指向同一块动态空间，需切实delete该节点，否则会造成内存泄漏
                // node = node->left;
                // return node;

                Node *node_tmp = node->left;
                delete node;
                count_--;
                return node_tmp;
            }
            else if (node->left && node->right)
            {
                // 深拷贝，因为下面的remove_min会delete删掉原本的node_successor所指向的空间
                Node *node_successor = new Node(minimum(node->right));
  
                node_successor->right = remove_min(node->right);
                node_successor->left = node->left;
                delete node;
                count_--;
                return node_successor;
            }
        }
    }
};