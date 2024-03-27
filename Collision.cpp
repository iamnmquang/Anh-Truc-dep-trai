#include "Collision.h"
#include "ECS/ColliderComponent.h"

bool Collision::AABB( SDL_Rect &recA,  SDL_Rect &recB)
{
    if (recA.x + recA.w >= recB.x && recB.x + recB.w >= recA.x &&
        recA.y + recA.h >= recB.y && recB.y + recB.h >= recA.y)
    {
        return true;
    }
    return false;
}

void Collision::AdjustPosition(SDL_Rect &movingRect, SDL_Rect &obstacleRect)
{
    // Nếu va chạm, điều chỉnh vị trí của movingRect sao cho nó không vượt qua obstacleRect
    // Điều chỉnh vị trí theo hướng nào phụ thuộc vào hướng di chuyển của movingRect

    int deltaX = (movingRect.x + movingRect.w / 2) - (obstacleRect.x + obstacleRect.w / 2);
    int deltaY = (movingRect.y + movingRect.h / 2) - (obstacleRect.y + obstacleRect.h / 2);

    int intersectX = abs(deltaX) - (movingRect.w + obstacleRect.w) / 2;
    int intersectY = abs(deltaY) - (movingRect.h + obstacleRect.h) / 2;

    if (intersectX > intersectY) {
        // Điều chỉnh theo trục y
        if (deltaY > 0)
            movingRect.y += intersectY;
        else
            movingRect.y -= intersectY;
    } else {
        // Điều chỉnh theo trục x
        if (deltaX > 0)
            movingRect.x += intersectX;
        else
            movingRect.x -= intersectX;
    }
}

bool Collision::AABB( ColliderComponent &colA,  ColliderComponent &colB)
{
    if (AABB(colA.collider, colB.collider))
    {
        std::cout << colA.tag << " hit " << colB.tag << std::endl;

        // Sau khi phát hiện va chạm, điều chỉnh vị trí của colA.collider (nếu cần)
        AdjustPosition(colA.collider, colB.collider);
        return true;
    }
    return false;
}

