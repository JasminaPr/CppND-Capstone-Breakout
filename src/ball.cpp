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



/*void Ball::SetDirection(float movementDirectionX, float movementDirectionY)
{
    float length = sqrt(movementDirectionX * movementDirectionX + movementDirectionY * movementDirectionY);
    this->movementDirectionX = kBallSpeed * (movementDirectionX / length);
    this->movementDirectionY = kBallSpeed + (movementDirectionY / length);
}*/