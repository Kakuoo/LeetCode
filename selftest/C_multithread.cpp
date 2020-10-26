#include <iostream> // std::cout
#include <thread>   // std::thread, std::this_thread::sleep_for, this_thread::get_id()
#include <chrono>   // std::chrono::seconds, chrono::high_resolution_clock
#include <mutex>    //
#include <numeric>  // std::accumulate
#include <vector>
#include <list>
#include <algorithm>  // std::for_each
#include <functional> // std::mem_fn(member function)
// #include <unistd.h> // std::sleep()
// #include <cstdlib>

// #include <windows.h> // std::Sleep()
using namespace std;





// class Demo
// {
// public:
//     Demo(int x) : num(x)
//     {
//         cout << "调用 构造函数" << endl;
//     }

//     Demo(const Demo &other) : num(other.num)
//     {
//         cout << "调用 拷贝构造函数" << endl;
//     }

//     Demo(Demo &&other) : num(other.num)
//     {
//         cout << "调用 移动构造函数" << endl;
//     }

// private:
//     int num;
// };


// int main()
// {
//     cout << "emplace back" << endl;
//     vector<Demo> test1;
//     test1.emplace_back(2);

//     cout << "==============" << endl;
//     cout << "push back" << endl;
//     vector<Demo> test2;
//     test2.push_back(2);

//     return 0;
// }


// list<int> some_list;
// mutex some_mutex;

// void add_to_list(int new_value)
// {
//     lock_guard<mutex> guard(some_mutex);
//     some_list.push_back(new_value);
// }

// bool list_containers(int value_to_find)
// {
//     lock_guard<mutex> guard(some_mutex);
//     return find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
// }

// template <typename Iterator, typename T>
// struct accumulate_block
// {
//     void operator()(Iterator first, Iterator last, T &result)
//     {
//         result = accumulate(first, last, result);
//     }
// };

// template <typename Iterator, typename T>
// T parallel_accumulate(Iterator first, Iterator last, T init)
// {
//     unsigned long const length = distance(first, last);

//     if (!length)
//     {
//         return init;
//     }

//     unsigned long const min_per_thread = 25;
//     unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
//     unsigned long const hardware_threads = thread::hardware_concurrency();

//     unsigned long const num_threads = min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
//     unsigned long const block_size = length / num_threads;

//     vector<T> results(num_threads);
//     vector<thread> threads(num_threads - 1); // except main_thread

//     Iterator block_start = first;
//     for (unsigned long i = 0; i < (num_threads - 1); i++)
//     {
//         Iterator block_end = block_start;
//         advance(block_end, block_size);

//         threads[i] = thread(accumulate_block<Iterator, T>(), block_start, block_end, std::ref(results[i]));
//         block_start = block_end;
//     }

//     accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);
//     for_each(threads.begin(), threads.end(), mem_fn(&thread::join));

//     return accumulate(results.begin(), results.end(), init);
// }

// template <typename T>
// void func(T &&t)
// {

// }

// int main()
// {
//     func(24);
//     func(2.421);
//     func("string");

//     int i = 2;
//     func(i);
// }

// void print(std::string const &str)
// {
//     cout << str << endl;
// }

// int main()
// {
//     // int &i = 42;
//     int const &i = 42;
//     cout << i << endl;
//     print("Hello");

//     int &&k = 1;
//     cout << k << endl;

//     return 0;
// }

// 较为精确的控制了 子线程执行频率在200Hz(即5ms执行一次)
// 利用detach() + 条件变量来进行线程同步，让主线程在等待时也有事可做
// using namespace std;
// using namespace chrono; //chrono计时器 namespace

// using milliseconds_duration = std::chrono::duration<double, std::milli>; //milli = ratio<1,1000>
// using seconds_duration = std::chrono::duration<double, std::ratio<1, 1>>;

// #define SUB_THREAD_NUM 1

// high_resolution_clock::time_point tps[SUB_THREAD_NUM][2]; //建立一个Time_point类型的数组，每个subThread都有一个start_tp、一个end_tp
// milliseconds_duration t1;
// int call_intervak_t1 = 5; //执行速度  5ms call 1次

// bool thread1_ended = false; //使用detach时，需要独立地提供一种同步机制来等待线程完成

// void pause_thread_second(int n)
// {
//     this_thread::sleep_for(chrono::seconds(n));
// }

// void pause_thread_millisecond(int n)
// {
//     this_thread::sleep_for(chrono::milliseconds(n));
// }

// //要以一定的频率调用该函数
// void threadFunc1()
// {
//     pause_thread_millisecond(1);
//     cout << "Thread :" << this_thread::get_id() << endl;
// }

// void Func1()
// {
//     int i = 10;
//     double run_time = 0.0f;
//     while (i--)
//     {
//         tps[0][0] = high_resolution_clock::now(); //start_timepoint
//         threadFunc1();
//         tps[0][1] = high_resolution_clock::now(); //end_tp
//         t1 = duration_cast<milliseconds_duration>(tps[0][1] - tps[0][0]);
//         if (t1.count() < call_intervak_t1)
//             pause_thread_millisecond(call_intervak_t1 - t1.count()); //若执行时间比规定的hz快，则sleep一段时间

//         //看是否达到了规定的频率
//         tps[0][1] = high_resolution_clock::now();
//         t1 = duration_cast<milliseconds_duration>(tps[0][1] - tps[0][0]);
//         run_time += t1.count();
//         cout << "Thread " << this_thread::get_id() << "has ran  " << run_time << " ms" << endl;
//     }
//     cout << "Sub thread " << this_thread::get_id() << " ended." << endl;
//     thread1_ended = true; //同步标志，线程1已结束
// }

