#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    std::size_t size() const { return n; }

protected:
    std::size_t n;
};
class Derived : private Base
{
public:
    using Base::size;

protected:
    using Base::n;
};

// class Base1 {
//     public:
//         Base1():value(10) {}
//         virtual ~Base1() {}
//         void test1() { cout << "Base test1..." << endl; }
//     protected: // 保护
//         int value;
// };

// // 默认为私有继承
// class Derived1 : Base1 {
//     public:
//         Base1::value;
//         void test2() { cout << "value is " << value << endl; }
// };

// class Base {
//     public:
//         Base():value(20) {}
//         virtual ~Base() {}
//         void test1() { cout << "Base test1..." << endl; }
//     private:  //私有
//         int value;
// };

// /**
//  * 子类对父类成员的访问权限跟如何继承没有任何关系，
//  * “子类可以访问父类的public和protected成员，不可以访问父类的private成员”——这句话对任何一种继承都是成立的。
//  *
//  */
// class Derived : public Base {
//     public:
//         using Base::value;
//         void test2() { cout << "value is " << value << endl; }
// };

// int main()
// {
//     // Derived1 d1;
//     // d1.test2();

//     Derived d;
//     d.test2();
//     return 0;
// }

// // // 类的成员函数做友元
// class Building;

// class GoodGay
// {
// public:
//     GoodGay();

//     void visit();  // 可以访问building类中的私有成员
//     void visit2();  // 无法访问building类中的私有成员

// public:
//     Building *building;
// };

// class Building
// {
//     friend void GoodGay::visit();

// public:
//     Building();

// public:
//     string m_settingroom;

// private:
//     string m_bedroom;
// };

// Building::Building()
// {
//     this->m_settingroom = "客厅";
//     this->m_bedroom = "卧室";
// }

// GoodGay::GoodGay()
// {
//     building = new Building;
// }

// void GoodGay::visit()
// {
//     cout << "visit 正在访问：" << building->m_settingroom << endl;
//     cout << "visit 正在访问：" << building->m_bedroom << endl;
// }

// void GoodGay::visit2()
// {
//     cout << "visit2 正在访问：" << building->m_settingroom << endl;
//     // cout << "visit2 正在访问：" << building->m_bedroom << endl;
// }

// void test()
// {
//     GoodGay gg;
//     gg.visit();
//     gg.visit2();
// }

// int main()
// {
//     test();
//     return 0;
// }

// // 类做友元
// class Building;

// class GoodGay
// {
// public:
//     GoodGay();

// public:
//     void visit();

// public:
//     Building *building;
// };

// class Building
// {
//     friend class GoodGay;

// public:
//     Building();

// public:
//     string m_settingroom;

// private:
//     string m_bedroom;
// };

// Building::Building()
// {
//     this->m_settingroom = "客厅";
//     this->m_bedroom = "卧室";
// }

// GoodGay::GoodGay()
// {
//     building = new Building;
// }
// void GoodGay::visit()
// {
//     cout << "好友正在访问：" << building->m_settingroom << endl;
//     cout << "好友正在访问：" << building->m_bedroom << endl;
// }

// void test()
// {
//     GoodGay gg;
//     gg.visit();
// }

// int main()
// {
//     test();
//     return 0;
// }

// // // 全局函数做友元