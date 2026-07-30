#include "DataGenerator.h"

#include <random>
#include <ctime>

static std::mt19937 rng((unsigned)time(nullptr));

std::string DataGenerator::generateKey()
{
    std::uniform_int_distribution<int> dist(1, 100);

    return "user" + std::to_string(dist(rng));
}

std::string DataGenerator::generateValue()
{
    std::uniform_int_distribution<int> dist(1000, 9999);

    return "value" + std::to_string(dist(rng));
}

Request DataGenerator::generateRequest()
{
    Request req;

    std::uniform_int_distribution<int> operationDist(1, 100);

    int chance = operationDist(rng);

    // ---------- PUT ----------
    if (chance <= 30 || insertedKeys.empty())
    {
        req.operation = "PUT";

        req.key = generateKey();

        req.value = generateValue();

        insertedKeys.push_back(req.key);
    }
    // ---------- GET ----------
    else
    {
        req.operation = "GET";

        std::uniform_int_distribution<int> hitMiss(1, 100);

        // 80% GET existing key
        if (hitMiss(rng) <= 80)
        {
            std::uniform_int_distribution<int> keyIndex(
                0,
                (int)insertedKeys.size() - 1
            );

            req.key = insertedKeys[keyIndex(rng)];
        }
        else
        {
            req.key = generateKey();
        }

        req.value = "";
    }

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