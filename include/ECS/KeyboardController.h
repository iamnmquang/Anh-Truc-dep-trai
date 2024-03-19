#include "snake.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
    TransformComponent *tranform;

    void init() override
    {
        tranform = &entity->getComponent<TransformComponent>();
    }

    void update() override
    {
        if(Snake::event.type == SDL_KEYDOWN)
        {
            switch (Snake::event.key.keysym.sym)
            {
            case SDLK_w:
                tranform->velocity.y = -1;
                break;
            case SDLK_a:
                tranform->velocity.x = -1;
                break;
            case SDLK_d:
                tranform->velocity.x = 1;
                break;
            case SDLK_s:
                tranform->velocity.y = 1;
                break;
            default:
                break;
            }
        }

        if(Snake::event.type == SDL_KEYUP)
        {
            switch (Snake::event.key.keysym.sym)
            {
            case SDLK_w:
                tranform->velocity.y = 0;
                break;
            case SDLK_a:
                tranform->velocity.x = 0;
                break;
            case SDLK_d:
                tranform->velocity.x = 0;
                break;
            case SDLK_s:
                tranform->velocity.y = 0;
                break;
            default:
                break;
            }
        }
    }
};
