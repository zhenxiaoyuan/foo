#include "character.hpp"

class Player : public Character
{
public:
    Player(const CharacterParams* params);
    ~Player();

    void draw();
    void update();
    void clean();

private:
    std::string tex_id;
    int frame = 0;
    int row, col;
    int x, y;
    int w, h;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};

