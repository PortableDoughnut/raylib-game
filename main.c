#include "raylib.h"

int main(void) {
	InitWindow(800, 450, "Hello Raylib");
	SetTargetFPS(60);

	Vector2 position = { 400, 225 };
	float speed = 200.0f;
	
	while (!WindowShouldClose()) {
		if (IsKeyDown(KEY_RIGHT)) position.x += speed * GetFrameTime();
		if (IsKeyDown(KEY_LEFT)) position.x -= speed * GetFrameTime();
		if (IsKeyDown(KEY_UP)) position.y -= speed * GetFrameTime();
		if (IsKeyDown(KEY_DOWN)) position.y += speed * GetFrameTime();

		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawCircleV(position, 20, RED);
		EndDrawing();
	} 
	
	CloseWindow();
	return 0;
}
