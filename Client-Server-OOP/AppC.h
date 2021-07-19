#ifndef _APPC_H
#define _APPC_H
#include "App.h"
#include "Client.h"

class AppC: public App, Client {
    public:
        AppC();

        void start();

        ~AppC();
};

#endif
