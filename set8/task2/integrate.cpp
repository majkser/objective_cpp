#include <iostream>
#include <cmath>

template <typename F>
double integrate(F f, double min, double max, double step)
{
    double integral = 0.0;

    for (double i = min; i < max; i += step)
    {
        integral += f(i) * step;
    }

    return integral;
}

class Constant
{
    double _c;

public:
    Constant(double c) : _c(c) {};
    double operator()(double x) { return _c; }
};

class Variable
{
public:
    double operator()(double x)
    {
        return x;
    }
};

int main()
{
    std::cout << ::integrate(Constant(1.0), 0, 1, 0.001) << std::endl;
    Variable x;
    std::cout << ::integrate(x, 0, 1, 0.001) << std::endl;
}