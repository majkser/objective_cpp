#include <iostream>

template <typename T>
class IsClass
{
    typedef char one;
    typedef struct
    {
        char c[2];
    } two;
    template <typename U>
    static one test(int U::*);
    template <typename U>
    static two test(...);

public:
    enum
    {
        yes = (sizeof(test<T>(0)) == sizeof(one))
    };
};

int main()
{
    std::cout << IsClass<int>::yes << std::endl;         // 0
    std::cout << IsClass<double>::yes << std::endl;      // 0
    std::cout << IsClass<std::string>::yes << std::endl; // 1
    return 0;
}