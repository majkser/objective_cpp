#include <iostream>

template <int T>
long long silnia()
{
    return T * silnia<T - 1>();
}

template <>
long long silnia<0>()
{
    return 1;
}

template <int N>
inline double pow(double x)
{
    return x * pow<N - 1>(x);
}

template <>
inline double pow<0>(double x)
{
    return 1.0;
}

template <int N>
inline double sin(double x)
{
    double sign = (N % 2 == 0) ? -1.0 : 1.0;
    return sin<N - 1>(x) + sign * pow<2 * N - 1>(x) / silnia<2 * N - 1>();
}

template <>
inline double sin<0>(double x)
{
    return 0.0;
}

int main()
{
    std::cout << "sin(pi/2) [5 wyrazow] = " << sin<5>(3.14159265 / 2.0) << std::endl;
    std::cout << "sin(pi/2) [10 wyrazow] = " << sin<10>(3.14159265 / 2.0) << std::endl;

    std::cout << "sin(pi/6) [5 wyrazow] = " << sin<5>(3.14159265 / 6.0) << std::endl;
    std::cout << "sin(pi/6) [10 wyrazow] = " << sin<10>(3.14159265 / 6.0) << std::endl;

    std::cout << "sin(pi) [5 wyrazow] = " << sin<5>(3.14159265) << std::endl;
    std::cout << "sin(pi) [10 wyrazow] = " << sin<10>(3.14159265) << std::endl;
    return 0;
}