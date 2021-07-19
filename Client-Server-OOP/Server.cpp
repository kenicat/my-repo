#include "Server.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include "exception/SocketException.h"
#include <iostream>

Server::Server(): TCPSocket() {}

Server::Server(int PORT): TCPSocket(PORT) {
    opt = 1;
    backlog = 5;
}

int Server::getOpt() {
    return opt;
}

int Server::getBacklog() {
    return backlog;
}

void Server::setOpt(int o) {
    opt = o;
}

void Server::setBacklog(int b) {
    backlog = b;
}

void Server::setSockOpt(int level, int optName) {
    int ret = ::setsockopt(sock_fd, level, optName, &opt, sizeof(opt));
    if (ret < 0) {
        perror("Can't set socket option\n");
        throw SocketException("Setsockopt");
    }
}

void Server::bind() {
    int ret = ::bind(sock_fd, (struct sockaddr*) &address, sizeof(address));
    if (ret < 0) {
        perror("Can't bind socket\n");
        throw SocketException("Bind");
    }
}

void Server::listen() {
    int ret = ::listen(sock_fd, backlog);
    if (ret < 0) {
        perror("Can't listen\n");
        throw SocketException("Listen");
    }
    std::cout << "Listeing..." << std::endl;
}

void Server::accept() {
    int ret = ::accept(sock_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen);
    if (ret < 0) {
        perror("Can't accept\n");
        throw SocketException("Accept");
    }
    connection = ret;
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &address.sin_addr, ip, sizeof(ip));
    std::cout << "Accepted connection from " << ip << std::endl;
}

void Server::shutdown(int con, int how = SHUT_RDWR) {
    ::shutdown(con, how);
    std::cout << "Shutdown connection" << std::endl;
}

void Server::shutdown(int how = SHUT_RDWR) {
    Server::shutdown(connection, how);
}

Server::~Server() {}
