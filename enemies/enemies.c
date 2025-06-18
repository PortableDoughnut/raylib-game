#include "enemies.h"
#include <math.h>

void InitEnemies(Enemy enemies[]) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].active = 0;
    }
}

void SpawnEnemy(Enemy enemies[], Vector2 position) {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        if(!enemies[i].active)
    }
}