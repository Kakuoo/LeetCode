/**
 * 练习多线程：https://www.runoob.com/w3cnote/cpp-multithread-demo.html
 */

#include <windows.h>
#include <iostream>
#include <string>
// #include <strstream>

using namespace std;

#define NAME_LINE 40

HANDLE g_mutex = nullptr;

struct Ticket
{
    int max_num;
    char str_thread_name[NAME_LINE];

    Ticket() : max_num(0)
    {
        memset(str_thread_name, 0, NAME_LINE * sizeof(char));
    }
};

struct ThdData
{
    Ticket *ticket;
    char str_thread_name[NAME_LINE];
    ThdData() : ticket(nullptr)
    {
        memset(str_thread_name, 0, NAME_LINE * sizeof(char));
    }
};

DWORD WINAPI ThreadFun(LPVOID thread_param)
{
    Ticket *thread_data = (Ticket *)thread_param;

    for (int i = 0; i < thread_data->max_num; i++)
    {
        WaitForSingleObject(g_mutex, INFINITE);
        cout << thread_data->str_thread_name << " --- " << i << endl;
        Sleep(100);
        ReleaseMutex(g_mutex);
    }
    return 0L;
}

int main()
{
    g_mutex = CreateMutex(NULL, FALSE, NULL);

    // Initialize thread
    Ticket thread_data_1, thread_data_2;
    thread_data_1.max_num = 5;
    strcpy(thread_data_1.str_thread_name, "线程1");
    thread_data_2.max_num = 10;
    strcpy(thread_data_2.str_thread_name, "线程2");

    // build first sub-thread
    HANDLE hthread_1 = CreateThread(NULL, 0, ThreadFun, &thread_data_1, 0, NULL);
    HANDLE hthread_2 = CreateThread(NULL, 0, ThreadFun, &thread_data_2, 0, NULL);
    CloseHandle(hthread_1);
    CloseHandle(hthread_2);

    for (int i = 0; i < 5; i++)
    {
        WaitForSingleObject(g_mutex, INFINITE);
        cout << "主线程: i === " << i << endl;
        Sleep(100);
        ReleaseMutex(g_mutex);
    }

    Sleep(500);
    return 0;
}