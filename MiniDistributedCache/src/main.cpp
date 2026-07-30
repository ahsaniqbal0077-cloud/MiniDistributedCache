#include <iostream>
#include "../cache/LRUCache.h"
#include "../simulator/DataGenerator.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " Mini Distributed Cache System\n";
    std::cout << " Redis Inspired Project\n";
    std::cout << "=====================================\n\n";

    // ==========================
    // LRU CACHE TEST
    // ==========================

    LRUCache cache(3);

    cache.put("A", "100");
    cache.put("B", "200");
    cache.put("C", "300");

    std::string value;

    // HIT
    cache.get("B", value);

    // MISS
    cache.get("X", value);

    // Eviction
    cache.put("D", "400");

    cache.printCache();
    cache.printStats();

    // ==========================
    // DATA GENERATOR TEST
    // ==========================

    std::cout << "\n===== Generated Requests =====\n";

    DataGenerator generator;

    auto requests = generator.generateRequests(10);

    for (const auto& request : requests)
    {
        std::cout
            << request.operation << "    "
            << request.key << "    "
            << request.value
            << std::endl;
    }

    return 0;
}