#include <iostream>
using namespace std;


class Animal
{
public:
	int m_age;
};

class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};

int main()
{
	SheepTuo st;
	st.Sheep::m_age = 100;
	st.Tuo::m_age = 200;
	cout << st.Sheep::m_age << endl;
	cout << st.Tuo::m_age << endl;
	cout << st.m_age << endl;
	return 0;
}


// // 利用开发人员命令提示工具查看对象模型
// // cl /d1 reportSingleClassLayout<类名> "文件名"
// class BasePage
// {
// public:
//     BasePage() : m_a(100) {}

//     void func()
//     {
//         cout << "BasePage - func()调用" << endl;
//     }

// public:
//     int m_a;
//     static int sta_var;

// protected:
//     double m_b;

// private:
//     char m_c;
// };

// class Page : public BasePage
// {
// public:
//     Page() : m_a(200) {}
//     void func()
//     {
//         cout << "Page - func()调用" << endl;
//     }

// public:
//     int m_a;
//     static int sta_var;
// };

// int BasePage::sta_var = 12;
// int Page::sta_var = 16;

// void test()
// {

//     Page page;
//     // cout << sizeof(page) << endl;
//     // cout << page.m_a << endl;
//     // cout << page.BasePage::m_a << endl;
//     // cout << page.sta_var << endl;
//     cout << sizeof(page) << endl;
// }

// void test02()
// {
//     Page page;
//     // page.BasePage::func();
//     // cout << page.BasePage::sta_var << endl;
//     // cout << BasePage::sta_var << endl;
//     cout << Page::BasePage::sta_var << endl;
// }

// int main()
// {
//     test();
//     return 0;
// }