#include "player.hpp"

Player::Player()
{
}

Player::~Player()
{
}

void Player::init(std::string tex_id, int row, int col, int x, int y, int w, int h)
{
    Game::init(tex_id, row, col, x, y, w, h);
}

void Player::draw(SDL_Renderer *renderer)
{
    Game::draw(renderer);
}

void Player::update()
{
    Game::update();
}

void Player::clean()
{
}
