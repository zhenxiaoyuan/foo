#pragma once

#include <vector>

#include "game_state.hpp"
#include "../constants.hpp"

class PlayState : public GameState
{
public:
    virtual void update();
    virtual void render();

    virtual bool on_enter();
    virtual bool on_exit();

    virtual std::string get_state_id() const {
        return play_id;
    }

    ~PlayState();

private:
    static const std::string play_id;

    // std::vector<GameObject*> game_objects;

};
