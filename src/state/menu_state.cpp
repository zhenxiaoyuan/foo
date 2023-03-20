#include "menu_state.hpp"
#include <iostream>

const std::string MenuState::menu_id = "MENU";

void MenuState::update()
{
    // no op now
}

void MenuState::render()
{
    // no op now
}

bool MenuState::on_enter()
{
    std::cout << "Enter menu state." << std::endl;
    return true;
}

bool MenuState::on_exit()
{
    std::cout << "Exit memu state." << std::endl;
    return true;
}

std::string MenuState::get_state_id() const
{
    return menu_id;
}

MenuState::~MenuState()
{
    std::cout << "De-constructor menu state." << std::endl;
}
