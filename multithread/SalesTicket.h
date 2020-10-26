#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define NAME_LINE 40

struct Ticket
{
    int n_count;
    char str_thread_name[NAME_LINE];

    Ticket() : n_count(0)
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

template<typename T>
string ConvertToString(const T val)
{
    string s;
    stringstream ss;
    ss << val;
    ss >> s;
    return s;
}

DWORD WINAPI SaleTicket(LPVOID lpthread_param);

