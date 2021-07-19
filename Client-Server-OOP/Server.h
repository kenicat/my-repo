#ifndef _SERVER_H
#define _SERVER_H
#include "TCPSocket.h"
#include "sys/socket.h"

class Server: public TCPSocket {
    private:
        int opt;
        int backlog;
        int connection;
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
