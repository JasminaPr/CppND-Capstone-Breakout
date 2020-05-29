#include "ball.h"

Ball::Ball(DisplayParams displayParams)
    : x(displayParams.screen_width / 2),
      y(displayParams.screen_height - (3 * displayParams.grid_height)),
      height(displayParams.grid_height) {}
Ball::~Ball() {}

void Ball::Update()
{
    // Moving the ball
    if (movementDirX == DirectionX::kPositive)
    {
        Ball::x += speed; // todo: for speed change here
    }
    else
    {
        Ball::x -= speed;
    }

    if (movementDirY == DirectionY::kPositive)
    {
        Ball::y += speed;
    }
    else
    {
        Ball::y -= speed;
    }
}