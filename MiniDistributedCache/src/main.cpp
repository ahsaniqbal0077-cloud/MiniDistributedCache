#include <iostream>
#include "../benchmark/Benchmark.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " Mini Distributed Cache System\n";
    std::cout << " Benchmark Mode\n";
    std::cout << "=====================================\n";

    Benchmark benchmark;

    benchmark.run();

    return 0;
}