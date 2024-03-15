#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int xpos, int ypos)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);

    x = xpos;
    y = ypos;
}

void GameObject::Update()
{

    x++;
    y++;

    srcRect.h = 64;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;

    desRect.x = x;
    desRect.y = y;
    desRect.w = srcRect.w * 2;
    desRect.h = srcRect.h * 2;

}

void GameObject::Render()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &desRect);
}