#include <iostream>
#include <memory>

namespace myNamespace
{

    template <class T, class... Args>
    std::enable_if_t<!std::is_array_v<T>,
                     std::unique_ptr<T>>
    make_unique(Args &&...args)
    {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    template <class T>
    std::enable_if_t<std::is_unbounded_array_v<T>,
                     std::unique_ptr<T>>
    make_unique(std::size_t size)
    {
        return std::unique_ptr<T>(new std::remove_extent_t<T>[size]());
    }

}

int main()
{
    auto obj = myNamespace::make_unique<int>(42);
    std::cout << *obj << "\n";

    auto arr = myNamespace::make_unique<int[]>(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
}