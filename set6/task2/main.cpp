#include <iostream>
#include "stack.cpp"

int main()
{
    std::cout << "Test No_checking_policy (domyslna):" << std::endl;
    Stack<int, 2> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30); // Nie będzie zgłaszać błędu, mimo przekroczenia pojemności

    std::cout << "Test Abort_on_error_policy:" << std::endl;
    Stack<int, 2, Abort_on_error_policy> s2;
    s2.push(100);
    s2.push(200);
    s2.push(300); // To powinno zgłosić błąd przepełnienia

    return 0;
}
