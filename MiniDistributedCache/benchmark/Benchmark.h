#pragma once

#include "../cache/LRUCache.h"
#include "../cache/LFUCache.h"
#include "../cache/FIFOCache.h"
#include "WorkloadGenerator.h"

#include <vector>

class Benchmark
{
public:

    void run();

private:

    std::vector<WorkloadOperation> workload;

    void testLRU();

    void testLFU();

    void testFIFO();
};