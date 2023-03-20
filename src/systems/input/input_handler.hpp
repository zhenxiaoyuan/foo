#pragma once

#include "../../manager/input_manager.hpp"

#include "down_command.hpp"
#include "up_command.hpp"


class InputHandler {
public:
  Command *handle_input() {
    if (InputManager::Instance()->is_key_down(SDL_SCANCODE_UP)) {
      return m_up;
    }
    if (InputManager::Instance()->is_key_down(SDL_SCANCODE_DOWN)) {
      return m_down;
    }
    return nullptr;
  }

  InputHandler() {
    m_up = new UpCommand();
    m_down = new DownCommand();
  };
  ~InputHandler(){};

private:
  Command *m_up;
  Command *m_down;
};
