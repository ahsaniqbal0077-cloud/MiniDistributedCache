#pragma once

#include <string>

struct CacheItem
{
    std::string key;
    std::string value;

    int frequency = 1;
};