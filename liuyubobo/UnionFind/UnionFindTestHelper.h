#ifndef UNIONFIND_UNIONFINDTESTHELPER_H
#define UNIONFIND_UNIONFINDTESTHELPER_H

#include <iostream>
#include <ctime>
#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"
#include "UnionFind5.h"
using namespace std;

namespace UnionFindTestHelper
{
    void TestUF1(int n)
    {
        srand((unsigned int)time(nullptr));
        UF1::UnionFind uf = UF1::UnionFind(n);

        time_t start_time = clock();

        for (int i = 0; i < n; i++)
        {
            int a = rand() % n;
            int b = rand() % n;
            uf.UnionElements(a, b);
        }
        for (int i = 0; i < n; i++)
        {
            int a = rand() % n;
            int b = rand() % n;
            uf.IsConnected(a, b);
        }
        time_t end_time = clock();

        cout << "UF1, " << 2 * n << " ops, " << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;
    }

    void TestUF2(int n)
    {
        srand((unsigned int)time(nullptr));
        UF2::UnionFind2 uf = UF2::UnionFind2(n);

        time_t start_time = clock();

        for (int i = 0; i < n; i++)
        {
            int a = rand() % n;
            int b = rand() % n;
            uf.UnionElements(a, b);
        }
        for (int i = 0; i < n; i++)
        {
            int a = rand() % n;
            int b = rand() % n;
            uf.IsConnected(a, b);
        }
        time_t end_time = clock();

        cout << "UF2, " << 2 * n << " ops, " << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;
    }

    void TestUF3(int n)
    {
        srand((unsigned int)time(nullptr));
        UF3::UnionFind3 uf = UF3::UnionFind3(n);

        time_t start_time = clock();

        for (int i = 0; i < n; i++)
        {
            int a = rand() % n;
            int b = rand() % n;
            uf.UnionElements(a, b);
        }
        for (int i = 0; i < n; i++)
        {
            int a = rand() % n;
            int b = rand() % n;
            uf.IsConnected(a, b);
        }
        time_t end_time = clock();

        cout << "UF3, " << 2 * n << " ops, " << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;
    }

    void TestUF4(int n)
    {
        srand((unsigned int)time(nullptr));
        UF4::UnionFind4 uf = UF4::UnionFind4(n);

        time_t start_time = clock();

        for (int i = 0; i < n; i++)
        {
            int a = rand() % n;
            int b = rand() % n;
            uf.UnionElements(a, b);
        }
        for (int i = 0; i < n; i++)
        {
            int a = rand() % n;
            int b = rand() % n;
            uf.IsConnected(a, b);
        }
        time_t end_time = clock();

        cout << "UF4, " << 2 * n << " ops, " << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;
    }

    void TestUF5(int n)
    {
        srand((unsigned int)time(nullptr));
        UF5::UnionFind5 uf = UF5::UnionFind5(n);

        time_t start_time = clock();

        for (int i = 0; i < n; i++)
        {
            int a = rand() % n;
            int b = rand() % n;
            uf.UnionElements(a, b);
        }
        for (int i = 0; i < n; i++)
        {
            int a = rand() % n;
            int b = rand() % n;
            uf.IsConnected(a, b);
        }
        time_t end_time = clock();

        cout << "UF5, " << 2 * n << " ops, " << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;
    }
} // namespace UnionFindTestHelper

#endif // UNIONFIND_UNIONFINDTESTHELPER_H