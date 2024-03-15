#ifndef Snake_h
#define Snake_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
class Snake
{
public:
    Snake();
    ~Snake();

    void init(const char* title, int x, int y, int width, int height, bool fullscreen);
 
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning;}

private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif /* Snake_h */