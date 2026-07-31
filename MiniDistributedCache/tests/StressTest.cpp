#include "StressTest.h"

#include <iostream>
#include <thread>
#include <vector>

void StressTest::worker(LRUCache& cache, int id)
{
    for (int i = 0; i < 5000; i++)
    {
        std::string key = "user" + std::to_string((id * 5000) + i);

        cache.put(key, "value");

        std::string value;
        cache.get(key, value);
    }
}

void StressTest::run()
{
    std::cout << "\n=====================================\n";
    std::cout << "      MULTITHREADED STRESS TEST\n";
    std::cout << "=====================================\n";

    LRUCache cache(1000);

    std::vector<std::thread> threads;

    for (int i = 0; i < 8; i++)
    {
        threads.emplace_back(&StressTest::worker,
            this,
            std::ref(cache),
            i);
    }

    for (auto& t : threads)
    {
        t.join();
    }

    cache.printStats();

    std::cout << "\nStress Test Completed Successfully.\n";
}