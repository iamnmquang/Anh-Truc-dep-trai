#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
    SDL_Surface* temSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Snake::renderer, temSurface);
    SDL_FreeSurface(temSurface);

    return tex;
}

void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Snake::renderer, tex, &src, &dest);
}