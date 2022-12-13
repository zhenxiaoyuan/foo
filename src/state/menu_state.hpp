#pragma once

#include "game_state.hpp"

class MenuState : public GameState
{
public:
    virtual void update();
    virtual void render();

    virtual bool on_enter();
    virtual bool on_exit();

    virtual std::string get_state_id() const {
        return menu_id;
    }

    ~MenuState();

private:
    static const std::string menu_id;
};

