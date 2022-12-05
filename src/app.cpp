#include "app.hpp"
#include "cons.hpp"
#include "cache/tex.hpp"

App::App()
{
    running = init();
}

App::~App()
{
    clean();

    delete player;
}

void App::run()
{
    while(running) {
        events();
        update();
        render();
    }
}

bool App::init()
{

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        SDL_Log("SDL_Init failed: %s\n", SDL_GetError());
        return false;
    }
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer) < 0) {
        SDL_Log("SDL_CreateWindowAndRenderer failed: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetWindowTitle(window, "foo");
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);

    Tex::Cache()->load(renderer, "assets/characters/player/idle.png", "player_idle", TEX_PLAYER_WIDTH, TEX_PLAYER_HEIGHT);

    return true;
}

void App::events()
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

void App::update()
{
    player->update();
}

void App::render()
{
    SDL_RenderClear(renderer);

    player->draw(renderer);

    SDL_RenderPresent(renderer);
}

void App::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
