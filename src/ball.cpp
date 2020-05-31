#include "ball.h"

Ball::Ball(DisplayParams displayParams)
    : x(displayParams.screen_width / 2),
      y(displayParams.screen_height - (3 * displayParams.grid_height)),
      height(displayParams.grid_height),
      screen_width(displayParams.screen_width),
      screen_height(displayParams.screen_height)
{
}
Ball::~Ball() {}

void Ball::Update()
{
    // Moving the ball
    if (movementDirX == Direction::kPositive)
    {
        Ball::x += speed; 
    }
    else
    {
        Ball::x -= speed;
    }

    if (movementDirY == Direction::kPositive)
    {
        Ball::y += speed;
    }
    else
    {
        Ball::y -= speed;
    }
    Ball::CheckPlayingFieldCollisions();
}

void Ball::ChangeDirectionX()
{
    Ball::movementDirX = (Ball::movementDirX == Ball::Direction::kNegative) ? Ball::Direction::kPositive : Ball::Direction::kNegative;
}

void Ball::ChangeDirectionY()
{
    Ball::movementDirY = (Ball::movementDirY == Ball::Direction::kNegative) ? Ball::Direction::kPositive : Ball::Direction::kNegative;
}

void Ball::CheckPlayingFieldCollisions()
{
    if ((Ball::x >= Ball::screen_width) || (Ball::x <= 0))
    {
        Ball::ChangeDirectionX();
    }
    if (Ball::y <= 0)
    {
        Ball::ChangeDirectionY();
    }
    if (Ball::y > Ball::screen_height) 
    {
        Ball::alive = false;
    }
}
