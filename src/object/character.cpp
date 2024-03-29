#include "character.hpp"
#include "../manager/texture_manager.hpp"

Character::Character(const CharacterParams *params)
    : tex_id{params->get_tex_id()}, row{params->get_row()},
      col{params->get_col()}, pos{params->get_x(), params->get_y()}, vel{0, 0},
      acc{0, 0}, w{params->get_w()}, h{params->get_h()},
      scalar{params->get_scalar()} {}

Character::~Character() {}

void Character::draw() {
}

void Character::update() {
  frame = int((SDL_GetTicks() / 100) % col);

  vel.set_x(0);
  vel.set_y(0);

  vel += acc;
  pos += vel;
}

void Character::clean() {}

void Character::up() { std::cout << "Player UP!!!" << std::endl; }

void Character::down() { std::cout << "Player DOWN!!!" << std::endl; }
