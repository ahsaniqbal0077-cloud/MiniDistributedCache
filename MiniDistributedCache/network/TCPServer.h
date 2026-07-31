#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

class TCPServer
{
public:

    TCPServer(int port);

    ~TCPServer();

    bool start();

    void stop();

private:

    int port;

    SOCKET serverSocket;
};