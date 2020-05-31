#include "ball.h"

Ball::Ball(DisplayParams displayParams)
    : screen_width(displayParams.screen_width),
      screen_height(displayParams.screen_height)
{
    // set initial position and size of the ball
    x = displayParams.screen_width / 2;
    y = displayParams.screen_height - (3 * displayParams.grid_height);
    height = displayParams.grid_height;
}
Ball::~Ball() {}

void Ball::Update()
{
    // Moving the ball further
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
    // check if ball collides with playing field
    Ball::CheckPlayingFieldCollisions();
}

// function ot change direction of the ball
void Ball::ChangeDirectionX()
{
    Ball::movementDirX = (Ball::movementDirX == Ball::Direction::kNegative) ? Ball::Direction::kPositive : Ball::Direction::kNegative;
}

void Ball::ChangeDirectionY()
{
    Ball::movementDirY = (Ball::movementDirY == Ball::Direction::kNegative) ? Ball::Direction::kPositive : Ball::Direction::kNegative;
}

// check whether ball has hit a playing field limit, change direction of the ball
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
