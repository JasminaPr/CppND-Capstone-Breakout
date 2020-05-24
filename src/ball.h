#ifndef BALL_H_
#define BALL_H_

#include <math.h>

//Define ball speed
constexpr float kBallSpeed = 550; //pixels per second

class Ball
{
public:
    //enum class Direction { kUp, kDown, kLeft, kRight }; //works for paddle, not ball

    Ball();
    ~Ball();

    void Update();
 //   void Render();

    void SetDirection(float ballDirectionX, float ballDirectionY);

    float x, y; //(jpremec) todo: getter and setter

private:
    float ballDirectionX, ballDirectionY;
};

#endif