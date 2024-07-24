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
	void handleInput();
	void moveBlockLeft();
	void moveBlockRight();
	void moveBlockDown();
	Grid grid;

private:
	bool isBlockOutside();
	void rotateBlock();
	// vector holds all block types
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;

};