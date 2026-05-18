#include <iostream>
#include <memory>

struct B;

class A
{
public:
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "[Destruktor A]" << std::endl; }
};

class B
{
public:
    std::weak_ptr<A> a_ptr;
    ~B() { std::cout << "[Destruktor B]" << std::endl; }
};

int main()
{
    std::cout << "--- Start ---\n";
    {
        auto obiektA = std::make_shared<A>();
        auto obiektB = std::make_shared<B>();

        std::cout << "Liczba referencji do obiektu A: " << obiektA.use_count() << std::endl;
        std::cout << "Liczba referencji do obiektu B: " << obiektB.use_count() << std::endl;

        obiektA->b_ptr = obiektB;
        obiektB->a_ptr = obiektA;

        std::cout << "Liczba referencji do obiektu A: " << obiektA.use_count() << std::endl;
        std::cout << "Liczba referencji do obiektu B: " << obiektB.use_count() << std::endl;
    }

    std::cout << "Koniec programu brak wyciekow pamieci mimo cyklicznych referencji" << std::endl;
}