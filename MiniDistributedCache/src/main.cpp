#include <iostream>
#include "../tests/StressTest.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " Mini Distributed Cache System\n";
    std::cout << " Stress Test Mode\n";
    std::cout << "=====================================\n";

    StressTest test;

    test.run();

    return 0;
}