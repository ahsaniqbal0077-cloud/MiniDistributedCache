#pragma once

#include "../cache/LRUCache.h"

class StressTest
{
public:

    void run();

private:

    void worker(LRUCache& cache, int id);
};