// Tetris using raylib
// IbletzFuller 2024/07/23
// tutorial: youtu.be/wVYKG_ch4yM?si=ulDCoMk4-0dbe9ZH

#include "raylib.h"

int main()
{
	InitWindow(300, 600, "raylib Tetris");

	SetTargetFPS(60);
	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		// Event handling

		// Updating states

		// Drawing

		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}