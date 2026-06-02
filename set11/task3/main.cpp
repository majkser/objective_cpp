#include <concepts>
#include <iostream>
#include <vector>

template <typename T>
class MyVector
{
public:
    void push_back(const T &value)
        requires std::copyable<T>
    {
        data.push_back(value);
    }

    std::size_t size() const
    {
        return data.size();
    }

private:
    std::vector<T> data;
};

class NonCopyable
{
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;
};

int main()
{
    MyVector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);

    std::cout << "numbers size: " << numbers.size() << "\n";

    MyVector<NonCopyable> bad;
    NonCopyable nc;
    // bad.push_back(nc); // Blad kompilacji: NonCopyable nie spelnia std::copyable.

    return 0;
}
