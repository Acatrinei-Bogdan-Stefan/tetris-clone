#pragma once
#include "grid.h"
#include "blocks.cpp"


class Game
{
  public:

  Game();  //Constructor
  void Draw();
  void HandleInput();
  void MoveBlockDown();
  bool gameOver;
  int score;

private:

  void MoveBlockLeft();
  void MoveBlockRight();
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  bool IsBlockOutside();
  void RotateBlock();
  void LockBlock();
  bool BlockFits();
  void Reset();
  void UpdateScore(int LinesCleared, int moveDownPoints);
  std::vector<Block> blocks;
  Grid grid;
  Block currentBlock;
  Block nextBlock;
};