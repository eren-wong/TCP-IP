#include <lib/error_handling.h>

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

int main(int argc, char *argv[])
{
    WSADATA wsaData;
    SOCKET hServSock, hClntSock;
    SOCKADDR_IN servAddr, clntAddr;
    int szClntAddr;
    char message[] = "hello world.";

    if (argc != 2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        ErrorHandling("WSAStartup() error!");
    }

    hServSock = socket(PF_INET, SOCK_STREAM, 0);
    if (hServSock == INVALID_SOCKET)
    {
        ErrorHandling("socket() error!");
    }

    memset(&servAddr, 0, sizeof(servAddr) );
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(atoi(argv[1]) );

    if (bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == INVALID_SOCKET)
    {
        ErrorHandling("bind() error!");
    }

    if (listen(hServSock, 5) == INVALID_SOCKET)
    {
        ErrorHandling("listen() error!");
    }

    szClntAddr = sizeof(clntAddr);
    hClntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
    if (hClntSock == INVALID_SOCKET)
    {
        ErrorHandling("accept() error!");
    }

    send(hClntSock, message, sizeof(message), 0);

    closesocket(hClntSock);
    closesocket(hServSock);
    WSACleanup();

    return 0;
}