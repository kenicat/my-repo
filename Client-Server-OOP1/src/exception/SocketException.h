#ifndef _SOCKETEX_H
#define _SOCKETEX_H
#include <stdexcept>
#include <string>

class SocketException: public std::runtime_error {
    private:
        std::string msg;
    public:
        SocketException(std::string);
        const char* what();
        std::string getMsg();
        ~SocketException();
};

#endif
