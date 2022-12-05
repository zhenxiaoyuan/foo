#include "character.hpp"
#include "../cache/tex.hpp"
#include "../cons.hpp"

Character::Character(const CharacterParams* params)
{
    this->tex_id = params->get_tex_id();
    this->row = params->get_row();
    this->col = params->get_col();
    this->x = params->get_x();
    this->y = params->get_y();
    this->w = params->get_w();
    this->h = params->get_h();
}

Character::~Character()
{
}

void Character::draw(SDL_Renderer *renderer)
{
    Tex::Cache()->draw(renderer, tex_id, frame, row, x, y, w, h, flip);
}

void Character::update()
{
    frame = int((SDL_GetTicks() / 100) % col);
}

void Character::clean()
{
}

