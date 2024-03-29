#pragma once

#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
public:

    Vector2D position;
    Vector2D velocity;

    int height = 32;
    int width = 32;
    int scale = 1;

    int speed = 8;

    TransformComponent()
    {
        position.x = 100.0f;
        position.y = 100.0f;
    }

    TransformComponent(int sc)
    {
        position.x = 100;
        position.y = 100;
        scale = sc;
    }

    TransformComponent(float x, float y)
    {
        position.x = 100;
        position.y = 100;
    }

     TransformComponent(float x, float y, int h, int w, int sc)
    {
    
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }

    void init() override
    {
        velocity.Zero();
    }

    void update() override
    {
        position.x += velocity.x * speed;
        if(position.x < 0 )
        {
            position.x -= velocity.x * speed;
        }
        position.y += velocity.y * speed;
        if(position.y < 0 )
        {
            position.y -= velocity.y *speed;
        }
    }

};