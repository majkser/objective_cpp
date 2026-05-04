#include <iostream>

template <int T, int U>
int pow()
{
    if constexpr (U == 0)
        return 1;
    else
        return T * pow<T, U - 1>();
}

int main()
{
    std::cout << "2^3 = " << pow<2, 3>() << std::endl;
    std::cout << "4^0 = " << pow<4, 0>() << std::endl;
    std::cout << "3^2 = " << pow<3, 2>() << std::endl;
    return 0;
}