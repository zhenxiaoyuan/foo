#include <string>

#include "SDL/SDL.h"

class CharacterParams
{
public:
    CharacterParams(std::string tex_id, int row, int col, int x, int y, int w, int h)
        : tex_id{tex_id}, row{row}, col{col}, x{x}, y{y}, w{w}, h{h}
    {
    }

private:
    std::string tex_id;
    int frame = 0;
    int row, col;
    int x, y;
    int w, h;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};

