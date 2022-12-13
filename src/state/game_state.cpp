#include "game_state.hpp"
#include <iostream>

GameState::~GameState()
{
    std::cout << "De-constructor game state." << std::endl;
}