#include "RunTimePoli.h"

#include <iostream>

void RunTimePoliBase::print() const
{
    std::cout << "Base class print function" << std::endl;
}

void RunTimePoliDerived::print() const
{
    std::cout << "Derived class print function" << std::endl;
}