#include <string>
#include <map>

#include "SDL/SDL.h"

class TextureManager
{
public:
    TextureManager(TextureManager &other) = delete;
    void operator= (const TextureManager &) = delete;

    static TextureManager* Instance();

    void load(std::string, std::string, int, int);
    void draw(std::string id, int frame, int row, int x, int y, int w, int h, SDL_RendererFlip flip);

private:
    TextureManager();
    ~TextureManager();

    static TextureManager* instance;

    std::map<std::string, SDL_Texture*> tex_map;
};

