#pragma once

#include "../include/ICache.h"
#include "../include/CacheStats.h"

#include <unordered_map>
#include <string>

class LFUCache : public ICache
{
private:

    struct Node
    {
        std::string key;
        std::string value;
        int frequency = 1;
    };

    size_t maxCapacity;

    std::unordered_map<
        std::string,
        Node
    > cache;

    CacheStats stats;

public:

    LFUCache(size_t capacity);

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
