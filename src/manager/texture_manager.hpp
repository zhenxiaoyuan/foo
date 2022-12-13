#pragma once

#include <string>
#include <map>

#include "SDL/SDL.h"

class TextureManager
{
public:
    TextureManager(TextureManager &other) = delete;
    void operator= (const TextureManager &) = delete;

    static TextureManager* Instance();

    void load(std::string path, std::string id, int w, int h);
    void draw(std::string id, int frame, int row, float x, float y, int w, int h, int scalar, SDL_RendererFlip flip);
    void clean(std::string id);

private:
    TextureManager();
    ~TextureManager();

    static TextureManager* instance;

    std::map<std::string, SDL_Texture*> tex_map;
};

