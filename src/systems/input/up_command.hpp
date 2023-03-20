#pragma once

#include "command.hpp"

class UpCommand : public Command
{
public:
    ~UpCommand() {};

    virtual void exe(GameObject& actor) { actor.up(); };

private:
    void up() {
        std::cout << "UP!!!" << std::endl;
    }
};
