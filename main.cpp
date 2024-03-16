#include "snake.h"

Snake *snake = nullptr;

int main(int argc, char *argv[])
{

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    snake = new Snake();

    snake->init("SnakeScreen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 640, false);

    while(snake->running())

    {

        frameStart = SDL_GetTicks();

        snake->handleEvents();
        snake->update();
        snake->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    snake->clean();

    return 0;
}