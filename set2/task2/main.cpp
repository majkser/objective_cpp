#include "CompileTimePoli.h"
#include "RunTimePoli.h"

int main()
{
    CompileTimePoli compileTimePoli;
    compileTimePoli.add(6, 7);
    compileTimePoli.add("Hello, ", "World!");

    RunTimePoliDerived derived;
    RunTimePoliBase &baseRef = derived;
    baseRef.print();

    RunTimePoliBase base;
    base.print();

    return 0;
}