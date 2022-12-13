#pragma once

#include "game_state.hpp"
#include <vector>

class StateMachine
{
public:
    void push(GameState* state);
    void change(GameState* state);
    void pop();

    void update();
    void render();

private:
    std::vector<GameState*> game_states;
};

