#include <iostream>
#include "../cache/LFUCache.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " LFU Cache Test\n";
    std::cout << "=====================================\n";

    LFUCache cache(3);

    std::string value;

    cache.put("A", "100");
    cache.put("B", "200");
    cache.put("C", "300");

    // Frequency:
    // A = 3
    // B = 2
    // C = 1

    cache.get("A", value);
    cache.get("A", value);

    cache.get("B", value);

    // Cache full -> C remove hoga
    cache.put("D", "400");

    cache.printCache();

    cache.printStats();

    return 0;
}