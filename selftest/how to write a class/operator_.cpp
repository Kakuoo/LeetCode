#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

typedef void (*pf)();

typedef struct A_
{
    pf f_;
} A;

typedef struct B_
{
    pf b_;
} B;

int *funcA(int *a, int *b)
{
    cout << "Base A::func()" << endl;
    return a;
}

void funcB(string a, string b)
{
    cout << "B::func()" << endl;
}

typedef int *(*pd)(int *, int *);

int main()
{
    int a = 2;
    int *b = &a;
    pd p1[3] = {funcA, funcA, funcA};
    cout << *p1[0](b, b) << endl;;

    pd (*p2)[3] = &p1;
    cout << *(*p2)[0](b, b) << endl;


    // A a;
    // B b;

    // a.f_ = funcA;
    // b.b_ = funcB;

    // A *p = &a;
    // p->f_();

    // p = (A*)&b;
    // p->f_();

    return 0;
}

// // 六大构造函数
// class A
// {
// public:
//     A() {}
//     A(const A &a) {}
//     ~A() {}
//     A &operator=(const A &a) {}
//     A *operator&() {}
//     const A *operator&() const {}
// };

// class MyPrint
// {
// public:
//     void operator()(string word)
//     {
//         cout << word << endl;
//     }

//     int operator()(int num1, int num2)
//     {
//         return num1 + num2;
//     }
// };

// void MyPrintFunc(string word)
// {
//     cout << word << endl;
// }

// void test()
// {
//     MyPrint my_print;
//     my_print("HelloWorld");

//     MyPrintFunc("HelloWorld");

//     // // 匿名对象 MyAdd
//     // cout << MyAdd()(100, 100) << endl;
// }

// class Person
// {
// public:
//     Person()
//     {
//     }

//     Person(string name, int age)
//     {
//         this->m_name = name;
//         this->m_age = age;
//     }

//     bool operator==(Person &p)
//     {
//         if (this->m_name == p.m_name && this->m_age == p.m_age)
//             return true;
//         return false;
//     }

//     bool operator!=(Person &p)
//     {
//         // if (this->m_name == p.m_name && this->m_name == p.m_name)
//         //     return false;
//         // return true;
//         return !operator==(p);
//     }

// public:
//     string m_name;
//     int m_age;
// };

// class Person
// {
// public:
//     Person(int age)
//     {
//         this->m_age = new int(age);
//     }

//     Person(const Person &p)
//     {
//         this->m_age = new int(*p.m_age);
//     }

//     ~Person()
//     {
//         if (m_age != nullptr)
//         {
//             delete m_age;
//             m_age = nullptr;
//         }
//     }

//     Person &operator=(Person &p)
//     {
//         // 编译器提供浅拷贝
//         // this->m_age = p.m_age;

//         // 先判断是否有属性在堆区，如果有则先释放干净，再深拷贝
//         if (this->m_age != nullptr)
//         {
//             delete this->m_age;
//             this->m_age = nullptr;
//         }

//         // 深拷贝
//         this->m_age = new int(*p.m_age);

//         // 返回对象自身
//         return *this;
//     }

//     int *m_age;
// };

// void test()
// {
//     Person p1(18);
//     cout << *p1.m_age << endl;
//     Person p2(20);
//     p2 = p1; // 赋值操作
//     cout << *p2.m_age << endl;
// }

// int main()
// {
//     test();
// }

// class Person
// {

// public:
//     Person() : m_A(1), m_B(2) {}

//     Person(int a, int b) : m_A(a), m_B(b)
//     {
//     }

//     Person(const Person &p)
//     {
//         this->m_height = new int(*p.m_height);
//     }

//     ~Person()
//     {
//         if (this->m_height != nullptr)
//         {
//             delete this->m_height;
//             this->m_height = nullptr;
//         }
//     }

//     // 重载++前置运算符
//     Person &operator++();
//     // 重载++后置运算符, int占位参数表明为++后置
//     Person operator++(int);

//     friend ostream &operator<<(ostream &cout, Person &p);

// private:
//     int m_A;
//     int m_B;
//     int *m_height;
// };

// Person &Person::operator++()
// {
//     this->m_A++;
//     this->m_B++;
//     return *this;
// }

// Person Person::operator++(int)
// {
//     Person temp = *this;
//     this->m_A++;
//     this->m_B++;
//     return temp;
// }

// ostream &operator<<(ostream &cout, Person &p)
// {
//     cout << p.m_A << " " << p.m_B;
//     return cout;
// }

// void test1()
// {
//     Person p(10, 10);
//     cout << p << endl;

//     ++(++p);
//     cout << p << endl;
// }

// void test2()
// {
//     Person p(10, 10);
//     cout << p << endl;

//     // ++(++p);
//     (p++)++;
//     cout << p << endl;
// }

///////////////////////////////////////////////////
// // 通常不用成员函数重载左移运算符，因为无法实现cout在左侧
// // 只能用全局函数重载左移运算符
// class Person
// {
//     friend ostream &operator<<(ostream &cout, Person &p);

// public:
//     Person() : m_A(1), m_B(2) {}

//     Person(int a, int b) : m_A(a), m_B(b)
//     {
//     }

// private:
//     int m_A;
//     int m_B;
// };

// ostream &operator<<(ostream &cout, Person &p)
// {
//     cout << p.m_A << " " << p.m_B;
//     return cout;
// }

//////////////////////////////////////////////////////////
// class Person
// {
// public:
//     Person() : m_A(1), m_B(2) {}

//     Person(int a, int b) : m_A(a), m_B(b)
//     {
//     }

//     // 成员函数重载+号
//     Person operator+(Person &other);
//     Person operator+(int a);

// public:
//     int m_A;
//     int m_B;
// };

// // 成员函数重载+号
// Person Person::operator+(Person &other)
// {
//     Person temp;
//     temp.m_A = this->m_A + other.m_A;
//     temp.m_B = this->m_B + other.m_B;
//     return temp;
// }

// // 重载运算符 重载
// Person Person::operator+(int a)
// {
//     Person temp;
//     temp.m_A = this->m_A + a;
//     temp.m_B = this->m_B + a;
//     return temp;
// }

// // 全局函数重载+
// Person operator+(Person &p1, Person &p2)
// {
//     Person temp;
//     temp.m_A = p1.m_A + p2.m_A;
//     temp.m_B = p1.m_B + p2.m_B;
//     return temp;
// }

// // 重载运算符 重载
// Person operator+(Person &p1, int a)
// {
//     Person temp;
//     temp.m_A = p1.m_A + a;
//     temp.m_B = p1.m_B + a;
//     return temp;
// }

// void test()
// {
//     Person p1(10, 10);
//     Person p2(10, 10);
//     Person p3 = p1 + 2;
//     cout << p3.m_A << " " << p3.m_B << endl;
// }

// int main()
// {
//     test();
//     return 0;
// }