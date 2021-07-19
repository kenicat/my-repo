#ifndef _APP_H
#define _APP_H

#include "TCPSocket.h"
#include <mutex>

class App: public virtual TCPSocket {
    private:
        bool running;
        std::mutex mtx;
    public:
        App();

        void run();
        bool isRunning();
        void setRunning(bool);
        void* sendThread();
        void* recvThread();
        virtual void start();
        virtual void disconnectCurrent();
        virtual void log(const char*, size_t, bool bValue);

        ~App();
};

#endif
