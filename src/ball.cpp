#include "ball.h"

Ball::Ball(std::size_t screen_width,
           std::size_t screen_height,
           std::size_t grid_height)
    : x(screen_width / 2),
      y(screen_height - (3 * grid_height)),
      height(grid_height) {}
Ball::~Ball() {}

void Ball::Update()
{
    // Moving the ball
    if (movementDirX == DirectionX::kPositive)
    {
        Ball::x += speed * 0.05; // todo: for speed change here
    }
    else
    {
        Ball::x -= speed * 0.05;
    }

    if (movementDirY == DirectionY::kPositive)
    {
        Ball::y += speed * 0.05;
    }
    else
    {
        Ball::y -= speed * 0.05;
    }
}



void Ball::SetDirection(float movementDirectionX, float movementDirectionY)
{
    float length = sqrt(movementDirectionX * movementDirectionX + movementDirectionY * movementDirectionY);
    this->movementDirectionX = kBallSpeed * (movementDirectionX / length);
    this->movementDirectionY = kBallSpeed + (movementDirectionY / length);
}