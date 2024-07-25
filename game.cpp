#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game()
{
	grid = Grid();
	blocks = getAllBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
}

// select a random block to appear next
// each block should be selected at least once before a block is repeated
Block Game::getRandomBlock()
{
	// if the vector has been emptied of blocks, refill it
	if (blocks.empty())
		blocks = getAllBlocks();

	// get a random index in the blocks vector
	// seed random generator to randomize blocks
	srand((unsigned int)time(NULL));
	int randomIndex = rand() % blocks.size();
	// create a new block of random type
	Block block = blocks[randomIndex];
	// remove that block from the vector to avoid repeats
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

// return a new vector filled with all block types
std::vector<Block> Game::getAllBlocks()
{
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

// call the draw functions of the objects in the game
void Game::draw()
{
	grid.draw();
	currentBlock.draw();
}

// detect and handle player input
void Game::handleInput()
{
	int keyPressed = GetKeyPressed();
	switch (keyPressed)
	{
	case KEY_LEFT:
		moveBlockLeft();
		break;
	case KEY_RIGHT:
		moveBlockRight();
		break;
	case KEY_DOWN:
		moveBlockDown();
		break;
	case KEY_UP:
		rotateBlock();
		break;
	}
}

// Three methods for moving the block left, right, and down
void Game::moveBlockLeft()
{
	currentBlock.move(0, -1);
	// undo movement if block ends up out of bounds
	if (isBlockOutside() || blockFits() == false)
		currentBlock.move(0, 1);
}
void Game::moveBlockRight()
{
	currentBlock.move(0, 1);
	// undo movement if block ends up out of bounds
	if (isBlockOutside() || blockFits() == false)
		currentBlock.move(0, -1);
}
void Game::moveBlockDown()
{
	currentBlock.move(1, 0);
	// undo movement if block ends up out of bounds
	if (isBlockOutside() || blockFits() == false)
	{
		currentBlock.move(-1, 0);
		LockBlock();
	}
}

// use grid class function to check if any cells of a block are out of bounds
bool Game::isBlockOutside()
{
	std::vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles)
	{
		if (grid.isCellOutside(item.row, item.column))
			return true;
	}
	return false;
}

// use block class function to rotate blocks
void Game::rotateBlock()
{
	currentBlock.rotate();
	if (isBlockOutside() || blockFits() == false)
		currentBlock.undoRotation();
}

// locks block movement and rotation, then checks for completed rows with clearFullRows()
void Game::LockBlock()
{
	std::vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles)
	{
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	nextBlock = getRandomBlock();
	grid.ClearFullRows();
}

// check if a block's cells are all on top of empty grid cells.
bool Game::blockFits()
{
	std::vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles)
	{
		if (grid.isCellEmpty(item.row, item.column) == false)
			return false;
	}
	return true;
}
