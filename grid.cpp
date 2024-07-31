#include "grid.h"
#include <iostream>

Grid::Grid()
{
	numRows = 20;
	numColumns = 10;
	cellSize = 30;
	Initialize();
	colors = GetCellColors();
}

// Initialize all cells of the grid to empty
void Grid::Initialize()
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

// check if a cell on the grid is occupied
bool Grid::isCellEmpty(int row, int column)
{
	if (grid[row][column] == 0)
		return true;
	return false;
}

// check all rows on grid to see if any are completed, and clear / move down rows correctly
int Grid::ClearFullRows()
{
	int completed = 0;
	for (int row = numRows - 1; row >= 0; row--)
	{
		if (isRowFull(row))
		{
			clearRow(row);
			completed++;
		}
		else if (completed > 0)
		{
			moveRowDown(row, completed);
		}
	}
	return completed;
}

// check if a grid row is full of occupied cells
bool Grid::isRowFull(int row)
{
	for (int column = 0; column < numColumns; column++)
	{
		if (grid[row][column] == 0)
			return false;
	}
	return true;
}

// clear a row of cells (set all cell ids to 0)
void Grid::clearRow(int row)
{
	for (int column = 0; column < numColumns; column++)
		grid[row][column] = 0;
}

// move an entire row of cells down by 'numRows' rows
void Grid::moveRowDown(int row, int numRows)
{
	for (int column = 0; column < numColumns; column++)
	{
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}
