#include "snake.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"
#include "GameObject.h"

Map *map;
Manager manager;

SDL_Event Snake::event;
SDL_Renderer *Snake::renderer = nullptr;

std::vector<ColliderComponent*> Snake::colliders;

auto &player(manager.addEntity());
auto &wall(manager.addEntity());

enum groupLabels : std::size_t
{
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders
};

Snake::Snake()
{}
Snake::~Snake()
{}

void Snake::init(const char *title, int x, int y,const int width,const int height, bool fullscreen)
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

    Map::LoadMap("Map.txt", 25, 20);

    player.addComponent<TransformComponent>(1);
    player.addComponent<SpriteComponent>("sba.png",2,1000);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);

     wall.addComponent<TransformComponent>(0.0f, 0.0f, 640, 32, 1);
     wall.addComponent<SpriteComponent>("dirt.png");
     wall.addComponent<ColliderComponent>("wall");
    wall.addGroup(groupMap);

     wall.addComponent<TransformComponent>(768.0f, 0.0f, 640, 32, 1);
     wall.addComponent<SpriteComponent>("dirt.png");
     wall.addComponent<ColliderComponent>("wall");
    wall.addGroup(groupMap);

    wall.addComponent<TransformComponent>(32.0f, 0.0f, 32, 736, 1);
     wall.addComponent<SpriteComponent>("dirt.png");
     wall.addComponent<ColliderComponent>("wall");
    wall.addGroup(groupMap);

    wall.addComponent<TransformComponent>(32.0f, 608.0f, 32, 736, 1);
     wall.addComponent<SpriteComponent>("dirt.png");
     wall.addComponent<ColliderComponent>("wall");
    wall.addGroup(groupMap);

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

for(auto& cc : colliders)
{
    // Kiểm tra va chạm giữa player và mỗi collider
    if(Collision::AABB(player.getComponent<ColliderComponent>(), *cc))
    {
        // Xử lý logic khi có va chạm
        
        // Đặt lại vị trí của player bằng vị trí trước đó

        // Dừng việc kiểm tra va chạm tiếp theo với các collider khác
    }
}
    
}

auto &tiles(manager.getGroup(groupMap));
auto &players(manager.getGroup(groupPlayers));
auto &enemies(manager.getGroup(groupEnemies));

void Snake::render()
{
    SDL_RenderClear(renderer);
    // this is where wwe would add stuff to render
    //map->DrawMap();
    // manager.draw();
    for(auto &t:tiles)
    {
        t->draw();
    }
    for(auto &p:players)
    {
        p->draw();
    }
    for(auto &e:enemies)
    {
        e->draw();
    }

    SDL_RenderPresent(renderer);

}

void Snake::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

void Snake::AddTile(int id, int x, int y)
{
    auto &tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, id);
    tile.addGroup(groupMap);
}
