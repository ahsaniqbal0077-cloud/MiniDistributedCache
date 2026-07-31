#include "LFUCache.h"

#include <iostream>
#include <limits>

LFUCache::LFUCache(size_t capacity)
{
    maxCapacity = capacity;
}

void LFUCache::put(const std::string& key,
    const std::string& value)
{
    // Key already exists
    auto it = cache.find(key);

    if (it != cache.end())
    {
        it->second.value = value;
        it->second.frequency++;
        return;
    }

    // Cache full
    if (cache.size() >= maxCapacity)
    {
        std::string removeKey;
        int minFrequency = std::numeric_limits<int>::max();

        for (const auto& item : cache)
        {
            if (item.second.frequency < minFrequency)
            {
                minFrequency = item.second.frequency;
                removeKey = item.first;
            }
        }

        cache.erase(removeKey);
        stats.evictions++;
    }

    Node node;
    node.key = key;
    node.value = value;
    node.frequency = 1;

    cache[key] = node;
}

bool LFUCache::get(const std::string& key,
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

    value = it->second.value;

    it->second.frequency++;

    return true;
}

void LFUCache::remove(const std::string& key)
{
    cache.erase(key);
}

bool LFUCache::exists(const std::string& key) const
{
    return cache.find(key) != cache.end();
}

void LFUCache::clear()
{
    cache.clear();
}

size_t LFUCache::size() const
{
    return cache.size();
}

size_t LFUCache::capacity() const
{
    return maxCapacity;
}

void LFUCache::printCache() const
{
    std::cout << "\n------ LFU Cache ------\n";

    for (const auto& item : cache)
    {
        std::cout
            << item.second.key
            << " : "
            << item.second.value
            << " (Freq="
            << item.second.frequency
            << ")"
            << std::endl;
    }

    std::cout << "-----------------------\n";
}

void LFUCache::printStats() const
{
    std::cout << "\n===== Cache Statistics =====\n";

    std::cout << "Requests  : " << stats.requests << std::endl;
    std::cout << "Hits      : " << stats.hits << std::endl;
    std::cout << "Misses    : " << stats.misses << std::endl;
    std::cout << "Evictions : " << stats.evictions << std::endl;

    double hitRate = 0;

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