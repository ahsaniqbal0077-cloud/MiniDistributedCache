#include <iostream>
#include "../network/TCPServer.h"

int main()
{
    std::cout << "=====================================\n";
    std::cout << " Mini Distributed Cache System\n";
    std::cout << " TCP Server Mode\n";
    std::cout << "=====================================\n";

    TCPServer server(5000);

    if (server.start())
    {
        std::cout << "Server Initialized Successfully\n";
    }

    return 0;
}