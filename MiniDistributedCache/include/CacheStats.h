#pragma once

struct CacheStats
{
    int hits = 0;
    int misses = 0;
    int evictions = 0;
    int requests = 0;
};