#include <iostream>
#include <cstdlib>

struct No_checking_policy
{
    static void check_push(size_t, size_t) {}
    static void check_pop(size_t) {}
    static void check_top(size_t) {}
};

struct Abort_on_error_policy
{
    static void check_push(size_t top, size_t capacity)
    {
        if (top >= capacity)
        {
            std::cerr << "Error: Stack overflow!" << std::endl;
            std::abort();
        }
    }

    static void check_pop(size_t top)
    {
        if (top == 0)
        {
            std::cerr << "Error: Stack underflow!" << std::endl;
            std::abort();
        }
    }

    static void check_top(size_t top)
    {
        if (top == 0)
        {
            std::cerr << "Error: Stack is empty!" << std::endl;
            std::abort();
        }
    }
};

template <typename T = int, size_t N = 100, typename Checking_policy = No_checking_policy>
class Stack
{
private:
    T _rep[N];
    size_t _top = 0;

public:
    void push(const T &val)
    {
        Checking_policy::check_push(_top, N);
        _rep[_top++] = val;
    }

    void pop()
    {
        Checking_policy::check_pop(_top);
        --_top;
    }

    T &top()
    {
        Checking_policy::check_top(_top);
        return _rep[_top - 1];
    }

    bool empty() const
    {
        return _top == 0;
    }
};