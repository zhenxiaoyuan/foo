#include "application.hpp"
#include "manager/texture_manager.hpp"
#include "manager/input_manager.hpp"

Application* Application::instance = nullptr;

Application::Application()
{
}

Application::~Application()
{
    clean();

    delete player;
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
    return renderer;
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

    TextureManager::Instance()->load("../assets/characters/player/idle.png", "player_idle", TEX_PLAYER_WIDTH, TEX_PLAYER_HEIGHT);
    TextureManager::Instance()->load("../assets/characters/player/run.png", "player_run", TEX_PLAYER_WIDTH, TEX_PLAYER_HEIGHT);
    TextureManager::Instance()->load("../assets/characters/player/attack.png", "player_attack", TEX_PLAYER_WIDTH, TEX_PLAYER_HEIGHT);

    running = true;
}

void Application::events()
{
    InputManager::Instance()->update();
}

void Application::update()
{
    player->update();
}

void Application::render()
{
    SDL_RenderClear(renderer);

    player->draw();

    SDL_RenderPresent(renderer);
}

void Application::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
