#include "snake.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* jerry;
GameObject* Tom;

Snake::Snake()
{}
Snake::~Snake()
{}

void Snake::init(const char *title, int x, int y, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialised!..." << std::endl;

        window = SDL_CreateWindow(title, x, y, width, height, flags);
        if(window)
        {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl; 
        }

        isRunning = true;
    }

    jerry = new GameObject("jerry.png", renderer, 0, 0);
    Tom = new GameObject("Tom.jpg", renderer, 50 , 50);
};

void Snake::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Snake::update()
{
    jerry->Update();
    Tom->Update();
}

void Snake::render()
{
    SDL_RenderClear(renderer);
    // this is where wwe would add stuff to render
    jerry->Render();
    Tom->Render();
    SDL_RenderPresent(renderer);

}

void Snake::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}