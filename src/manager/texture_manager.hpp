#pragma once

#include <string>
#include <map>

#include "SDL/SDL.h"

#include "../components/position.hpp"
#include "../components/velocity.hpp"
#include "../components/sprite.hpp"

class TextureManager
{
public:
    TextureManager(TextureManager &other) = delete;
    void operator= (const TextureManager &) = delete;

    static TextureManager* Instance();

    void load(std::string path, std::string id, int w, int h);
    void draw(const Sprite sprite, const Position pos, const Velocity vel);
    void clean(std::string id);

private:
    TextureManager();
    ~TextureManager();

    static TextureManager* instance;

    std::map<std::string, SDL_Texture*> tex_map;
};

