#include "AppC.h"
#include <iostream>

#define ADDRESS "127.0.0.1"
#define PORT    8089

AppC::AppC(): App::App(), Client::Client() {}

void AppC::start() {
    connect(ADDRESS, PORT);

    run();
    
    std::cout << "Disconnect from the server." << std::endl;
}

void AppC::disconnectCurrent() {
}

AppC::~AppC() {}
