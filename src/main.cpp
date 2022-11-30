#include "app.hpp"

#include <iostream>

int main(int argc, char** argv) {
    try {
        App* app = new App;
        app->run();
        delete app;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}

