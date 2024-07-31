// Tetris using raylib
// IbletzFuller 2024/07/23
// tutorial: youtu.be/wVYKG_ch4yM?si=ulDCoMk4-0dbe9ZH

#include "raylib.h"
#include "game.h"
#include "colors.h"

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
	InitWindow(500, 620, "raylib Tetris");

	Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

	Game game = Game();

	SetTargetFPS(60);
	while (WindowShouldClose() == false)
	{

		// Event handling
		game.handleInput();

		// Updating states
		if (EventTriggered(0.2))
			game.moveBlockDown();

		// Drawing
		BeginDrawing();
		ClearBackground(darkBlue);
		
		// UI Elements
		DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);
		DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
		if(game.gameOver)
			DrawTextEx(font, "Game Over", { 320, 450 }, 38, 2, WHITE);

		game.draw();

		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}