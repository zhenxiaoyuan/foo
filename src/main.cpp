#include "application.hpp"

#include <iostream>

int main(int argc, char** argv) {
    try {
        Application::Instance()->init();
        Application::Instance()->run();
        Application::Instance()->clean();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

