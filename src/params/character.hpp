#include <string>

#include "SDL/SDL.h"

class CharacterParams
{
public:
    CharacterParams(std::string tex_id, int row, int col, int x, int y, int w, int h)
        : tex_id{tex_id}, row{row}, col{col}, x{x}, y{y}, w{w}, h{h}
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

    int get_x() const {
        return this->x;
    }

    int get_y() const {
        return this->y;
    }

    int get_w() const {
        return this->w;
    }

    int get_h() const {
        return this->h;
    }


private:
    std::string tex_id;
    int row, col;
    int x, y;
    int w, h;
};

