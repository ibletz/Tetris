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

// Check for out of bounds cells of a block, return false if cell is in bounds
bool Grid::isCellOutside(int row, int column)
{
	if (row >= 0 && row < numRows && column >= 0 && column < numColumns)
		return false;
	return true;
}
