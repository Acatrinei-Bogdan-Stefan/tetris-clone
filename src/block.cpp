#include "block.h"

Block::Block(){
  cellSize = 30;
  rotationState = 0;
  colors = GetCellColors();
  rowOffSet = 0;
  columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY){
  std::vector<Position> tiles = GetCellPosition();
  for(Position item: tiles){
    DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
  }
}

void Block::Move(int row, int columns)
{
  rowOffSet += row;
  columnOffset += columns;
}

std::vector<Position> Block::GetCellPosition()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for(Position item: tiles)
    {
      Position newPos = Position(item.row + rowOffSet, item.column + columnOffset);
      movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate()
{
  rotationState ++;
  if(rotationState == (int)cells.size())
  {
      rotationState = 0;
  }
}

void Block::UndoRotation()
{
  rotationState --;
  if(rotationState == -1)
  {
    rotationState = cells.size() - 1;
  }
}
