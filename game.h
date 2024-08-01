#pragma once
#include "grid.h"
#include "blocks.cpp"

/* Game class to hold all related game and update logic */

class Game
{
public:
	Game();
	~Game();
	void draw();
	void handleInput();
	void moveBlockDown();
	bool gameOver;
	int score;
	Music music;

private:
	Block getRandomBlock();
	std::vector<Block> getAllBlocks();
	void moveBlockLeft();
	void moveBlockRight();
	bool isBlockOutside();
	void rotateBlock();
	void LockBlock();
	// check cells of a block to see if they are on top of empty grid cells
	bool blockFits();
	// vector holds all block types
	void Reset();
	void updateScore(int linesCleared, int moveDownPoints);
	std::vector<Block> blocks;
	Grid grid;
	Block currentBlock;
	Block nextBlock;
	Sound rotateSound;
	Sound clearSound;
	Sound lockSound;

};