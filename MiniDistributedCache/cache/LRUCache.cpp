#include "LRUCache.h"
#include <iostream>

LRUCache::LRUCache(size_t capacity)
{
    maxCapacity = capacity;
}

void LRUCache::put(const std::string& key,
    const std::string& value)
{
    // Key already exists
    auto it = cacheMap.find(key);

    if (it != cacheMap.end())
    {
        // Update value
        it->second->value = value;

        // Move node to front (Most Recently Used)
        cacheList.splice(cacheList.begin(), cacheList, it->second);

        return;
    }

    // Cache full?
    if (cacheList.size() >= maxCapacity)
    {
        auto last = cacheList.back();

        cacheMap.erase(last.key);

        cacheList.pop_back();
    }

    // Insert new node at front
    cacheList.push_front({ key, value });

    cacheMap[key] = cacheList.begin();
}

bool LRUCache::get(const std::string& key,
    std::string& value)
{
    auto it = cacheMap.find(key);

    // Key not found
    if (it == cacheMap.end())
    {
        stats.misses++;
        stats.requests++;
        return false;
    }

    // Cache hit
    stats.hits++;
    stats.requests++;

    // Get value
    value = it->second->value;

    // Move node to front (Most Recently Used)
    cacheList.splice(cacheList.begin(), cacheList, it->second);

    return true;
}

void LRUCache::remove(const std::string& key)
{
    auto it = cacheMap.find(key);

    if (it == cacheMap.end())
        return;

    cacheList.erase(it->second);

    cacheMap.erase(it);
}

bool LRUCache::exists(const std::string& key) const
{
    return cacheMap.find(key) != cacheMap.end();
}

void LRUCache::clear()
{
    cacheList.clear();
    cacheMap.clear();
}

size_t LRUCache::size() const
{
    return cacheMap.size();
}

size_t LRUCache::capacity() const
{
    return maxCapacity;
}

void LRUCache::printCache() const
{
    std::cout << "\n------ LRU Cache ------\n";

    for (const auto& item : cacheList)
    {
        std::cout << item.key
            << " : "
            << item.value
            << std::endl;
    }

    std::cout << "-----------------------\n";
}