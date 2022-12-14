#include "application.hpp"
#include "constants.hpp"
#include "manager/input_manager.hpp"
#include "state/menu_state.hpp"
#include "state/play_state.hpp"

#include "systems/make.hpp"
#include "systems/draw.hpp"
#include "systems/input.hpp"
#include "systems/move.hpp"

Application* Application::instance = nullptr;

Application::Application()
{
}

Application::~Application()
{
    clean();

    delete instance;
}

Application* Application::Instance()
{
    if (instance == nullptr) {
        instance = new Application();
    }

    return instance;
}

void Application::run()
{
    Uint32 frame_start, frame_time;

    while(running) {
        frame_start = SDL_GetTicks();

        events();
        update();
        render();

        frame_time = SDL_GetTicks() - frame_start;

        if (frame_time < DELAY_TIME) {
            SDL_Delay((int)(DELAY_TIME - frame_time));
        }
    }
}

void Application::set_running(bool running)
{
    this->running = running;
}

SDL_Renderer *Application::get_renderer()
{
    return this->renderer;
}

void Application::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        SDL_Log("SDL_Init failed: %s\n", SDL_GetError());
        running = false;
    }
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer) < 0) {
        SDL_Log("SDL_CreateWindowAndRenderer failed: %s\n", SDL_GetError());
        running = false;
    }

    SDL_SetWindowTitle(window, "foo");
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);

    state_machine = new StateMachine();
    state_machine->push(new MenuState());

    make_player(registry);

    running = true;
}

void Application::events()
{
    InputManager::Instance()->update();

    input_player(registry);

    if (InputManager::Instance()->is_key_down(SDL_SCANCODE_RETURN)) {
        state_machine->change(new PlayState());
    }
}

void Application::update()
{
    move(registry);

    state_machine->update();
}

void Application::render()
{
    SDL_RenderClear(renderer);

    draw_player(registry);

    state_machine->render();

    SDL_RenderPresent(renderer);
}

void Application::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
