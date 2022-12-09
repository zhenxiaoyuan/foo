#include <string>

#include "SDL/SDL.h"

class CharacterParams
{
public:
    CharacterParams(std::string tex_id, int row, int col, float x, float y, int w, int h, int scalar)
        : tex_id{tex_id}, row{row}, col{col}, x{x}, y{y}, w{w}, h{h}, scalar{scalar}
    {
    }

    std::string get_tex_id() const {
        return this->tex_id;
    }

    int get_row() const {
        return this->row;
    }

    int get_col() const {
        return this->col;
    }

    float get_x() const {
        return this->x;
    }

    float get_y() const {
        return this->y;
    }

    int get_w() const {
        return this->w;
    }

    int get_h() const {
        return this->h;
    }

    int get_scalar() const {
        return this->scalar;
    }

private:
    std::string tex_id;
    int row, col;
    float x, y;
    int w, h;
    int scalar;
};

