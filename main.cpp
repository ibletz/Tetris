// Tetris using raylib
// IbletzFuller 2024/07/23
// tutorial: youtu.be/wVYKG_ch4yM?si=ulDCoMk4-0dbe9ZH

#include "raylib.h"
#include "grid.h"
#include "blocks.cpp"

int main()
{
	Color darkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "raylib Tetris");

	Grid grid{};
	grid.print();

	IBlock block = IBlock();


	SetTargetFPS(60);
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(darkBlue);

		// Event handling

		// Updating states

		// Drawing
		grid.draw();
		block.draw();

		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}