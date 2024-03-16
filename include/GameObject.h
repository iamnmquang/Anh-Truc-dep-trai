#include "snake.h"

class GameObject 
{
public: 
    GameObject(const char* texturesheet, int xpos, int ypos);
    ~GameObject();

    void Update();
    void Render();

private:
    int x;
    int y;


    SDL_Texture* objTexture;
    SDL_Rect srcRect, desRect;
};
