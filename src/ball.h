#ifndef BALL_H_
#define BALL_H_

#include <math.h>

//Define ball speed
constexpr float kBallSpeed = 550; //pixels per second

class Ball
{
public:
    enum class DirectionX { kPositive, kNegative }; 
    enum class DirectionY { kPositive, kNegative };

    Ball(std::size_t screen_width,
         std::size_t screen_height,
         std::size_t grid_height);
    ~Ball();

    void Update(float deltaTimeSec);
    void Update();
    void SetDirection(float ballDirectionX, float ballDirectionY);

    //position
    float x, y; //(jpremec) todo: getter and setter
    //dimensions
    float width, height; //(jpremec) todo: getter and setter
    //direction of movement
    DirectionX movementDirX{DirectionX::kPositive};
    DirectionY movementDirY{DirectionY::kNegative};
    float movementDirectionX, movementDirectionY;
    float speed{0.001f};
private:
    
};

#endif