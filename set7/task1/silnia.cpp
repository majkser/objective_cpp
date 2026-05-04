#include <iostream>

template <int T>
int silnia()
{
    return T * silnia<T - 1>();
}

template <>
int silnia<0>()
{
    return 1;
}

int main()
{
    std::cout << "Silnia z 0: " << silnia<0>() << std::endl;
    std::cout << "Silnia z 3: " << silnia<3>() << std::endl;
    return 0;
}