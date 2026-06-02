#include <compare>
#include <concepts>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Point
{
    int x;
    int y;

    auto operator<=>(const Point &other) const = default;
};

static_assert(std::three_way_comparable<Point>);
static_assert(std::three_way_comparable<int>);

template <std::three_way_comparable T>
bool is_less(const T &a, const T &b)
{
    return (a <=> b) < 0;
}

int main()
{
    Point a{1, 2};
    Point b{2, 1};

    std::cout << std::boolalpha;
    std::cout << "Point a < b: " << is_less(a, b) << "\n";
    std::cout << "int 3 < 7: " << is_less(3, 7) << "\n";

    std::vector<Point> points{{2, 2}, {1, 5}, {1, 2}};
    std::ranges::sort(points);

    std::cout << "Sorted points:\n";
    for (const auto &p : points)
    {
        std::cout << "(" << p.x << ", " << p.y << ")\n";
    }

    // struct NoCompare { int v; };
    // static_assert(std::three_way_comparable<NoCompare>); // Blad kompilacji.

    return 0;
}