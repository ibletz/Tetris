// Tetris using raylib
// IbletzFuller 2024/07/23
// tutorial: youtu.be/wVYKG_ch4yM?si=ulDCoMk4-0dbe9ZH

#include "raylib.h"
#include "game.h"

// global variable to keep track of last game update
double lastUpdateTime{};
// make sure events are occurring at intervals, and not too fast
bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

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
		if (EventTriggered(0.2))
			game.moveBlockDown();

		// Drawing
		game.draw();

		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}