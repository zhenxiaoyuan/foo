#include "game.hpp"

class Player : public Game
{
public:
    Player();
    ~Player();

    void init(std::string tex_id, int row, int col, int x, int y, int w, int h);
    void draw(SDL_Renderer* renderer);
    void update();
    void clean();

private:

};

