#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <lib/error_handling.h>

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

int main(int argc, char *argv[])
{
    WSADATA wsaData;
    SOCKET hSocket;
    SOCKADDR_IN servAddr;

    char message[40];
    int strLen = 0;
    int idx = 0;
    int readLen = 0;

    if (argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        ErrorHandling("WSAStartup() error!");
    }

    hSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (hSocket == INVALID_SOCKET)
    {
        ErrorHandling("socket() error!");
    }

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(argv[1]);
    servAddr.sin_port = htons(atoi(argv[2]));

    if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == INVALID_SOCKET)
    {
        ErrorHandling("connect() error!");
    }

    while (readLen = recv(hSocket, &message[idx++], 1, 0))
    {
        if (readLen == -1)
        {
            ErrorHandling("recv() error!");
        }

        strLen += readLen;
    }

    printf("Message from server: %s\n", message);
    printf("Function read call count: %d\n", strLen);

    closesocket(hSocket);
    WSACleanup();

    return 0;
}