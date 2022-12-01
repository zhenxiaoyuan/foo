#include "SDL3/SDL.h"
#include "SDL3/SDL_image.h"

class App {
    public:
        App();
        ~App();

        void run();

    private:
        bool init();
        void events();
        void update();
        void render();
        void clean();

        void load_texture();

        SDL_Window* window = 0;
        SDL_Renderer* renderer = 0;
        SDL_Texture* texture = 0;

        bool running = false;
};