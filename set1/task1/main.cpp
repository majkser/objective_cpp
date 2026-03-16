#include <iostream>

template <typename T>
T maksimum(T num1, T num2)
{
    return (num1 > num2) ? num1 : num2;
}

int main()
{
    int a = 1, b = 2;
    double c = 1.5, d = 2.5;

    std::cout << "MAX of " << a << " and " << b << " is " << maksimum(a, b) << std::endl;
    std::cout << "MAX of " << c << " and " << d << " is " << maksimum(c, d) << std::endl;

    return 0;
}