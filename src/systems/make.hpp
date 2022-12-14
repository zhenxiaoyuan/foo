#include "entt/entt.hpp"

#include "../manager/texture_manager.hpp"
#include "../constants.hpp"

#include "../components/player.hpp"
#include "../components/position.hpp"
#include "../components/velocity.hpp"
#include "../components/sprite.hpp"

void make_player(entt::registry &registry) {
    TextureManager::Instance()->load("../assets/characters/player/idle.png", "player_idle", TEX_PLAYER_WIDTH, TEX_PLAYER_HEIGHT);
    TextureManager::Instance()->load("../assets/characters/player/run.png", "player_run", TEX_PLAYER_WIDTH, TEX_PLAYER_HEIGHT);
    TextureManager::Instance()->load("../assets/characters/player/attack.png", "player_attack", TEX_PLAYER_WIDTH, TEX_PLAYER_HEIGHT);

    const auto player = registry.create();
    registry.emplace<Player>(player);
    registry.emplace<Position>(player, Vector2D(100, 100));
    registry.emplace<Velocity>(player, Vector2D(0, 0));
    registry.emplace<Sprite>(player, "player_idle", 1, 6, PLAYER_WIDTH, PLAYER_HEIGHT, 4.f, SDL_FLIP_NONE);
}