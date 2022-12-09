#include "input_manager.hpp"
#include "../application.hpp"

InputManager* InputManager::instance = nullptr;

InputManager *InputManager::Instance()
{
    if (instance == nullptr) {
        instance = new InputManager();
    }

    return instance;
}

void InputManager::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            Application::Instance()->set_running(false);
            break;

        default:
            break;
        }
    }
    
}

bool InputManager::on_key_down(SDL_Scancode key)
{
    const Uint8* key_state = SDL_GetKeyboardState(NULL);

    if (key_state != 0) {
        if (key_state[key] == 1)
            return true;
        else
            return false;
    }

    return false;
}

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
    delete instance;
}
