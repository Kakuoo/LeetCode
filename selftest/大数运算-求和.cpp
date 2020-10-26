#include <iostream>
#include <string.h>
using namespace std;

/**
 * 大数运算 求和
 * 采用字符串 列竖式的方法
 * 
 *  12345
 * +54321
 * ------
 *  66666
 * 
 *  19
 * +12
 * ---
 *  31
 */

#define MAXLEN 10000

int main()
{
    int up = 0, tmp;     // up为进位
    char buff[MAXLEN + 1] = {0};
    char a[MAXLEN + 1] = {0}, b[MAXLEN + 1] = {0};

    // input a 倒序存储a
    scanf("%s", buff);
    tmp = 0;
    for (int i = strlen(buff) - 1; i >= 0; --i)
        a[tmp++] = buff[i] - '0';
    // input b 倒序存储b
    scanf("%s", buff);
    tmp = 0;
    for (int i = strlen(buff) - 1; i >= 0; --i)
        b[tmp++] = buff[i] - '0';

    for (int i = 0; i < MAXLEN; ++i)
    {
        tmp = a[i] + b[i] + up;
        a[i] = tmp % 10;
        up = tmp / 10;
    }

    for (int i = MAXLEN; i >= 0; i--)
    {
        if (a[i] != 0)
        {
            for (i; i >= 0 ; i--)
                printf("%d", a[i]);
        }
    }
    return 0;
}