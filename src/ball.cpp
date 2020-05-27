#include "ball.h"

Ball::Ball(std::size_t screen_width, std::size_t screen_height, std::size_t grid_height) : x(screen_width/2), y(screen_height-(3*grid_height)) {}
Ball::~Ball() {}

void Ball::Update(float deltaTimeSec)
{
    // Moving the ball
    Ball::x += Ball::movementDirectionX * deltaTimeSec;
    Ball::y += Ball::movementDirectionY * deltaTimeSec;
}

void Ball::SetDirection(float movementDirectionX, float movementDirectionY)
{
    float length = sqrt(movementDirectionX * movementDirectionX + movementDirectionY * movementDirectionY);
    this->movementDirectionX = kBallSpeed * (movementDirectionX / length);
    this->movementDirectionY = kBallSpeed + (movementDirectionY / length);
}