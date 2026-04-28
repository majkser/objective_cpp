#include <iostream>

template <typename T>
struct sum_traits;

template <>
struct sum_traits<char>
{
    typedef int sum_type;
};

template <>
struct sum_traits<int>
{
    typedef long int sum_type;
};

template <>
struct sum_traits<float>
{
    typedef double sum_type;
};

template <>
struct sum_traits<double>
{
    typedef double sum_type;
};

template <typename T>
typename sum_traits<T>::sum_type sum(const T *beg, const T *end)
{
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_type();
    while (beg != end)
    {
        total += *beg;
        beg++;
    }
    return total;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << sum(&arr[0], &arr[5]) << std::endl;

    float farr[] = {1.1f, 2.2f, 3.3f};
    std::cout << sum(&farr[0], &farr[3]) << std::endl;

    double darr[] = {1.1, 2.2, 3.3};
    std::cout << sum(&darr[0], &darr[3]) << std::endl;

    char carr[] = {'a', 'b', 'c'};
    std::cout << sum(&carr[0], &carr[3]) << std::endl;

    return 0;
}
