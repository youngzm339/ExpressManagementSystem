#include <iostream>
#include "Method.h"

int main() {
    std::cout << "Welcome to ExpressManagementSystem" << std::endl;
    std::cout << "Powered by YoungZM, All Rights Reserved" << std::endl;

    // Init
    std::cout << "Loading Users..." << std::endl;
    try {
        LoadUsers();
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        return -1;
    }
    std::cout << "Loading Items..." << std::endl;
    try {
        LoadItems();
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        return -2;
    }

    // Main
    try {
        LoginPanel();
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
    }

    // Download config files
    std::cout << "Downloading Users..." << std::endl;
    try {
        DownloadUsers();
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        return 1;
    }
    std::cout << "Downloading Items..." << std::endl;
    try {
        DownloadItems();
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        return 2;
    }

    std::cout << "Program has exited" << std::endl;
    return 0;
}
