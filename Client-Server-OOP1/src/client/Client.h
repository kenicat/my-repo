#ifndef _CLIENT_H
#define _CLIENT_H
#include "../TCPSocket/TCPSocket.h"

class Client: public virtual TCPSocket {
    public:
        Client();
        Client(const char*, int);
        
        void connect(const char*, int);
        void disconnect();

        ~Client();
};

#endif
