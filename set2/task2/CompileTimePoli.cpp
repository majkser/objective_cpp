#include "CompileTimePoli.h"

#include <iostream>

void CompileTimePoli::add(int a, int b)
{
    std::cout << "Sum of two integers: " << a + b << std::endl;
}

void CompileTimePoli::add(const std::string &a, const std::string &b)
{
    std::cout << "String Concatenation: " << a + b << std::endl;
}