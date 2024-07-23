#pragma once
#include <vector>
#include "raylib.h"

class Grid
{
public:
	Grid();
	int grid[20][10];
	void Initialize(int value);
	void print();
	void draw();

private:
	int numRows{};
	int numColumns{};
	int cellSize{};
	std::vector<Color> colors;
	std::vector<Color> GetCellColors();
};