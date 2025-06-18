#ifndef BULLETS_H
#define BULLETS_H

#include "raylib.h"

#define MAX_BULLETS 100

typedef struct Bullet {
    Vector2 position;
    Vector2 velocity;
    bool active;
} Bullet;

void InitBullets(Bullet bullets[]);
void UpdateBullets(Bullet bullets[], float dt);
void DrawBullets(Bullet bullets[]);
void ShootBullet(Bullet bullets[], Vector2 origin, Vector2 direction);

#endif
