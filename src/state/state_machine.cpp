#include "state_machine.hpp"

void StateMachine::push(GameState *state)
{
    game_states.push_back(state);
    game_states.back()->on_enter();
}

void StateMachine::change(GameState *state)
{
    if (!game_states.empty()) {
        if (game_states.back()->get_state_id() == state->get_state_id()) {
            return;
        }

        if (game_states.back()->on_exit()) {
            delete game_states.back();
            game_states.pop_back();
        }
    }

    game_states.push_back(state);
    game_states.back()->on_enter();
}

void StateMachine::pop()
{
    if (!game_states.empty()) {
        if (game_states.back()->on_exit()) {
            delete game_states.back();
            game_states.pop_back();
        }
    }
}

void StateMachine::update()
{
    if (!game_states.empty()) {
        game_states.back()->update();
    }
}

void StateMachine::render()
{
    if (!game_states.empty()) {
        game_states.back()->render();
    }
}
