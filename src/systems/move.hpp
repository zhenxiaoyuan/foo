#include "entt/entt.hpp"

#include "../components/position.hpp"
#include "../components/velocity.hpp"

void move(entt::registry &registry) {
    auto view = registry.view<Position, Velocity>();

    view.each([](auto &position, auto &velocity) {
        position.v2d += velocity.v2d;
        velocity.v2d.zero();
    });
}
