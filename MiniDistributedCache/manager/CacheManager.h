#pragma once

#include "../cache/LRUCache.h"
#include "../simulator/DataGenerator.h"

class CacheManager
{
private:

    LRUCache cache;

    DataGenerator generator;

public:

    CacheManager();

    void start();
};
