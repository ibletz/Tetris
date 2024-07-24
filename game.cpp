#include "game.h"
#include <random>

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