#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "object/player.hpp"

class Application {
    public:
        static Application* Instance();

        void init();
        void run();
        void clean();

        SDL_Renderer* get_renderer();

    private:
        Application();
        ~Application();

        static Application* instance;

        void events();
        void update();
        void render();

        SDL_Window* window = 0;
        SDL_Renderer* renderer = 0;

        bool running = false;

        Player* player = new Player(new CharacterParams("player_idle", 1, 6, 100, 100, 48, 48));
};