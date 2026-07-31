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