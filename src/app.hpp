#include "SDL3/SDL.h"

class App {
    public:
        App();
        ~App();

        void run();

    private:
        bool init(
            const char* title,
            const int xpos,
            const int ypos,
            const int height,
            const int width,
            const int flags
        );
        void events();
        void update();
        void render();
        void clean();

        SDL_Window* window = 0;
        SDL_Renderer* renderer = 0;

        bool running = false;
};