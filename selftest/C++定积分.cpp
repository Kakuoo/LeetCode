/**
 * 求y^2 = 2ax和直线y = bx + c围成的面积
 * 
 */

#include <iostream>
#include <cmath>
using namespace std;

double integral(double a, double b, double c)
{
    double delta = 4 * a * (a - 2 * b * c);
    if (delta <= 0)
        return 0;
    double sqrt_delta = sqrt(delta);
    // 交点坐标 y1，y2
    double y1 = (2 * a - sqrt_delta) / (2 * b);
    double y2 = (2 * a + sqrt_delta) / (2 * b);
    // 积分公式中分别代入y1坐标和y2坐标的两项
    double s1 = (pow(y1, 2) - 2 * y1 * c) / (2 * b) - pow(y1, 3) / (6 * a);
    double s2 = (pow(y2, 2) - 2 * y2 * c) / (2 * b) - pow(y2, 3) / (6 * a);
    
    return (y1 > y2 ? (s1 - s2) : (s2 - s1));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double a, b, c;
        cin >> a >> b >> c;
        cout << integral(a, b, c) << endl;
    }
    return 0;
}