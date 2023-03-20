#pragma once

#include "command.hpp"

class DownCommand : public Command
{
public:
    ~DownCommand() {};

    virtual void exe(GameObject& actor) { actor.down(); };

private:
    void down() {
        std::cout << "DOWN!!!" << std::endl;
    }
};
