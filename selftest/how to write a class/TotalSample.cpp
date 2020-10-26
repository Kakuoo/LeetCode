#include <cstring>
#include "TotalSample.h"
using std::cin;
using std::cout;

// 初始化静态成员变量
int String::num_strings = 0;

// 静态成员函数
int String::HowMany()
{
    return num_strings;
}

// 成员函数
String::String()
{
    len = 4;
    str = new char[len + 1];
    str[0] = '\0';
    num_strings++;
}

String::String(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String(const String &st)
{
    len = st.len;
    str = new char[len + 1];
    str = std::strcpy(str, st.str);
    num_strings++;
}

String::~String()
{
    --num_strings;
    delete[] str;
}

// 重载函数运算符

// 重载赋值运算符
// 考虑异常安全性的两种做法
// 1.先用new分配新内容，再用delete释放已有内容（只在分配内容成功后再释放原有内容）
// 2.先创建一个临时实例，再交换临时实例和原来的对象
String &String::operator=(const String &st)
{
    if (this == &st)
        return *this;
        
    // 在构造函数里用new分配内存，若由于内存不足抛出bad_alloc等异常，
    // 不影响原来实例的状态，因此实例还是有效的，保证了异常安全性
    String st_temp(st);

    // 交换后，脱离str_temp的作用域时，自动调用析构函数释放其指向的旧内容
    char *str_temp = st_temp.str;
    st_temp.str = str;
    str = str_temp;

    return *this;
}

String &String::operator=(const String &st)
{
    if (this == &st)
        return *this;

    delete[] str;
    str = nullptr;

    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String &String::operator=(const char *s)
{
    delete[] str;
    str = nullptr;

    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char &String::operator[](int i)
{
    return str[i];
}

const char &String::operator[](int i) const
{
    return str[i];
}

// 重载友元运算符
bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream &operator<<(ostream &os, const String &st)
{
    os << st.str;
    return os;
}

istream &operator>>(istream &is, String &st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}