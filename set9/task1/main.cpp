#include <iostream>
#include <memory>

int main()
{
    int *standard_pointer = new int(42);
    delete standard_pointer; // bez tego mielibyśmy wyciek pamięci

    std::unique_ptr<int> unique_pointer = std::make_unique<int>(42); // automatyczne zarządzanie pamięcią, nie musimy ręcznie zwalniać pamięci

    std::shared_ptr<int> shared_pointer = std::make_shared<int>(42); // automatyczne zarządzanie pamięcią, licznik referencji, obiekt zostanie zniszczony gdy licznik osiągnie zero
    std::cout << "Liczba referencji do obiektu shared_pointer: " << shared_pointer.use_count() << std::endl;
    {
        std::shared_ptr<int> shared_pointer2 = shared_pointer; // współdzielenie zarządzania pamięcią, licznik referencji zwiększa się
        std::cout << "Liczba referencji do obiektu shared_pointer po utworzeniu shared_pointer2: " << shared_pointer.use_count() << std::endl;
    }
    std::cout << "Liczba referencji do obiektu shared_pointer po zniszczeniu shared_pointer2: " << shared_pointer.use_count() << std::endl;

    return 0;
}