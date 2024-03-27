
#include "SDL2/SDL.h"

class ColliderComponent;

class Collision
{
public:
    static bool AABB( SDL_Rect &recA,  SDL_Rect &recB);
    static void AdjustPosition(SDL_Rect &movingRect,  SDL_Rect &obstacleRect);
    static bool AABB( ColliderComponent &colA,  ColliderComponent &colB);
};