#pragma once

#include "../cache/LRUCache.h"
#include "../cache/LFUCache.h"
#include "../cache/FIFOCache.h"

class Benchmark
{
public:

    void run();

private:

    void testLRU();

    void testLFU();

    void testFIFO();
};