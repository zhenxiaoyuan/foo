#include "entt/entt.hpp"
#include "SDL/SDL.h"

#include "../components/player.hpp"
#include "../components/position.hpp"
#include "../components/velocity.hpp"
#include "../components/sprite.hpp"

void draw_player(entt::registry &registry) {
    auto view = registry.view<const Player, const Position, const Velocity, const Sprite>();

    view.each([](const auto &player, const auto &position, const auto &velocity, const auto &sprite) {

        TextureManager::Instance()->draw(sprite, position, velocity);
    });
}
