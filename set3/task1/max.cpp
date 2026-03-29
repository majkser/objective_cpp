#include <iostream>
#include <cstring>

template <typename T>
T max(T num1, T num2)
{
    return (num1 > num2) ? num1 : num2;
}

template <typename T>
T max(T *a, T *b)
{
    return (*a > *b) ? *a : *b;
}

template <typename T>
T max(T *data, size_t n)
{
    T max_value = data[0];
    for (size_t i = 1; i < n; i++)
    {
        if (data[i] > max_value)
        {
            max_value = data[i];
        }
    }
    return max_value;
}

template <>
char *
max(char *a, char *b)
{
    return (strcmp(a, b) > 0) ? a : b;
}

template <>
const char *
max(const char *a, const char *b)
{
    return (strcmp(a, b) > 0) ? a : b;
}

template <typename T>
const T *max(T *a, const T *b)
{
    return (*a) > (*b) ? a : b;
}

int main()
{
    // Test: max(T, T)
    std::cout << "max(T, T): max(5, 10) = " << max(5, 10) << std::endl;
    std::cout << "max(T, T): max(5.5, 2.2) = " << max(5.5, 2.2) << std::endl;

    // Test: max(char*, char*)
    char a1[] = "apple";
    char a2[] = "banana";
    std::cout << "max(char*, char*): max(\"apple\", \"banana\") = " << max<char *>(a1, a2) << std::endl;

    // Test: max(const char*, const char*)
    const char *ca1 = "apple";
    const char *ca2 = "banana";
    std::cout << "max(const char*, const char*): max(\"apple\", \"banana\") = " << max<const char *>(ca1, ca2) << std::endl;

    // Test: max(T*, T*)
    int val1 = 5, val2 = 11;
    int *p1 = &val1, *p2 = &val2;
    std::cout << "max(T*, T*): max(p1(5), p2(11)) returns max value = " << max(p1, p2) << std::endl;

    // Test: max(T*, const T*)
    const int c_val2 = 15;
    const int *c_p2 = &c_val2;
    std::cout << "max(T*, const T*): max(p1(5), c_p2(15)) returns a pointer, value = " << *max(p1, c_p2) << std::endl;

    // Test: max(T*, size_t)
    int arr[] = {3, 1, 4, 1, 5, 21, 37};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "max(T*, size_t): max(arr) returns max value = " << max(arr, arr_size) << std::endl;

    // Test: max(std::string*, std::string*)
    std::string *str1 = new std::string("Hello");
    std::string *str2 = new std::string("World");
    std::cout << "max(std::string*, std::string*): max(str1, str2) returns max string = " << max(str1, str2) << std::endl;

    delete str1;
    delete str2;

    return 0;
}