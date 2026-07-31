#include "Benchmark.h"

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void Benchmark::run()
{
    std::cout << "\n=====================================\n";
    std::cout << "       CACHE BENCHMARK\n";
    std::cout << "=====================================\n";

    testLRU();

    testLFU();

    testFIFO();
}

void Benchmark::testLRU()
{
    auto start = high_resolution_clock::now();

    LRUCache cache(100);

    std::string value;

    for (int i = 0; i < 10000; i++)
    {
        cache.put(
            "user" + std::to_string(i % 200),
            "value" + std::to_string(i)
        );

        cache.get(
            "user" + std::to_string(i % 200),
            value
        );
    }

    auto end = high_resolution_clock::now();

    auto duration =
        duration_cast<milliseconds>(end - start);

    std::cout << "\n========== LRU ==========\n";

    cache.printStats();

    std::cout << "Execution Time : "
        << duration.count()
        << " ms\n";
}

void Benchmark::testLFU()
{
    auto start = high_resolution_clock::now();

    LFUCache cache(100);

    std::string value;

    for (int i = 0; i < 10000; i++)
    {
        cache.put(
            "user" + std::to_string(i % 200),
            "value" + std::to_string(i)
        );

        cache.get(
            "user" + std::to_string(i % 200),
            value
        );
    }

    auto end = high_resolution_clock::now();

    auto duration =
        duration_cast<milliseconds>(end - start);

    std::cout << "\n========== LFU ==========\n";

    cache.printStats();

    std::cout << "Execution Time : "
        << duration.count()
        << " ms\n";
}

void Benchmark::testFIFO()
{
    auto start = high_resolution_clock::now();

    FIFOCache cache(100);

    std::string value;

    for (int i = 0; i < 10000; i++)
    {
        cache.put(
            "user" + std::to_string(i % 200),
            "value" + std::to_string(i)
        );

        cache.get(
            "user" + std::to_string(i % 200),
            value
        );
    }

    auto end = high_resolution_clock::now();

    auto duration =
        duration_cast<milliseconds>(end - start);

    std::cout << "\n========== FIFO ==========\n";

    cache.printStats();

    std::cout << "Execution Time : "
        << duration.count()
        << " ms\n";
}