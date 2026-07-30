#include <iostream>
#include "../manager/CacheManager.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " Mini Distributed Cache System\n";
    std::cout << " Redis Inspired Project\n";
    std::cout << "=====================================\n";

    CacheManager manager;

    manager.start();

    return 0;
}