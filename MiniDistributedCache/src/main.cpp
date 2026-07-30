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

    std::string value;

    if (cache.get("B", value))
        cache.put("D", "400");

    std::cout << "\nAfter inserting D\n";

    cache.printCache();
    {
        std::cout << "\nFound : " << value << std::endl;
    }

    cache.printCache();

    return 0;
}