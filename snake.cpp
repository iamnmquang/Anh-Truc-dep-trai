#include "snake.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"
//#include "GameObject.h"

Map *map;
Manager manager;

SDL_Event Snake::event;
SDL_Renderer *Snake::renderer = nullptr;
auto &player(manager.addEntity());
auto &wall(manager.addEntity());

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
    
    map = new Map();
    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("Ohno.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");

    wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
    wall.addComponent<SpriteComponent>("dirt.png");
    wall.addComponent<ColliderComponent>("wall");

};

void Snake::handleEvents()
{
    
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
    manager.update();
    manager.refresh();

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider))
    {
        player.getComponent<TransformComponent>().scale = 1;
        std::cout << "Wall hit!" << std::endl;
    }
    
}

void Snake::render()
{
    SDL_RenderClear(renderer);
    // this is where wwe would add stuff to render
    map->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);

}

void Snake::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}
