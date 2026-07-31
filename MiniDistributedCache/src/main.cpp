#include <iostream>
#include "../cache/FIFOCache.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " FIFO Cache Test\n";
    std::cout << "=====================================\n";

    FIFOCache cache(3);

    std::string value;

    cache.put("A", "100");
    cache.put("B", "200");
    cache.put("C", "300");

    // FIFO -> A sabse pehle aaya tha
    cache.put("D", "400");

    cache.printCache();

    std::cout << "\nTesting GET...\n";

    if (cache.get("A", value))
        std::cout << "A Found : " << value << std::endl;
    else
        std::cout << "A Not Found\n";

    if (cache.get("D", value))
        std::cout << "D Found : " << value << std::endl;

    cache.printStats();

    return 0;
}