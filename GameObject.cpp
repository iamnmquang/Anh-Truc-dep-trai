#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int xpos, int ypos)
{
    objTexture = TextureManager::LoadTexture(texturesheet);

    x = xpos;
    y = ypos;
}

void GameObject::Update()
{

    x++;
    y++;

    srcRect.h = 128;
    srcRect.w = 128;
    srcRect.x = 16;
    srcRect.y = 16;

    desRect.x = x;
    desRect.y = y;
    desRect.w = srcRect.w * 2;
    desRect.h = srcRect.h * 2;

}

void GameObject::Render()
{
    SDL_RenderCopy(Snake::renderer, objTexture, &srcRect, &desRect);
}