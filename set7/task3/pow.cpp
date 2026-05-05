#include <iostream>

template <int N>
inline double pow(double x)
{
    if constexpr (N % 2 == 0)
    {
        double y = pow<N / 2>(x);
        return y * y;
    }
    else
    {
        return x * pow<N - 1>(x);
    }
}

template <>
inline double pow<0>(double x)
{
    return 1.0;
}

int main()
{
    std::cout << "2^3 = " << pow<3>(2.0) << std::endl;
    std::cout << "4^0 = " << pow<0>(4.0) << std::endl;
    std::cout << "3^2 = " << pow<2>(3.0) << std::endl;
    return 0;
};