#include "raylib.h"
#include "raymath.h"
#include "bullets.h"


int main(void) {
	InitWindow(800, 450, "Bullet Them up!");
	SetTargetFPS(100);

	Vector2 playerPos = { 400, 225 };
	float playerSpeed = 300.0f;
	float radius = 20.0f;

	Vector2 facingDirection = {1, 0};
	
	Bullet bullets[MAX_BULLETS] = { 0 };
	InitBullets(bullets);
		
	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		
		Vector2 moveInput = { 
		    (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)), 
		    (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) 
		};
		
		if (moveInput.x != 0 || moveInput.y != 0) {
		    moveInput = Vector2Normalize(moveInput);
		    playerPos = Vector2Add(playerPos, Vector2Scale(moveInput, playerSpeed * dt));
		    facingDirection = moveInput;
		}
		
		if (playerPos.x < radius) playerPos.x = radius;
		if (playerPos.x > 800 - radius) playerPos.x = 800 - radius;
		if (playerPos.y < radius) playerPos.y = radius;
		if (playerPos.y > 450 - radius) playerPos.y = 450 - radius;
		
		if (IsKeyPressed(KEY_SPACE)) {
			ShootBullet(bullets, playerPos, (Vector2){facingDirection.x * 600, facingDirection.y * 600});
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
