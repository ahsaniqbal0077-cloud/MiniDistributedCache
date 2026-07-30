#include <iostream>
#include "../cache/LRUCache.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " Mini Distributed Cache System\n";
    std::cout << " Redis Inspired Project\n";
    std::cout << "=====================================\n";

    LRUCache cache(3);

    cache.put("A", "100");
    cache.put("B", "200");
    cache.put("C", "300");

    cache.printCache();

    cache.put("B", "999");

    cache.printCache();
    return 0;
}