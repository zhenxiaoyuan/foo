#include "player.hpp"
#include "../manager/input_manager.hpp"

Player::Player(const CharacterParams* params) : Character(params)
{
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
    acc.set_x(0);
    acc.set_y(0);

    tex_id = "player_idle";

    if (InputManager::Instance()->on_key_down(SDL_SCANCODE_D)) {
        acc.set_x(scalar);
        tex_id = "player_run";
        flip = SDL_FLIP_NONE;
    }
    if (InputManager::Instance()->on_key_down(SDL_SCANCODE_A)) {
        acc.set_x(-scalar);
        tex_id = "player_run";
        flip = SDL_FLIP_HORIZONTAL;
    }
    if (InputManager::Instance()->on_key_down(SDL_SCANCODE_W)) {
        tex_id = "player_run";
        acc.set_y(-scalar);
    }
    if (InputManager::Instance()->on_key_down(SDL_SCANCODE_S)) {
        tex_id = "player_run";
        acc.set_y(scalar);
    }
    if (InputManager::Instance()->on_key_down(SDL_SCANCODE_J)) {
        tex_id = "player_attack";
    }

    Character::update();
}

void Player::clean()
{
}
