#include <vector>
#include <string>
#include <iostream>
using namespace std;

/**
 * 方法一：事先制表
 */

/**
 * 方法二
 * 一开始，为了节省时间，我采用了第一种代码，制了表，可是提交上去发现，
 * 超出内存限制，仔细一想也对，毕竟当n为3000时，结果就已经在屏幕上显示过百行了，
 * 放在内存里，肯定会花费很多内存的
 * 
 */
// vector<int> fac;

// int main()
// {
//     int n;
//     while (cin >> n)
//     {
//         if (n == 0 || n == 1)
//             cout << "1" << endl;
//         else
//         {
//            fac.push_back(1);
//            for (int i = 2; i <= n; ++i)
//            {
//                for (int j = 0; j < fac.size(); ++j)
//                {
//                    fac[j] *= i;
//                }
//                int carry = 0;
//                 for (int j = fac.size() - 1; j >= 0; --j)
//                 {
//                     int tmp = fac[j] + carry;
//                     fac[j] = tmp % 10;
//                     carry = tmp / 10;
//                 }
//                 /**
//                  * 对最前面一位进上去的数字进行处理，由于这个数字可能不止一位，
//                  * 所以不能简简单单地插到最前面，而是要用一个while循环一步步插到最前面
//                  */
//                 while (carry)
//                 {
//                     fac.insert(fac.begin(), carry % 10);
//                     carry = carry / 10;
//                 }
//            }
//            for (int i = 0; i < fac.size(); ++i)
//            {
//                cout << fac[i];
//            }
//            cout << endl;
//         }
//         fac.clear();
//     }
//     return 0;
// }