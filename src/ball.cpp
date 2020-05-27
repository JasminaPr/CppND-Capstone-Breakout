#include "ball.h"

Ball::Ball() : x(0), y(0) {}
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