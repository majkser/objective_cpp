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

template <typename LHS, typename RHS>
class AddExpr
{
    LHS lhs;
    RHS rhs;

public:
    AddExpr(const LHS &l, const RHS &r) : lhs(l), rhs(r) {};
    double operator()(double x)
    {
        return lhs(x) + rhs(x);
    }
};

template <typename LHS, typename RHS>
AddExpr<LHS, RHS> operator+(const LHS &l,
                            const RHS &r)
{
    return AddExpr<LHS, RHS>(l, r);
};

template <typename LHS>
AddExpr<LHS, Constant> operator+(const LHS &l,
                                 double r)
{
    return AddExpr<LHS, Constant>(l, Constant(r));
};
template <typename RHS>
AddExpr<Constant, RHS> operator+(double l,
                                 const RHS &r)
{
    return AddExpr<Constant, RHS>(Constant(l), r);
};

int main()
{
    Variable x;
    std::cout << ::integrate(x + 1.0, 0, 1, 0.001) << std::endl;
}