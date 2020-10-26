/*
 * poj
 * [2341] 最优加油方法  Hard
 * 
 * 贪心
 * 
 * 问题：
 * 已知一条公路上有一个起点一个终点，之间有n个加油站；
 * 已知从这n个加油站到终点的距离d与各个加油站可以加油的量l，起点位置到终点的距离L起始时刻油箱中的汽油量P；
 * 假设使用1个单位的汽油即走一个单位的距离，油箱没有上限，最少加几次油，可以从起点开至终点？（如果无法到达终点，返回-1）
 * 
 */

/*
 * 思考：
 * 何时加油最合适？
 * 油快用光的时候加油最合适
 * 
 * 在哪个加油站最合适？
 * 在油量最多的加油站最合适(最大堆)
 * 
 */

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}

int get_minimum_stop(int L, int P, vector<pair<int, int>> &stop)
// L为起点到终点的距离，P为起点初始的加油量
// pair<加油站至终点的距离, 加油站汽油量>
{
    priority_queue<int> Q; // 存储油量的最大堆
    int add_oil_num = 0;
    stop.push_back(make_pair(0, 0)); // 将终点作为一个停靠点，添加至stop数组
    sort(stop.begin(), stop.end(), cmp);
    for (int i = 0; i < stop.size(); i++)
    {
        int dist = L - stop[i].first; // 当前距下一个加油站的距离
        while (dist > P && !Q.empty())
        {
            P = P + Q.top();
            Q.pop();
            add_oil_num++;
        }
        if (dist > P && !Q.empty())
        {
            return -1;
        }
        P -= dist;
        L = stop[i].first;
        Q.push(stop[i].second);
    }
    return add_oil_num;
}