#include "block.h"

Block::Block()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	rowOffset = 0;
	columnOffset = 0;
}

void Block::draw()
{
	std::vector<Position> tiles = getCellPositions();
	for (Position item : tiles)
	{
		DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize -1 , colors[id]);
	}
}

// move the block by changing the grid offsets
void Block::move(int rows, int columns)
{
	rowOffset += rows;
	columnOffset += columns;
}

std::vector<Position> Block::getCellPositions()
{
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;
	// calculate new cell positions and push to movedTiles vector
	for (Position item : tiles)
	{
		Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
		movedTiles.push_back(newPos);
	}
	return movedTiles;
}