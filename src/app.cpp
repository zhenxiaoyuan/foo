#include "app.hpp"
#include "cons.hpp"

App::App()
{
    running = init();
}

App::~App()
{
    clean();
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

    load_texture();
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
}

void App::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void App::clean()
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void App::load_texture()
{
    int texture_player_w = 288;
    int texture_player_h = 240;

    texture = IMG_LoadTexture(renderer, "assets/characters/player.png");
    if (!texture) {
        SDL_Log("IMG_LoadTexture failed: %s. \n", SDL_GetError());
        return;
    }

    SDL_QueryTexture(texture, NULL, NULL, &texture_player_w, &texture_player_h);
}
