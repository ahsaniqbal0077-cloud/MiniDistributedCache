#pragma once

#include "../include/ICache.h"
#include "../include/CacheStats.h"

#include <unordered_map>
#include <queue>
#include <string>

class FIFOCache : public ICache
{
private:

    size_t maxCapacity;

    std::unordered_map<
        std::string,
        std::string
    > cache;

    std::queue<std::string> order;

    CacheStats stats;

public:

    FIFOCache(size_t capacity);

    void put(
        const std::string& key,
        const std::string& value
    ) override;

    bool get(
        const std::string& key,
        std::string& value
    ) override;

    void remove(
        const std::string& key
    ) override;

    bool exists(
        const std::string& key
    ) const override;

    void clear() override;

    size_t size() const override;

    size_t capacity() const override;

    void printCache() const override;

    void printStats() const;
};
