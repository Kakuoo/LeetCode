#include <iostream>
#include <string>
using namespace std;

class CPU
{
public:
    virtual void calculator() = 0;
};

class VideoCard
{
public:
    virtual void display() = 0;
};

class Memory
{
public:
    virtual void storage() = 0;
};

// 组装
class Computer
{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem)
    {
        this->m_cpu = cpu;
        this->m_vc = vc;
        this->m_mem = mem;
    }

    void work()
    {
        this->m_cpu->calculator();
        this->m_vc->display();
        this->m_mem->storage();
    }

private:
    CPU *m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
};

// 具体厂商
class IntelCpu : public CPU
{
public:
    virtual void calculator()
    {
        cout << "Interl CPU" << endl;
    }
};

class LenovoCpu : public CPU
{
public:
    virtual void calculator()
    {
        cout << "Lenovo CPU" << endl;
    }
};

// class Animal
// {
// public:
//     Animal() { cout << "Animal Construction" << endl; }
//     // virtual ~Animal() { cout << "Animal Deconstruction" << endl; }
//     virtual ~Animal() = 0;
//     virtual void speak() = 0;
// };

// Animal::~Animal()
// {
//     cout << "Animal 纯虚 Deconstruction" << endl;
// }

// class Cat : public Animal
// {
// public:
//     Cat(string name) /*  :  m_name(new string(name)) */
//     {
//         cout << "Cat Construction" << endl;
//         m_name = new string(name);
//     }

//     ~Cat()
//     {
//         if (m_name != nullptr)
//         {
//             cout << "Cat Deconstruction" << endl;
//             delete m_name;
//             m_name = nullptr;
//         }
//     }

//     virtual void speak()
//     {
//         cout << "Cat " << *m_name << endl;
//     }

//     string *m_name;
// };

// void test()
// {
//     Animal *animal = new Cat("Tom");
//     animal->speak();
//     delete animal;
// }

// int main()
// {
//     test();
//     return EXIT_SUCCESS;
// }

// class AbstractDrink
// {
// public:
//     virtual void Boil() = 0;
//     virtual void Brew() = 0;
//     virtual void PourInCup() = 0;
//     virtual void PutSomething() = 0;

//     void MakeDrink()
//     {
//         Boil();
//         Brew();
//         PourInCup();
//         PutSomething();
//     }
// };

// class Coffee : public AbstractDrink
// {
// public:
//     virtual void Boil()
//     {
//         cout << "Boil" << endl;
//     }

//     virtual void Brew()
//     {
//         cout << "Brew" << endl;
//     }

//     virtual void PourInCup()
//     {
//         cout << "PourInCup" << endl;
//     }

//     virtual void PutSomething()
//     {
//         cout << "PutSomething" << endl;
//     }
// };

// class Tea : public AbstractDrink
// {
// public:
//     virtual void Boil()
//     {
//         cout << "Boil" << endl;
//     }

//     virtual void Brew()
//     {
//         cout << "Brew" << endl;
//     }

//     virtual void PourInCup()
//     {
//         cout << "PourInCup" << endl;
//     }

//     virtual void PutSomething()
//     {
//         cout << "PutSomething" << endl;
//     }
// };

// void Dowork(AbstractDrink *abc)
// {
//     abc->MakeDrink();
//     delete abc;
// }

// void test()
// {
//     Dowork(new Coffee);
// }

// int main()
// {
//     test();
//     return 0;
// }

// class AbstractCalculator
// {
// public:
//     // virtual int get_result()
//     // {
//     //     return 0;
//     // }

//     virtual int get_result() = 0;

//     int m_num1;
//     int m_num2;
// };

// class AddCalculator : public AbstractCalculator
// {
// public:
//     virtual int get_result()
//     {
//         return m_num1 + m_num2;
//     }
// };

// class SubCalculator : public AbstractCalculator
// {
// public:
//     virtual int get_result()
//     {
//         return m_num1 - m_num2;
//     }
// };

// class MulCalculator : public AbstractCalculator
// {
// public:
//     virtual int get_result()
//     {
//         return m_num1 * m_num2;
//     }
// };

// void test()
// {
//     AbstractCalculator *abc = new AddCalculator;
//     abc->m_num1 = 10;
//     abc->m_num2 = 20;
//     cout << abc->get_result() << endl;;
//     delete abc;
// }

// int main()
// {
//     test();
//     return 0;
// }