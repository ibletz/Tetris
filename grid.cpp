#include "grid.h"
#include <iostream>

Grid::Grid()
{
	numRows = 20;
	numColumns = 10;
	cellSize = 30;
	Initialize(0);
	colors = GetCellColors();
}

// Initialize all cells of the grid
void Grid::Initialize(int value)
{
	for (int row = 0; row < numRows; row++)
		for (int column = 0; column < numColumns; column++)
			grid[row][column] = 0;
}

// Print the grid
void Grid::print()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumns; column++)
		{
			std::cout << grid[row][column] << ' ';
		}
		std::cout << '\n';
	}
}

// Get a vector containing the colors for the blocks and empty cells
std::vector<Color> Grid::GetCellColors()
{
	Color darkGrey{26, 31, 40, 255};
	Color green{ 47, 230, 23, 255 };
	Color red{ 232, 18, 18, 255 };
	Color orange{ 226, 116, 17, 255 };
	Color yellow{ 237, 234, 4, 255 };
	Color purple{ 116, 0, 247, 255 };
	Color cyan{ 21, 204, 209, 255 };
	Color blue{ 13, 64, 216, 255 };

	return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
}

// Draw the grid with colors
void Grid::draw()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumns; column++)
		{
			int cellValue = grid[row][column];
			DrawRectangle(column * cellSize+1, row * cellSize+1, cellSize-1, cellSize-1, colors[cellValue]);
		}
	}

}
