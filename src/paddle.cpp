#include "paddle.h"
#include <cstddef>

Paddle::Paddle(std::size_t screen_width, std::size_t screen_height, std::size_t grid_width, std::size_t grid_height)
    : paddleHeight(grid_height/2),
      paddleWidth(grid_width * 4),
      y(screen_height-grid_height*2),
      x(screen_width/2 - grid_width*2){} //todo: connect them to screen variables 

Paddle::~Paddle() {}

void Paddle::Update() {}
