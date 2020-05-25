#ifndef BOARD_H_
#define BOARD_H_

#include <math.h>

class Brick
{
public:
    int type;
    bool state;
};

namespace board_parameters
{
constexpr int board_width = 12;
constexpr int board_height = 12;
constexpr int board_brick_width = 64;
constexpr int board_brick_height = 24;
} // namespace board_parameters

class Board
{
public:
    //enum class Direction { kUp, kDown, kLeft, kRight }; //works for paddle, not ball

    Board();
    ~Board();

    void Update();
    void CreateLevel(); // todo: check usability

    Brick bricks[board_parameters::board_width][board_parameters::board_height];

    float brickoffsetx, brickoffsety; // private then getter and setter
    float x, y; //(jpremec) todo: getter and setter
private:
};

#endif