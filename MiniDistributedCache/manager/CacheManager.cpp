#include "CacheManager.h"

#include <iostream>

CacheManager::CacheManager()
    : cache(5)
{
}

void CacheManager::start()
{
    std::cout << "\n========== Cache Manager Started ==========\n";

    auto requests = generator.generateRequests(20);

    std::string value;

    for (const auto& request : requests)
    {
        std::cout
            << request.operation
            << " "
            << request.key
            << " ";

        if (request.operation == "PUT")
        {
            std::cout << request.value << std::endl;

            cache.put(
                request.key,
                request.value
            );
        }
        else
        {
            bool found = cache.get(
                request.key,
                value
            );

            if (found)
            {
                std::cout
                    << "FOUND : "
                    << value
                    << std::endl;
            }
            else
            {
                std::cout
                    << "NOT FOUND"
                    << std::endl;
            }
        }
    }

    cache.printCache();

    cache.printStats();
}