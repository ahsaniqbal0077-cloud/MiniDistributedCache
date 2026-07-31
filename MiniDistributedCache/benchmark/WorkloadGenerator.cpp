#include "WorkloadGenerator.h"

#include <cstdlib>

std::vector<WorkloadOperation>
WorkloadGenerator::generate(int operations)
{
    std::vector<WorkloadOperation> workload;

    for (int i = 0; i < operations; i++)
    {
        WorkloadOperation op;

        int random = rand() % 100;

        if (random < 30)
        {
            op.operation = "PUT";
            op.key = "user" + std::to_string(rand() % 300);
            op.value = "value" + std::to_string(rand() % 10000);
        }
        else
        {
            op.operation = "GET";
            op.key = "user" + std::to_string(rand() % 300);
        }

        workload.push_back(op);
    }

    return workload;
}