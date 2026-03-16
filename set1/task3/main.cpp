#include <iostream>

template <int N, typename T>
T dot_product(const T (&arr1)[N], const T (&arr2)[N])
{
    T result = 0;
    for (int i = 0; i < N; ++i)
    {
        result += arr1[i] * arr2[i];
    }
    return result;
}

int main()
{
    double arr1[3] = {1.0, 2.0, 1.0};
    double arr2[3] = {2.0, 2.0, 3.0};
    std::cout << "Iloczyn skalarny arr1 i arr2: "
              << dot_product(arr1, arr2)
              << std::endl;

    return 0;
}