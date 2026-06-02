#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <chrono>
#include <cmath>

int main()
{
    const size_t SIZE = 10'000'000;
    std::vector<double> data(SIZE);

    // Sekwencyjnie
    std::fill(data.begin(), data.end(), 4.0);
    auto start_seq = std::chrono::high_resolution_clock::now();

    std::transform(std::execution::seq, data.begin(), data.end(), data.begin(), [](double x)
                   { return std::sqrt(x) + 1.0; });

    auto end_seq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_seq = end_seq - start_seq;
    std::cout << "[SEQ] Czas wykonania: " << duration_seq.count() << " ms\n";

    // Równolegle
    std::fill(data.begin(), data.end(), 4.0);
    auto start_par = std::chrono::high_resolution_clock::now();

    std::transform(std::execution::par, data.begin(), data.end(), data.begin(), [](double x)
                   { return std::sqrt(x) + 1.0; });

    auto end_par = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_par = end_par - start_par;
    std::cout << "[PAR] Czas wykonania: " << duration_par.count() << " ms\n";

    // Równolegle + Wektoryzacja
    std::fill(data.begin(), data.end(), 4.0);
    auto start_par_unseq = std::chrono::high_resolution_clock::now();

    std::transform(std::execution::par_unseq, data.begin(), data.end(), data.begin(), [](double x)
                   {
                       return std::sqrt(x) + 1.0; // Prosta operacja matematyczna - idealna pod SIMD
                   });

    auto end_par_unseq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_par_unseq = end_par_unseq - start_par_unseq;
    std::cout << "[PAR_UNSEQ] Czas wykonania: " << duration_par_unseq.count() << " ms\n";

    std::cout << "pierwszy element: " << data[0] << "\n"; // Powinno być 3.0

    return 0;
}