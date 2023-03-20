#pragma once

#include "game_state.hpp"

class MenuState : public GameState
{
public:
    void update() override;
    void render() override;

    bool on_enter() override;
    bool on_exit() override;

    std::string get_state_id() const override;

    ~MenuState();

private:
    static const std::string menu_id;
};