// int main()
// {
//     auto n = thread::hardware_concurrency();
//     cout << "CPU核心数为:\t" << n << endl;
//     thread myThread(Func1);
//     myThread.detach();
//     while (!thread1_ended) //同步机制等待  thread1结束
//     {
//         //此处除了  pause之外， 主线程可以做其他一切自己想做的事情
//         pause_thread_second(1);
//     }
//     pause_thread_second(1);
//     cout << "Main thread " << this_thread::get_id() << " ended." << endl;
//     return 0;
// }

// class ThreadGuard
// {
// private:
//     thread &t;

// public:
//     explicit ThreadGuard(thread &t_) : t(t_) {}
//     ~ThreadGuard()
//     {
//         if (t.joinable())
//         {
//             t.join();
//         }
//     }

//     ThreadGuard(ThreadGuard const &) = delete;
//     ThreadGuard &operator=(ThreadGuard const &) = delete;
// };

// struct func
// {
//     int &i;
//     func(int &i_) : i(i_) {}
//     void operator()()
//     {
//         for (unsigned int j = 0; j < 10000; j++)
//         {
//             cout << "Hello in func." << endl;
//         }
//     }
// };

// void PrintHello()
// {
//     cout << "Hello World." << endl;
// }

// void f()
// {
//     int some_local_state = 0;
//     func my_func(some_local_state);
//     thread t(my_func);

//     ThreadGuard g(t);
// }

// int main()
// {
//     // thread t(PrintHello);
//     // t.join();

//     auto n = thread::hardware_concurrency();
//     cout << "CPU核心数为:\t" << n << endl;

//     cout << "Main thread " << this_thread::get_id() << endl;

//     return 0;
// }

// #define NUM_THREADS 5

// void *wait(void *t)
// {
//     int i;
//     long tid;

//     tid = long(t);
//     sleep(1);
//     cout << "sleeping in thread." << endl;
//     cout << "Thread with id: " << tid << "   ...exiting" << endl;
//     pthread_exit(nullptr);
// }

// int main()
// {
//     int rc;
//     int i;
//     pthread_t threads[NUM_THREADS];
//     pthread_attr_t attr;
//     void *status;

//     // 初始化并设置线程为可连接的（joinable）
//     pthread_attr_init(&attr);
//     pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

//     for (i = 0; i < NUM_THREADS; i++)
//     {
//         cout << "main(): creating thread, " << i << endl;
//         rc = pthread_create(&threads[i], nullptr, wait, (void *)&i);
//         if (rc)
//         {
//             cerr << "Error: unable to create thread." << endl;
//             exit(EXIT_FAILURE);
//         }
//     }

//     // 删除属性 等待其他线程
//     pthread_attr_destroy(&attr);
//     for (i = 0; i < NUM_THREADS; i++)
//     {
//         rc = pthread_join(threads[i], &status);
//         if (rc)
//         {
//             cerr << "Error: unable to join." << endl;
//             exit(EXIT_FAILURE);
//         }
//         cout << "Main: completed thread id: " << i;
//         cout <<"   exiting with status: " << status << endl;
//     }

//     cout << "Main: program exiting." << endl;
//     pthread_exit(nullptr);
// }

// #define NUM_THREADS 5

// struct ThreadData
// {
//     int thread_id;
//     char *msg;
// };

// void *PrintHello(void *thread_args)
// {
//     ThreadData *my_data;
//     my_data = (ThreadData *)thread_args;
//     cout <<"Thread ID: " << my_data->thread_id << endl;
//     cout << "Thread msg: " << my_data->msg << endl;
//     pthread_exit(nullptr);
// }

// int main()
// {
//     pthread_t threads[NUM_THREADS];
//     ThreadData td[NUM_THREADS];
//     int rc;
//     int i;

//     for (i = 0;i < NUM_THREADS; i++)
//     {
//         cout << "main(): creating thread, " << i << endl;
//         td[i].thread_id = i;
//         td[i].msg = (char *)"This is a message.";
//         rc = pthread_create(&threads[i], nullptr, PrintHello, (void *)&td[i]);

//         if (rc)
//         {
//             cout << "Error: unable to create thread." << endl;
//             exit(EXIT_FAILURE);
//         }
//     }
//     pthread_exit(nullptr);
//     return 0;
// }

// #define NUM_THREADS 5
// void *PrintHello(void *thread_id)
// {
//     int tid = *((int *)thread_id);
//     cout << "Hello C++! Thread ID: " << tid << endl;
//     return 0;
// }

// int main()
// {
//     pthread_t threads[NUM_THREADS];
//     int indexes[NUM_THREADS];
//     int rc;
//     int i;
//     for (i = 0; i < NUM_THREADS; i++)
//     {
//         cout << "main(): 创建线程, " << i << endl;
//         indexes[i] = i;
//         rc = pthread_create(&threads[i], nullptr, PrintHello, (void *)&(indexes[i]));

//         if (rc)
//         {
//             cout << "Error: 无法创建线程, " << rc << endl;
//             exit(EXIT_FAILURE);
//         }
//     }

//     pthread_exit(nullptr);
//     return 0;
// }

// #define NUM_THREADS 5

// void *SayHello(void *args)
// {
//     cout << "Hello Runoob" << endl;
//     return 0;
// }

// void *FinalSay(void *args)
// {
//     cout << "It's over!" << endl;
//     return 0;
// }

// int main()
// {
//     pthread_t tid[NUM_THREADS];
//     for (int i = 0; i < NUM_THREADS; i++)
//     {
//         // 参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
//         int ret = pthread_create(&tid[i], nullptr, SayHello, nullptr);
//         if (ret != 0)
//         {
//             cout << "pthread_create error: error_code = " << ret << endl;
//         }
//     }

//     pthread_exit(nullptr);
//     return 0;
// }