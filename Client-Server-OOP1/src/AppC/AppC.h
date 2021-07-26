#ifndef _APPC_H
#define _APPC_H
#include "../App/App.h"
#include "../client/Client.h"

class AppC: public App, Client {
    public:
        AppC();

        void start();
        void disconnectCurrent();

        ~AppC();
};

#endif
