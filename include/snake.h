#ifndef Snake_h
#define Snake_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

class ColliderComponent;


class Snake
{
public:
    Snake();
    ~Snake();

    void init(const char* title, int x, int y,const int width,const int height, bool fullscreen);
 
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning;}

    static void AddTile(int id, int x, int y);
    static SDL_Event event;
    static SDL_Renderer* renderer;
    static std::vector<ColliderComponent*> colliders;

private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
};

#endif /* Snake_h */