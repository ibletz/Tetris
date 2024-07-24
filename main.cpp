// Tetris using raylib
// IbletzFuller 2024/07/23
// tutorial: youtu.be/wVYKG_ch4yM?si=ulDCoMk4-0dbe9ZH

#include "raylib.h"
#include "game.h"

int main()
{
	Color darkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "raylib Tetris");

	Game game = Game();

	SetTargetFPS(60);
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(darkBlue);

		// Event handling
		game.handleInput();

		// Updating states

		// Drawing
		game.draw();

		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}