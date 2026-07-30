#include "LRUCache.h"
#include <iostream>

LRUCache::LRUCache(size_t capacity)
{
    maxCapacity = capacity;
}

void LRUCache::put(const std::string& key,
    const std::string& value)
{
    auto it = cacheMap.find(key);

    // Key already exists
    if (it != cacheMap.end())
    {
        it->second->value = value;

        cacheList.splice(
            cacheList.begin(),
            cacheList,
            it->second
        );

        cacheMap[key] = cacheList.begin();

        return;
    }

    // Cache full
    if (cacheList.size() >= maxCapacity)
    {
        auto last = cacheList.back();

        cacheMap.erase(last.key);
        cacheList.pop_back();

        stats.evictions++;
    }

    cacheList.push_front({ key, value });

    cacheMap[key] = cacheList.begin();
}

bool LRUCache::get(const std::string& key,
    std::string& value)
{
    stats.requests++;

    auto it = cacheMap.find(key);

    if (it == cacheMap.end())
    {
        stats.misses++;
        return false;
    }

    stats.hits++;

    value = it->second->value;

    cacheList.splice(
        cacheList.begin(),
        cacheList,
        it->second
    );

    cacheMap[key] = cacheList.begin();

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

void LRUCache::printStats() const
{
    std::cout << "\n===== Cache Statistics =====\n";

    std::cout << "Requests  : " << stats.requests << std::endl;
    std::cout << "Hits      : " << stats.hits << std::endl;
    std::cout << "Misses    : " << stats.misses << std::endl;
    std::cout << "Evictions : " << stats.evictions << std::endl;
    std::cout << "Hit Rate  : " << stats.hitRate() << "%" << std::endl;

    std::cout << "============================\n";
}