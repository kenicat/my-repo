#include "TCPSocket.h"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "exception/SocketException.h"

TCPSocket::TCPSocket(): TCPSocket::TCPSocket(0) {}

TCPSocket::TCPSocket(int p) {

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Can't create socket\n");
        throw SocketException("Create");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(p);
    addrlen = sizeof(address);
}

TCPSocket::TCPSocket(const char* addr, int p): TCPSocket::TCPSocket(p)
{
    address.sin_addr.s_addr = inet_addr(addr);
}

int TCPSocket::getSocketFD() {
    return sock_fd;
}

struct sockaddr_in& TCPSocket::getSockaddr() {
    return address;
}

unsigned short TCPSocket::getPort() {
    return port;
}

void TCPSocket::setAddress(const char* addr) {
    address.sin_addr.s_addr = inet_addr(addr);
}

void TCPSocket::setPort(int p) {
    address.sin_port = htons(p);
}

ssize_t TCPSocket::send(int sock, const void* buffer, size_t bsize) {
    ssize_t byte = ::send(sock, buffer, bsize, 0);
    if (byte < 0) {
        perror("Error on sending message\n");
        throw SocketException("Send");
    }
    std::cout << "Sent: " << (char*) buffer << std::endl;
    return byte;
}

ssize_t TCPSocket::recv(int sock, void* buffer, size_t bsize) {
    ssize_t byte = ::recv(sock, buffer, bsize, 0);
    if (byte < 0) {
        perror("Error on receiving message\n");
        throw SocketException("Receive");
    }
    std::cout << "Received: " << (char*) buffer << std::endl;
    return byte;
}

void TCPSocket::close() {
    ::close(sock_fd);
}

TCPSocket::~TCPSocket() {
    close();
}
