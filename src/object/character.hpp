#include <string>

#include "SDL/SDL.h"
#include "../params/character_params.hpp"

class Character
{
public:
    Character(const CharacterParams* params);
    virtual ~Character();

    virtual void draw();
    virtual void update();
    virtual void clean();

private:
    std::string tex_id;
    int frame = 0;
    int row, col;
    int x, y;
    int w, h;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};

