#include <iostream>

#include "play_state.hpp"
#include "../constants.hpp"
#include "../manager/texture_manager.hpp"

const std::string PlayState::play_id = "PLAY";

void PlayState::update()
{
    // for (auto it : game_objects) {
    //     it->update();
    // }
}

void PlayState::render()
{
    // for (auto it : game_objects) {
    //     it->draw();
    // }
}

bool PlayState::on_enter()
{
    std::cout << "Enter play state." << std::endl;

    TextureManager::Instance()->load("../assets/characters/player/idle.png", "player_idle", TEX_PLAYER_WIDTH, TEX_PLAYER_HEIGHT);
    TextureManager::Instance()->load("../assets/characters/player/run.png", "player_run", TEX_PLAYER_WIDTH, TEX_PLAYER_HEIGHT);
    TextureManager::Instance()->load("../assets/characters/player/attack.png", "player_attack", TEX_PLAYER_WIDTH, TEX_PLAYER_HEIGHT);

    // Player* player = new Player(new CharacterParams("player_idle", TEX_PLAYER_ROW, TEX_PLAYER_COLUMN, 100, 100, PLAYER_WIDTH, PLAYER_HEIGHT, 4));
    // game_objects.push_back(player);

    return true;
}

bool PlayState::on_exit()
{
    std::cout << "Exit play state." << std::endl;

    // for (auto it : game_objects) {
    //     it->clean();
    // }

    // game_objects.clear();

    TextureManager::Instance()->clean("player_idle");
    TextureManager::Instance()->clean("player_run");
    TextureManager::Instance()->clean("player_attack");

    return true;
}

std::string PlayState::get_state_id() const
{
    return play_id;
}

PlayState::~PlayState()
{
    std::cout << "De-constructor play state." << std::endl;
}
