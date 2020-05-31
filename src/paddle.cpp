#include "paddle.h"

Paddle::Paddle(DisplayParams displayParams)
    : height(displayParams.grid_height / 2),
      width(displayParams.grid_width * 4),
      y(displayParams.screen_height - displayParams.grid_height * 2),
      x(displayParams.screen_width / 2 - displayParams.grid_width * 2),
      screen_width(displayParams.screen_width)
{
}
Paddle::~Paddle() {}

void Paddle::Update()
{
  Paddle::CheckPaddleBorders();
}

void Paddle::CheckPaddleBorders()
{
  if (Paddle::x >= screen_width - Paddle::width)
  {
    Paddle::x = screen_width - Paddle::width;
  }
  else if (Paddle::x <= 0)
  {
    Paddle::x = 0;
  }
}
