#include "entt/entt.hpp"

#include "../manager/input_manager.hpp"

#include "../components/player.hpp"
#include "../components/velocity.hpp"
#include "../components/sprite.hpp"

#include "iostream"

void input_player(entt::registry &registry) {
    auto view = registry.view<const Player, Velocity, Sprite>();

    view.each([](const auto &player, auto &velocity, auto &sprite) {
        bool key_pressed = false;

        if (InputManager::Instance()->is_key_down(SDL_SCANCODE_D) ||
            InputManager::Instance()->is_key_down(SDL_SCANCODE_RIGHT)) {
                key_pressed = true;
                velocity.v2d.set_x(sprite.scalar);
                sprite.id = "player_run";
                sprite.flip = SDL_FLIP_NONE;
        }
        if (InputManager::Instance()->is_key_down(SDL_SCANCODE_A) ||
            InputManager::Instance()->is_key_down(SDL_SCANCODE_LEFT)) {
                key_pressed = true;
                velocity.v2d.set_x(-sprite.scalar);
                sprite.id = "player_run";
                sprite.flip = SDL_FLIP_HORIZONTAL;
        }
        if (InputManager::Instance()->is_key_down(SDL_SCANCODE_W) ||
            InputManager::Instance()->is_key_down(SDL_SCANCODE_UP)) {
                key_pressed = true;
                velocity.v2d.set_y(-sprite.scalar);
                sprite.id = "player_run";
        }
        if (InputManager::Instance()->is_key_down(SDL_SCANCODE_S) ||
            InputManager::Instance()->is_key_down(SDL_SCANCODE_DOWN)) {
                key_pressed = true;
                velocity.v2d.set_y(sprite.scalar);
                sprite.id = "player_run";
        }

        if (!key_pressed) {
            sprite.id = "player_idle";
        }
    });

}
