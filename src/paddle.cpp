#include "paddle.h"

Paddle::Paddle(DisplayParams displayParams)
    : paddleHeight(displayParams.grid_height/2),
      paddleWidth(displayParams.grid_width * 4),
      y(displayParams.screen_height-displayParams.grid_height*2),
      x(displayParams.screen_width/2 - displayParams.grid_width*2){} //todo: connect them to screen variables 

Paddle::~Paddle() {}

void Paddle::Update() {}
