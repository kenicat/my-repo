#include "AppS.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <chrono>
#include <ctime>
#include <string>

AppS::AppS(): App::App(), Server::Server() {
    fout.open("log.txt", std::ios::out | std::ios::app);
}

void AppS::start() {
    setSockOpt(SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT);
    setPort(8089);

    bind();

    std::cout << "Listening for connection..." << std::endl;
    listen();

    accept();

    run();

    std::cout << "Shutdown connection." << std::endl;

    char endSplit[] = "\n___________________________________________________________________________\n\n";
    fout.write(endSplit, strlen(endSplit));
}

void AppS::disconnectCurrent() {
    shutdown(connection, SHUT_RDWR);
}

void AppS::log(const char* buffer, size_t bsize, bool bValue) {                                 // true = send, false = recv
    std::lock_guard<std::mutex> guard(mtx);

    std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::string direction;
    if (bValue)
        direction = "Server -> Client";
    else
        direction = "Client -> Server";

    fout << std::setw(26) << std::ctime(&time);
    fout << std::setw(18) << direction << '\t';
    fout << buffer << std::endl;
}

AppS::~AppS() {
    fout.close();
}
