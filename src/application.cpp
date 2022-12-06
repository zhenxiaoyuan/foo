#include "application.hpp"
#include "constants.hpp"
#include "manager/texture_manager.hpp"

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
    while(running) {
        events();
        update();
        render();
    }
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

    TextureManager::Instance()->load("assets/characters/player/idle.png", "player_idle", TEX_PLAYER_WIDTH, TEX_PLAYER_HEIGHT);

    running = true;
}

void Application::events()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;

        default:
            break;
        }
    }
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
