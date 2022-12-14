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

void TextureManager::draw(const Sprite sprite, const Position pos, const Velocity vel)
{
    int frame = int((SDL_GetTicks() / 100) % sprite.col);

    SDL_Rect src_rect, dst_rect;

    src_rect.x = frame * sprite.w;
    src_rect.y = (sprite.row - 1) * sprite.h;
    src_rect.w = sprite.w;
    src_rect.h = sprite.h;

    dst_rect.x = pos.v2d.get_x();
    dst_rect.y = pos.v2d.get_y();
    dst_rect.w = sprite.w * sprite.scalar;
    dst_rect.h = sprite.h * sprite.scalar;

    SDL_RenderCopyEx(Application::Instance()->get_renderer(), tex_map[sprite.id], &src_rect, &dst_rect, 0, 0, sprite.flip);
}

void TextureManager::clean(std::string id)
{
    SDL_DestroyTexture(tex_map[id]);
    tex_map.erase(id);
}
