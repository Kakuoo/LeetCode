#include "SalesTicket.h"

static HANDLE g_mutex;

// SaleTickets Program
DWORD WINAPI SaleTicket(LPVOID lpthread_param)
{
    ThdData *thread_data = (ThdData *)lpthread_param;
    Ticket *sale_data = thread_data->ticket;
    while (sale_data->n_count > 0)
    {
        WaitForSingleObject(g_mutex, INFINITE);
        if (sale_data->n_count > 0)
        {
            cout << thread_data->str_thread_name << " 正在出售第 " << sale_data->n_count-- << " 张票" << endl;

            if (sale_data->n_count >= 0)
            {
                cout << "出票成功！剩余 " << sale_data->n_count << " 张票" << endl;
            }
            else
            {
                cout << "出票失败！该票已售空。" << endl;
            }
        }
        Sleep(10);
        ReleaseMutex(g_mutex);
    }
    return 0L;
}

// test
int main()
{
    // create a mutex meta
    g_mutex = CreateMutex(NULL, FALSE, NULL);

    // Initialize train ticket
    Ticket ticket;
    ticket.n_count = 100;
    strcpy(ticket.str_thread_name, "北京--->西安");

    const int THREAD_NUM = 100;
    ThdData thread_sale[THREAD_NUM]; // 结构体数组，8个售票窗口
    HANDLE hthread[THREAD_NUM];
    for (int i = 0; i < THREAD_NUM; i++)
    {
        thread_sale[i].ticket = &ticket;
        string str_thread_name = ConvertToString(i);
        str_thread_name = "窗口" + str_thread_name;
        strcpy(thread_sale[i].str_thread_name, str_thread_name.c_str());

        hthread[i] = CreateThread(NULL, NULL, SaleTicket, &thread_sale[i], 0, NULL);

        WaitForSingleObject(g_mutex, INFINITE);
        cout << thread_sale[i].str_thread_name << " 开始出售 " << thread_sale[i].ticket->str_thread_name << " 的车票" << endl;
        ReleaseMutex(g_mutex);

        CloseHandle(hthread[i]);
    }

    Sleep(800);
}