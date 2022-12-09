#include "texture_manager.hpp"
#include "SDL/SDL_image.h"
#include "../application.hpp"

TextureManager* TextureManager::instance = nullptr;

TextureManager* TextureManager::Instance()
{
    if (instance == nullptr) {
        instance = new TextureManager();
    }

    return instance;
}

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
    for (auto it : tex_map) {
        SDL_DestroyTexture(it.second);
    }
    delete instance;
}

void TextureManager::load(std::string path, std::string id, int w, int h)
{
    SDL_Texture* texture = IMG_LoadTexture(Application::Instance()->get_renderer(), path.c_str());

    if (!texture) {
        SDL_Log("IMG_LoadTextureManagerture failed: %s. \n", SDL_GetError());
        return;
    }

    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    tex_map[id] = texture;
}

void TextureManager::draw(std::string id, int frame, int row, float x, float y, int w, int h, int scalar, SDL_RendererFlip flip)
{
    SDL_Rect src_rect, dst_rect;

    src_rect.x = frame * w;
    src_rect.y = (row - 1) * h;
    dst_rect.x = x;
    dst_rect.y = y;
    src_rect.w = w;
    src_rect.h = h;
    dst_rect.w = w * scalar;
    dst_rect.h = h * scalar;

    SDL_RenderCopyEx(Application::Instance()->get_renderer(), tex_map[id], &src_rect, &dst_rect, 0, 0, flip);
}
