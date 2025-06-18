#ifndef ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

#define MAX_ENEMIES 100

typedef struct Enemy {
    Vector2 position;
    float speed;
    int active;
    int health;
} Enemy;

void InitEmemies(Enemy enemies[]);
void SpawnEnemy(Enemy enemies[], Vector2 playerPos, float dt);
void DrawEnemies(Enemy enemies[]);

#endif