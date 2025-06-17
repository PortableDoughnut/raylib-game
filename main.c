#include "raylib.h"
#include "bullets.h"


int main(void) {
	InitWindow(800, 450, "Bullet Them up!");
	SetTargetFPS(100);

	Vector2 playerPos = { 400, 225 };
	float playerSpeed = 300.0f;
	float radius = 20.0f;
	
	Bullet bullets[MAX_BULLETS] = { 0 };
	InitBullets(bullets);
		
	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		
		if (IsKeyDown(KEY_D)) playerPos.x += playerSpeed * GetFrameTime() * dt;
		if (IsKeyDown(KEY_A)) playerPos.x -= playerSpeed * GetFrameTime() * dt;
		if (IsKeyDown(KEY_W)) playerPos.y -= playerSpeed * GetFrameTime() * dt;
		if (IsKeyDown(KEY_S)) playerPos.y += playerSpeed * GetFrameTime() * dt;
		
		if (position.x < radius) playerPos.x = radius;
		if (position.x > 800 - radius) playerPos.x = 800 - radius;
		if (position.y < radius) playerPos.y = radius;
		if (position.y > 450 - radius) playerPos.y = 450 - radius;
		
		if (IsKeyPressed(KEY_SPACE)) {
			ShootBullet(bullets, playerPos, (Vector2){0, -600});
		}
		
		UpdateBullets(bullets, dt);
		
		BeginDrawing();
		ClearBackground(RAYWHITE);
		
		DrawCircleV(playerPos, 20, PINK);
		DrawBullets(bullets);
		
		EndDrawing();
	} 
	
	CloseWindow();
	return 0;
}
