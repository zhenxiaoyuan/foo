#include "tex.hpp"
#include "SDL/SDL_image.h"

Tex* Tex::tex_cache = nullptr;

Tex* Tex::Cache()
{
    if (tex_cache == nullptr) {
        tex_cache = new Tex();
    }

    return tex_cache;
}

Tex::Tex()
{
}

Tex::~Tex()
{
    for (auto it : tex_map) {
        SDL_DestroyTexture(it.second);
    }
}

void Tex::load(SDL_Renderer* renderer, std::string path, std::string id, int w, int h)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());

    if (!texture) {
        SDL_Log("IMG_LoadTexture failed: %s. \n", SDL_GetError());
        return;
    }

    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    tex_map[id] = texture;
}

void Tex::draw(SDL_Renderer* renderer, std::string id, int frame, int row, int x, int y, int w, int h, SDL_RendererFlip flip)
{
    SDL_Rect src_rect, dst_rect;

    src_rect.x = frame * w;
    src_rect.y = (row - 1) * h;
    dst_rect.x = x;
    dst_rect.y = y;
    src_rect.w = dst_rect.w = w;
    src_rect.h = dst_rect.h = h;

    SDL_RenderCopyEx(renderer, tex_map[id], &src_rect, &dst_rect, 0, 0, flip);
}
