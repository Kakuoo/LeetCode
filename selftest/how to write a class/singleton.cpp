#include <iostream>
#include <string>
#include <vector>
using namespace std;


// class Singleton
// {
// public:
//     static Singleton *get_instance()
//     {
//         if (local_instance == nullptr)
//         {
//             local_instance = new Singleton();
//         }
//         return local_instance;
//     }

// private:
//     static Singleton *local_instance;
//     Singleton() {}
// };

// Singleton *Singleton::local_instance = nullptr;

// class Apple
// {
// public:
//     Apple() {}
//     Apple(int x) : m_nums(x) {}
//     // explicit Apple(int x) : m_nums(x) {}
//     friend ostream &operator<<(ostream &out, const Apple &a);

// private:
//     int m_nums;
// };

// ostream &operator<<(ostream &out, const Apple &a)
// {
//     cout << a.m_nums;
//     return out;
// }

// int main()
// {
//     int *pt = new int(2);
//     cout << "*pt: " << *pt << endl;

//     pt = new int[3]{5, 7, 9};
//     cout << "*pt array: " << *pt << endl;
//     cout << "*pt array: " << *(pt + 1) << endl;
//     cout << "*pt array: " << *(pt + 2) << endl;

//     delete pt;
//     cout << "=================" << endl;

//     // Apple *p = new Apple(5);
//     // cout << *p << endl;

//     Apple *p = new Apple[3]{0, 3, 6};
//     // Apple *p = new Apple[3]{Apple(0), Apple(3), Apple(6)};
//     cout << "*p array: " << *p << endl;
//     cout << "*p array: " << *(p + 1) << endl;
//     cout << "*p array: " << *(p + 2) << endl;

//     delete p;

//     return 0;
// }

// class Singleton
// {
// public:
//     static Singleton *get_instance()
//     {
//         if (local_instance == nullptr)
//             local_instance = new Singleton();
//         return local_instance;
//     }

// private:
//     Singleton() {}
//     static Singleton *local_instance;
// };

// Singleton *Singleton::local_instance = nullptr;

// class Singleton
// {
// public:
//     static Singleton *get_instance()
//     {
//         static Singleton local_s;
//         return &local_s;
//     }

// private:
//     Singleton() { cout << "构造" << endl; }
//     ~Singleton() { cout << "析构" << endl; }
//     static Singleton *local_instance;
// };

// int main()
// {
//     cout << "单例模式访问第一次前" << endl;
//     Singleton *s = Singleton::get_instance();
//     cout << "单例模式访问第一次后" << endl;
//     cout << "单例模式访问第二次前" << endl;
//     Singleton *s2 = Singleton::get_instance();
//     cout << "单例模式访问第二次后" << endl;
//     return 0;
// }
