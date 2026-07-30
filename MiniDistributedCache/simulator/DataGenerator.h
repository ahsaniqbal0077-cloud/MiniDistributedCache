#pragma once

#include <string>
#include <vector>

struct Request
{
    std::string operation;   // GET or PUT
    std::string key;
    std::string value;
};

class DataGenerator
{
public:

    std::string generateKey();

    std::string generateValue();

    Request generateRequest();

    std::vector<Request> generateRequests(int count);
};
