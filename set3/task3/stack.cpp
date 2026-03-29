#include <iostream>

template <typename T, int N = 100>
class Stack
{
public:
    void print()
    {
        std::cout << "Base Stack: T = " << typeid(T).name() << ", N = " << N << std::endl;
    }
};

template <typename T>
class Stack<T, 666>
{
public:
    void print()
    {
        std::cout << "Specialized Stack: T = " << typeid(T).name() << ", N = 666" << std::endl;
    }
};

template <typename T, int N>
class Stack<T *, N>
{
public:
    void print()
    {
        std::cout << "Specialized Pointer Stack: T = " << typeid(T).name() << ", N = " << N << std::endl;
    }
};

template <int N>
class Stack<double, N>
{
public:
    void print()
    {
        std::cout << "Specialized Stack for double: T = double, N = " << N << std::endl;
    }
};

template <int N>
class Stack<int *, N>
{
public:
    void print()
    {
        std::cout << "Specialized Stack for int*: T = int*, N = " << N << std::endl;
    }
};

template <>
class Stack<double, 666>
{
public:
    void print()
    {
        std::cout << "Specialized Stack for double: T = double, N = 666" << std::endl;
    }
};

template <>
class Stack<double *, 44>
{
public:
    void print()
    {
        std::cout << "Specialized Stack for double*: T = double*, N = 44" << std::endl;
    }
};

int main()
{
    Stack<int> s1;
    s1.print();

    Stack<double, 666> s2;
    s2.print();

    Stack<char *, 50> s3;
    s3.print();

    Stack<double, 44> s4;
    s4.print();

    Stack<int *, 100> s5;
    s5.print();

    return 0;
}