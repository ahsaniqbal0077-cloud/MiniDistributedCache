#include "FIFOCache.h"

#include <iostream>

FIFOCache::FIFOCache(size_t capacity)
{
    maxCapacity = capacity;
}

void FIFOCache::put(const std::string& key,
    const std::string& value)
{
    auto it = cache.find(key);

    // Update existing value
    if (it != cache.end())
    {
        it->second = value;
        return;
    }

    // Cache full
    if (cache.size() >= maxCapacity)
    {
        std::string oldestKey = order.front();
        order.pop();

        cache.erase(oldestKey);

        stats.evictions++;
    }

    cache[key] = value;
    order.push(key);
}

bool FIFOCache::get(const std::string& key,
    std::string& value)
{
    stats.requests++;

    auto it = cache.find(key);

    if (it == cache.end())
    {
        stats.misses++;
        return false;
    }

    stats.hits++;

    value = it->second;

    return true;
}

void FIFOCache::remove(const std::string& key)
{
    cache.erase(key);
}

bool FIFOCache::exists(const std::string& key) const
{
    return cache.find(key) != cache.end();
}

void FIFOCache::clear()
{
    cache.clear();

    while (!order.empty())
    {
        order.pop();
    }
}

size_t FIFOCache::size() const
{
    return cache.size();
}

size_t FIFOCache::capacity() const
{
    return maxCapacity;
}

void FIFOCache::printCache() const
{
    std::cout << "\n------ FIFO Cache ------\n";

    for (const auto& item : cache)
    {
        std::cout
            << item.first
            << " : "
            << item.second
            << std::endl;
    }

    std::cout << "------------------------\n";
}

void FIFOCache::printStats() const
{
    std::cout << "\n===== Cache Statistics =====\n";

    std::cout << "Requests  : " << stats.requests << std::endl;
    std::cout << "Hits      : " << stats.hits << std::endl;
    std::cout << "Misses    : " << stats.misses << std::endl;
    std::cout << "Evictions : " << stats.evictions << std::endl;

    double hitRate = 0.0;

    if (stats.requests > 0)
    {
        hitRate =
            (double)stats.hits /
            stats.requests * 100.0;
    }

    std::cout << "Hit Rate  : "
        << hitRate
        << "%"
        << std::endl;

    std::cout << "============================\n";
}