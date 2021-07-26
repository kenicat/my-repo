#ifndef _APPS_H
#define _APPS_H

#include "../App/App.h"
#include "../server/Server.h"
#include <fstream>

class AppS: public App, Server {
    private:
        std::fstream fout;
        std::mutex mtx;
    public:
        AppS();

        void start();
        void disconnectCurrent();
        void log(const char*, size_t, bool);

        ~AppS();
};

#endif
