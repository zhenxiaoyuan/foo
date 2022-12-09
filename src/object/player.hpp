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

};

