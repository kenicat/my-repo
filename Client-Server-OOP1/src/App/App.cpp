#include "App.h"
#include <iostream>
#include <cstring>
#include <thread>

App::App(): TCPSocket() {
    running = false;
}

bool App::isRunning() {
    std::lock_guard<std::mutex> guard(mtx);
    return running;
}

void App::setRunning(bool bValue) {
    std::lock_guard<std::mutex> guard(mtx);
    running = bValue;
}

void App::run() {
    char greeting[] = "Welcome to chatting app\nYou can send and receive message asynchronously.\nType \"!!\" to terminate.\n\n";
    printf("%s", greeting);
    
    running = true;
    
    std::thread t1([this] {sendThread();});
    std::thread t2([this] {recvThread();});
    t1.join();
    t2.join();

    disconnectCurrent();
}

void* App::sendThread() {
    char buffer[256];
    while (isRunning()) {
        memset(buffer, 0, 256);

        std::cin.getline(buffer, 256);
        int val = send(connection, buffer, strlen(buffer));
        
        log(buffer, 256, true);
        
        if (!isRunning())
            std::cout << "Service stopped!" << std::endl;
        
        if (strcmp(buffer, "!!") == 0) {
            setRunning(false);
            disconnectCurrent();
        }
    }
    return NULL;
}

void* App::recvThread() {
    char buffer[256];
    while (isRunning()) {
        int val = recv(connection, buffer, 256);

        log(buffer, 256, false);

        if (strcmp(buffer, "!!") == 0) {
            setRunning(false);
            std::cout << "The other end has terminated connection!" << std::endl;
        }

        memset(buffer, 0, 256);
    }
    return NULL;
}

void App::start() {}

void App::disconnectCurrent() {}

void App::log(const char* message, size_t size, bool bValue) {}

App::~App() {}