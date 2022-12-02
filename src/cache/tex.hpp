#include <string>
#include <map>

#include "SDL/SDL.h"

class Tex
{
public:
    Tex(Tex &other) = delete;
    void operator= (const Tex &) = delete;

    static Tex* Cache();

    void load(SDL_Renderer*, std::string, std::string, int, int);
    void draw(SDL_Renderer* renderer, std::string id, int frame, int row, int x, int y, int w, int h, SDL_RendererFlip flip);

private:
    Tex();
    ~Tex();

    static Tex* tex_cache;

    std::map<std::string, SDL_Texture*> tex_map;
};

