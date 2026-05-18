#include <iostream>
#include <memory>

int main()
{
    int *standard_pointer = new int(42);
    std::unique_ptr<int> unique_pointer = std::make_unique<int>(42);
    std::shared_ptr<int> shared_pointer = std::make_shared<int>(42);
    std::weak_ptr<int> weak_pointer = shared_pointer;

    std::cout << "Rozmiar standardowego wskaźnika: " << sizeof(standard_pointer) << std::endl;
    std::cout << "Rozmiar inteligentnego (Unique) wskaźnika: " << sizeof(unique_pointer) << std::endl;
    std::cout << "Rozmiar inteligentnego (Shared) wskaźnika: " << sizeof(shared_pointer) << std::endl;
    std::cout << "Rozmiar inteligentnego (Weak) wskaźnika: " << sizeof(weak_pointer) << std::endl;

    delete standard_pointer;
    return 0;
}