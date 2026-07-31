#include "Benchmark.h"
#include "WorkloadGenerator.h"

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void Benchmark::run()
{
    cout << "\n=====================================\n";
    cout << "       CACHE BENCHMARK\n";
    cout << "=====================================\n";

    WorkloadGenerator generator;
    workload = generator.generate(10000);

    testLRU();
    testLFU();
    testFIFO();
}

void Benchmark::testLRU()
{
    auto start = high_resolution_clock::now();

    LRUCache cache(100);
    string value;

    for (const auto& op : workload)
    {
        if (op.operation == "PUT")
            cache.put(op.key, op.value);
        else
            cache.get(op.key, value);
    }

    auto end = high_resolution_clock::now();

    cout << "\n========== LRU ==========\n";
    cache.printStats();

    cout << "Execution Time : "
        << duration_cast<milliseconds>(end - start).count()
        << " ms\n";
}

void Benchmark::testLFU()
{
    auto start = high_resolution_clock::now();

    LFUCache cache(100);
    string value;

    for (const auto& op : workload)
    {
        if (op.operation == "PUT")
            cache.put(op.key, op.value);
        else
            cache.get(op.key, value);
    }

    auto end = high_resolution_clock::now();

    cout << "\n========== LFU ==========\n";
    cache.printStats();

    cout << "Execution Time : "
        << duration_cast<milliseconds>(end - start).count()
        << " ms\n";
}

void Benchmark::testFIFO()
{
    auto start = high_resolution_clock::now();

    FIFOCache cache(100);
    string value;

    for (const auto& op : workload)
    {
        if (op.operation == "PUT")
            cache.put(op.key, op.value);
        else
            cache.get(op.key, value);
    }

    auto end = high_resolution_clock::now();

    cout << "\n========== FIFO ==========\n";
    cache.printStats();

    cout << "Execution Time : "
        << duration_cast<milliseconds>(end - start).count()
        << " ms\n";
}