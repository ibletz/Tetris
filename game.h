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
	bool gameOver;

private:
	bool isBlockOutside();
	void rotateBlock();
	void LockBlock();
	// check cells of a block to see if they are on top of empty grid cells
	bool blockFits();
	// vector holds all block types
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;

};