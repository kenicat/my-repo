#include "SocketException.h"

SocketException::SocketException(std::string msg): std::runtime_error(msg), msg(msg) {}

const char* SocketException::what() {
    return "Socket Exception ";
}

std::string SocketException::getMsg() {
    return msg;
}

SocketException::~SocketException() {}
