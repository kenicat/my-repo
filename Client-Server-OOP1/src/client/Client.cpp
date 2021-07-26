#include "Client.h"
#include <iostream>
#include <sys/socket.h>
#include "../exception/SocketException.h"

Client::Client(): TCPSocket() {}

Client::Client(const char* addr, int p): TCPSocket::TCPSocket(addr, p) {}

void Client::connect(const char* addr, int p) {
    TCPSocket::setAddress(addr);
    TCPSocket::setPort(p);
    int ret = ::connect(sock_fd, (struct sockaddr*) &address, sizeof(address));
    if (ret < 0) {
        perror("Can't connect\n");
        throw SocketException("Connect");
    }

    connection = sock_fd;

    std::cout << "Connected to " << addr << ":" << p << std::endl;
}

void Client::disconnect() {
    close();
}

Client::~Client() {}