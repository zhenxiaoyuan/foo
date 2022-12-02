#include <string>

#include "SDL/SDL.h"

class Character
{
public:
    Character();
    virtual ~Character();

    virtual void init(std::string tex_id, int row, int col, int x, int y, int w, int h);
    virtual void draw(SDL_Renderer* renderer);
    virtual void update();
    virtual void clean();

private:
    std::string m_tex_id;
    int m_frame = 0;
    int m_row, m_col;
    int m_x, m_y;
    int m_w, m_h;
    SDL_RendererFlip m_flip = SDL_FLIP_NONE;
};

