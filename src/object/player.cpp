#include "player.hpp"

Player::Player(const CharacterParams* params) : Character(params)
{
    this->tex_id = params->get_tex_id();
    this->row = params->get_row();
    this->col = params->get_col();
    this->x = params->get_x();
    this->y = params->get_y();
    this->w = params->get_w();
    this->h = params->get_h();
}

Player::~Player()
{
}

void Player::draw()
{
    Character::draw();
}

void Player::update()
{
    Character::update();
}

void Player::clean()
{
}
