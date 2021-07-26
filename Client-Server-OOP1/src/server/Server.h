#ifndef _SERVER_H
#define _SERVER_H
#include "../TCPSocket/TCPSocket.h"
#include "sys/socket.h"

class Server: public virtual TCPSocket {
    private:
        int opt;
        int backlog;
    public:
        Server();
        Server(int);
        
        int getOpt();
        int getBacklog();
        void setOpt(int);
        void setBacklog(int);
        void setSockOpt(int, int);
        void bind();
        void listen();
        void accept();
        void shutdown(int, int);
        void shutdown(int);

        ~Server();
};

#endif
