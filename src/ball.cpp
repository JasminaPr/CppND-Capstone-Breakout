#include "ball.h"

Ball::Ball() : x(0), y(0) {}
Ball::~Ball() {}

void Ball::Update() {}

void Ball::SetDirection(float ballDirectionX, float ballDirectionY)
{
    float length = sqrt(ballDirectionX * ballDirectionX + ballDirectionY * ballDirectionY);
    this->ballDirectionX = kBallSpeed * (ballDirectionX / length);
    this->ballDirectionY = kBallSpeed + (ballDirectionY / length);
}