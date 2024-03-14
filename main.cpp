#include "snake.h"

Snake *snake = nullptr;

int main(int argc, const char *argv[])
{
    snake = new Snake();

    snake->init("SnakeScreen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(snake->running())
    {
        snake->handleEvents();
        snake->update();
        snake->render();

    }

    snake->clean();

    return 0;
}