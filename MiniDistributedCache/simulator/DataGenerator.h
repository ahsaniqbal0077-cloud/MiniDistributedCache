#pragma once

#include <string>
#include <vector>

struct Request
{
    std::string operation;
    std::string key;
    std::string value;
};

class DataGenerator
{
private:

    std::vector<std::string> insertedKeys;

public:

    std::string generateKey();

    std::string generateValue();

    Request generateRequest();

    std::vector<Request> generateRequests(int count);
};