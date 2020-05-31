#include "board.h"
//using namespace board_parameters;

Board::Board(DisplayParams displayParams)
    : x(0),
      y(50)
{
  //  brickoffsetx = (displayParams.screen_width -
   //                 (board_parameters::board_width * board_parameters::board_brick_width)) / (board_parameters::board_width );
}
Board::~Board() {}

void Board::Update() {}
void Board::CreateLevel() {}
