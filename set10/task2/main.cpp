#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <mutex>
#include <numeric>
#include <chrono>

int main()
{
    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);

    std::vector<int> output_seq;

    auto start_seq = std::chrono::high_resolution_clock::now();

    std::for_each(std::execution::seq, vec.begin(), vec.end(),
                  [&output_seq](int elem)
                  {
                      if (elem % 2 == 0)
                      {
                          output_seq.push_back(elem);
                      }
                  });

    auto end_seq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_seq = end_seq - start_seq;

    std::cout << "Polityka [SEQ]: " << duration_seq.count() << " ms" << std::endl;

    std::vector<int> output_par;
    std::mutex output_mutex;

    auto start_par = std::chrono::high_resolution_clock::now();

    std::for_each(std::execution::par, vec.begin(), vec.end(),
                  [&output_par, &output_mutex](int elem)
                  {
                      if (elem % 2 == 0)
                      {
                          std::lock_guard<std::mutex> lock(output_mutex);
                          output_par.push_back(elem);
                      }
                  });

    auto end_par = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_par = end_par - start_par;

    std::cout << "Polityka [PAR + MUTEX]: " << duration_par.count() << " ms" << std::endl;

    return 0;
}