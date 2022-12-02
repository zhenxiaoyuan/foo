#include <string>

#include "SDL/SDL.h"

class Game
{
public:
    Game();
    ~Game();

    void init(std::string tex_id, int row, int col, int x, int y, int w, int h);
    void draw(SDL_Renderer* renderer);
    void update();
    void clean();

protected:
    std::string m_tex_id;
    int m_frame = 0;
    int m_row, m_col;
    int m_x, m_y;
    int m_w, m_h;
    SDL_RendererFlip m_flip = SDL_FLIP_NONE;
};

