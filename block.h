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
	int id;
	std::map<int, std::vector<Position>> cells;
	
private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;

};