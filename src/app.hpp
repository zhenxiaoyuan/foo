#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "object/player.hpp"

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

        SDL_Window* window = 0;
        SDL_Renderer* renderer = 0;

        bool running = false;

        Player* player = new Player;
};