#include "TCPServer.h"

#include <iostream>

TCPServer::TCPServer(int p)
{
    port = p;
    serverSocket = INVALID_SOCKET;
}

TCPServer::~TCPServer()
{
    stop();
}

bool TCPServer::start()
{
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cout << "WSAStartup Failed\n";
        return false;
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (serverSocket == INVALID_SOCKET)
    {
        std::cout << "Socket Creation Failed\n";

        WSACleanup();

        return false;
    }

    std::cout << "Socket Created Successfully\n";

    // Configure Server Address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    // Bind Socket
    if (bind(
        serverSocket,
        (sockaddr*)&serverAddress,
        sizeof(serverAddress)
    ) == SOCKET_ERROR)
    {
        std::cout << "Bind Failed. Error Code: "
            << WSAGetLastError()
            << std::endl;

        return false;
    }

    std::cout << "Bind Successful\n";

    // Start Listening
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cout << "Listen Failed\n";

        closesocket(serverSocket);
        WSACleanup();

        return false;
    }

    std::cout << "Listening on Port " << port << "...\n";

    return true;
}

void TCPServer::stop()
{
    if (serverSocket != INVALID_SOCKET)
    {
        closesocket(serverSocket);

        serverSocket = INVALID_SOCKET;
    }

    WSACleanup();
}