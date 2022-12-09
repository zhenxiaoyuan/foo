#include "SDL/SDL.h"

class InputManager
{
public:
    static InputManager* Instance();

    void update();
    bool on_key_down(SDL_Scancode key);

private:
    InputManager();
    ~InputManager();

    static InputManager* instance;
};


