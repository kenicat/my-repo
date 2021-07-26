#ifndef _TCPSOCKET_H
#define _TCPSOCKET_H
#include <cstdio>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class TCPSocket {
    protected:
        int sock_fd;
        struct sockaddr_in address;
        int addrlen;
        unsigned short port;
        int connection;
    public:
        TCPSocket();
        TCPSocket(int);
        TCPSocket(const char *, int);

        int getSocketFD();
        struct sockaddr_in& getSockaddr();
        const char* getAddress();
        unsigned short getPort();
        void setAddress(const char*);
        void setPort(int);
        int getConnection();
        ssize_t send(int, const void*, size_t);
        ssize_t recv(int, void*, size_t);
        void close();

        ~TCPSocket();
};

#endif
