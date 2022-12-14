#pragma once

#include <string>

#include "SDL/SDL.h"

struct Sprite
{
    std::string id;
    int row;
    int col;
    int w;
    int h;
    float scalar;
    SDL_RendererFlip flip;
};
