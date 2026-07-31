#pragma once

#include <string>
#include <vector>

struct WorkloadOperation
{
    std::string operation;
    std::string key;
    std::string value;
};

class WorkloadGenerator
{
public:

    std::vector<WorkloadOperation> generate(int operations);
};