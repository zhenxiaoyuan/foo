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

    // load_texture();
    Tex* cache = Tex::Cache();
    cache->say_hello();

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
}

void App::render()
{
    SDL_Rect src_rect, dst_rect;
    src_rect.x = 48 * int((SDL_GetTicks() / 100) % 6);
    src_rect.y = 0;
    dst_rect.x = 100;
    dst_rect.y = 100;
    src_rect.w = 48;
    src_rect.h = 48;
    dst_rect.w = 48 * 2;
    dst_rect.h = 48 * 2;

    SDL_RenderClear(renderer);
    SDL_RenderCopyEx(renderer, texture, &src_rect, &dst_rect, 0, 0, SDL_FLIP_HORIZONTAL);
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
    SDL_Rect src_rect;
    src_rect.w = 288;
    src_rect.h = 48;

    texture = IMG_LoadTexture(renderer, "assets/characters/player/idle.png");
    if (!texture) {
        SDL_Log("IMG_LoadTexture failed: %s. \n", SDL_GetError());
        return;
    }

    SDL_QueryTexture(texture, NULL, NULL, &src_rect.w, &src_rect.h);
}
