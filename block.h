#pragma once

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
public:
	Block();
	void draw();
	void move(int rows, int columns);
	std::vector<Position> getCellPositions();
	void rotate();
	void undoRotation();
	// id used for choosing the color
	int id;
	std::map<int, std::vector<Position>> cells;
	
private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
	int rowOffset;
	int columnOffset;
};