#ifndef STRING_MINE_H_
#define STRING_MINE_H_
#include <iostream>
using namespace std;

class String
{
public:
    // 构造函数及成员方法
    String();
    String(const char *);
    String(const String &s);
    ~String();
    int length() const { return len; }

    // 重载运算符
    String &operator=(const char *);
    String &operator=(const String &);
    char &operator[](int i);  // read-write char access for non-const String
    const char &operator[](int i) const;  // read-only char access for const String

    // 重载友元运算符
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend ostream &operator<<(ostream &os, const String &st);
    friend istream &operator>>(istream &is, String &st);

    // 静态成员函数
    static int HowMany();

private:
    char *str;                    // pointer to string
    int len;                      // len of string
    static int num_strings;       // number of objects
    static const int CINLIM = 80; // cin input limits
};
#endif // STRING_MINE_H_