#ifndef BOARD_H_
#define BOARD_H_

#include <math.h>

#include "entity.h"


class Brick
{
public:
    int type;
    bool state{true};
};

namespace board_parameters
{
constexpr int board_width = 7;
constexpr int board_height = 5;
constexpr int board_brick_width = 70;
constexpr int board_brick_height = 24;
} // namespace board_parameters

class Board : public Entity
{
public:
  
    Board();
    ~Board();

    void Update() override;

    Brick bricks[board_parameters::board_width][board_parameters::board_height];

};

#endif