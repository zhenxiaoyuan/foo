#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "constants.hpp"
#include "object/player.hpp"

class Application {
    public:
        static Application* Instance();

        void init();
        void run();
        void clean();

        void set_running(bool running);
        SDL_Renderer* get_renderer();

    private:
        Application();
        ~Application();

        static Application* instance;

        const int FPS = 60;
        const int DELAY_TIME = 1000.0f / 60;

        void events();
        void update();
        void render();

        SDL_Window* window = 0;
        SDL_Renderer* renderer = 0;

        bool running = false;

        Player* player = new Player(new CharacterParams("player_idle", TEX_PLAYER_ROW, TEX_PLAYER_COLUMN, 100, 100, PLAYER_WIDTH, PLAYER_HEIGHT, 4));
};