#include <concepts>
#include <iostream>

template <std::integral T>
T najwiekszy_wspolny_dzielnik(T a, T b)
{
    if (a < 0)
    {
        a = -a;
    }
    if (b < 0)
    {
        b = -b;
    }

    while (b != 0)
    {
        T r = a % b;
        a = b;
        b = r;
    }

    return a;
}

template <std::integral T>
T najmniejsza_wspolna_wielokrotnosc(T a, T b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }

    T g = najwiekszy_wspolny_dzielnik(a, b);
    return (a / g) * b;
}

template <std::integral T>
bool jest_parzysta(T value)
{
    return (value % 2) == 0;
}

int main()
{
    std::cout << "najwiekszy_wspolny_dzielnik(48, 18) = " << najwiekszy_wspolny_dzielnik(48, 18) << "\n";
    std::cout << "najmniejsza_wspolna_wielokrotnosc(6, 15) = " << najmniejsza_wspolna_wielokrotnosc(6, 15) << "\n";
    std::cout << "jest_parzysta(42) = " << std::boolalpha << jest_parzysta(42) << "\n";

    // najwiekszy_wspolny_dzielnik(3.14, 1.57); // Blad kompilacji: double nie spelnia std::integral.

    return 0;
}