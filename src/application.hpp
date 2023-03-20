#include "entt/entt.hpp"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "state/state_machine.hpp"

#include "systems/input/input_handler.hpp"
#include "object/character.hpp"
#include "constants.hpp"

class Application {
    public:
        static Application* Instance();

        void init();
        void run();
        void clean();

        void set_running(bool running);
        SDL_Renderer* get_renderer();
        entt::registry get_registry();

    private:
        Application();
        ~Application();

        static Application* instance;

        const int FPS = 60;
        const int DELAY_TIME = 1000.0f / FPS;

        void events();
        void update();
        void render();

        SDL_Window* window = 0;
        SDL_Renderer* renderer = 0;

        StateMachine* state_machine;
        bool running = false;

        // entt
        entt::registry registry;

        InputHandler* input_handler = new InputHandler();
        Character actor = Character(new CharacterParams("player_idle", TEX_PLAYER_ROW, TEX_PLAYER_COLUMN, 100, 100, PLAYER_WIDTH, PLAYER_HEIGHT, 4));

};