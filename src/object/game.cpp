#include "game.hpp"
#include "../cache/tex.hpp"
#include "../cons.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(std::string tex_id, int row, int col, int x, int y, int w, int h)
{
    m_tex_id = tex_id;
    m_row = row;
    m_col = col;
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
}

void Game::draw(SDL_Renderer *renderer)
{
    Tex::Cache()->draw(renderer, m_tex_id, m_frame, m_row, m_x, m_y, m_w, m_h, m_flip);
}

void Game::update()
{
    m_frame = int((SDL_GetTicks() / 100) % m_col);
}

void Game::clean()
{
}