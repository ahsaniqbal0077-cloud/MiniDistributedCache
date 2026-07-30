#include "DataGenerator.h"

#include <random>
#include <ctime>

std::string DataGenerator::generateKey()
{
    static std::mt19937 rng((unsigned)time(nullptr));

    std::uniform_int_distribution<int> dist(1, 1000);

    return "user" + std::to_string(dist(rng));
}

std::string DataGenerator::generateValue()
{
    static std::mt19937 rng((unsigned)time(nullptr) + 10);

    std::uniform_int_distribution<int> dist(1000, 9999);

    return "value" + std::to_string(dist(rng));
}

Request DataGenerator::generateRequest()
{
    static std::mt19937 rng((unsigned)time(nullptr) + 20);

    std::uniform_int_distribution<int> opDist(1, 100);

    Request req;

    if (opDist(rng) <= 70)
        req.operation = "GET";
    else
        req.operation = "PUT";

    req.key = generateKey();
    req.value = generateValue();

    return req;
}

std::vector<Request> DataGenerator::generateRequests(int count)
{
    std::vector<Request> requests;

    requests.reserve(count);

    for (int i = 0; i < count; i++)
    {
        requests.push_back(generateRequest());
    }

    return requests;
}