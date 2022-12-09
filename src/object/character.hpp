#include <string>

#include "SDL/SDL.h"
#include "../params/character_params.hpp"
#include "vector2d.hpp"

class Character
{
public:
    Character(const CharacterParams* params);
    virtual ~Character();

    virtual void draw();
    virtual void update();
    virtual void clean();

protected:
    std::string tex_id;
    int frame = 0;
    int row, col;
    Vector2D pos;
    Vector2D vel;
    Vector2D acc;
    int w, h;
    int scalar;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};

