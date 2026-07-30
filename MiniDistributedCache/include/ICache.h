#pragma once

#include <string>

class ICache
{
public:
    virtual ~ICache() = default;

    virtual void put(const std::string& key,
        const std::string& value) = 0;

    virtual bool get(const std::string& key,
        std::string& value) = 0;

    virtual void remove(const std::string& key) = 0;

    virtual bool exists(const std::string& key) const = 0;

    virtual void clear() = 0;

    virtual size_t size() const = 0;

    virtual size_t capacity() const = 0;

    virtual void printCache() const = 0;
};