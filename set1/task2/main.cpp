#include <iostream>

template <typename T, typename U>
T convert(U arg)
{
    return T(arg);
}

int main()
{
    char ch = 'A';
    std::cout << "Converted character: " << convert<int>(ch) << std::endl;

    return 0;
}