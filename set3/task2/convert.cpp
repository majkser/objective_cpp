#include <iostream>

template <typename T, typename U>
T convert(U arg)
{
    return static_cast<T>(arg);
}

template <>
int convert<int, char>(char arg)
{
    return static_cast<int>(arg);
}

template <>
double convert<double, char>(char arg)
{
    return static_cast<double>(arg);
}

int main()
{
    char ch = 'A';
    std::cout << "Converted character to int: " << convert<int>(ch) / 2 << std::endl;
    std::cout << "Converted character to double: " << convert<double>(ch) / 2 << std::endl;

    return 0;
}