#include "app.hpp"

App::App()
{
    if (init(
        "foo",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        640,
        SDL_WINDOW_SHOWN
    )) {
        running = true;
    }
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

bool App::init(
    const char* title,
    const int xpos,
    const int ypos,
    const int height,
    const int width,
    const int flags
)
{
    bool init_success = false;

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        window = SDL_CreateWindow(
            "foo",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            800,
            640,
            SDL_WINDOW_SHOWN
        );

        if (window != 0) {
            renderer = SDL_CreateRenderer(window, -1, 0);

            if (renderer != 0) {
                SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
                init_success = true;
            }
        }
    }

    return init_success;
}

void App::events()
{
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
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
    SDL_RenderPresent(renderer);
}

void App::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
