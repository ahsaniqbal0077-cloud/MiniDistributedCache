#pragma once

struct CacheStats
{
    int hits = 0;
    int misses = 0;
    int evictions = 0;
    int requests = 0;

    double hitRate() const
    {
        if (requests == 0)
            return 0.0;

        return (double)hits * 100.0 / requests;
    }
};