#include "bullets.h"

void InitBullets(Bullet bullets[]) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = false;
    }
}

void UpdateBullets(Bullet bullets[], float dt) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            bullets[i].position.x += bullets[i].velocity.x * dt;
            bullets[i].position.y += bullets[i].velocity.y * dt;

            if (bullets[i].position.y < 0 ||
                bullets[i].position.y > 450 ||
                bullets[i].position.x < 0 ||
                bullets[i].position.x > 800)
            {
                bullets[i].active = false;
            }
        }
    }
}

void DrawBullets(Bullet bullets[]) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            DrawCircleV(bullets[i].position, 5, BLUE);
        }
    }
}

void ShootBullet(Bullet bullets[], Vector2 origin, Vector2 direction) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].active) {
            bullets[i].active = true;
            bullets[i].position = origin;
            bullets[i].velocity = direction;
            break;
        }
    }
}

