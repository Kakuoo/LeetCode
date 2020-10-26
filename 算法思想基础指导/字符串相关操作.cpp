#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
using namespace std;

// 整数转字符串
void int_to_string(int val, string str_val)
{
    string tmp;
    while (val)
    {
        // tmp += (string)(val % 10);
        tmp += val % 10 + '0';
        val = val / 10;
    }
    for (int i = tmp.length() - 1; i >= 0; i--)
    {
        str_val += tmp[i]; // 逆序将字符串添加到str_val中
    }
}

// 提取以空格分割的字符串1
void divide_string1(string str)
{
    vector<string> word_vec;
    string tmp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {
            tmp += str[i];
        }
        else
        {
            word_vec.push_back(tmp);
            tmp = "";
        }
    }

    if (tmp.size() != 0)
        word_vec.push_back(tmp);
}

// 提取以空格分割的字符串2
void divide_string2(string str)
{
    vector<string> word_vec;
    istringstream is(str);
    string tmp;
    while (is >> tmp)
    {
        word_vec.push_back(tmp);
    }
}

// 任意2-36进制数转换为10进制数
int atoi_mine(string s, int radix)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char t = s[i];
        if (t >= '0' && t <= '9')
            res = res * radix + t - '0';
        else
            res = res * radix + t - 'A' + 10;
    }

    return res;
}

// 10进制数转换为任意的n进制数
string itoa_mine(int num, int radix)
{
    string res = "";
    while (num != 0)
    {
        int t = num % radix;
        if (t >= 0 && t <= 9)
            res += t + '0';
        else
           res += t - 10 + 'A';
        num /= radix;
    }
    
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string str = "16";
    int res_int = atoi_mine(str, 8);
    cout << res_int << endl;

    int num = 123;
    string res_str = itoa_mine(num, 36);
    cout << res_str << endl;
    
    return 0;
}