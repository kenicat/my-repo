#ifndef _CLIENT_H
#define _CLIENT_H
#include "TCPSocket.h"

class Client: public TCPSocket {
    public:
        Client();
        Client(const char*, int);
        
        void connect(const char*, int);
        void disconnect();

        ~Client();
};

#endif
