#pragma once

#include <iostream>

#include "../../object/game_object.hpp"

class Command
{
private:
    /* data */
public:
    virtual ~Command() {};

    virtual void exe(GameObject& actor) = 0;
};

