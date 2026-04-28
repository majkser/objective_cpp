#include <iostream>

template <typename T>
class IsNestedType
{
    typedef char one;
    typedef struct
    {
        char c[2];
    } two;
    template <typename U>
    static one test(typename U::value_type *);
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
    std::cout << IsNestedType<int>::yes << std::endl;              // 0
    std::cout << IsNestedType<std::vector<int>>::yes << std::endl; // 1
    return 0;
}