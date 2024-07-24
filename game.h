#pragma once
#include "grid.h"
#include "blocks.cpp"

/* Game class to hold all related game and update logic */

class Game
{
public:
	Game();
	Block getRandomBlock();
	std::vector<Block> getAllBlocks();
	void draw();
	Grid grid;

private:
	// vector holds all block types
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;

};