#include "tex.hpp"
#include "SDL/SDL.h"

Tex* Tex::Cache()
{
    if (cache == nullptr) {
        cache = new Tex();
    }

    return cache;
}

Tex::Tex()
{
}

Tex::~Tex()
{
}

void Tex::say_hello()
{
    SDL_Log("Hello, this is texture cache. \n");
}

