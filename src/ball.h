#ifndef BALL_H_
#define BALL_H_

#include <math.h>
#include "display_params.h"

class Ball
{
public:
    enum class DirectionX { kPositive, kNegative }; 
    enum class DirectionY { kPositive, kNegative };

    Ball(DisplayParams displayParams);
    ~Ball();

    void Update(float deltaTimeSec);
    void Update();
    /*void SetDirection(float ballDirectionX, float ballDirectionY);*/

    //position
    float x, y; //(jpremec) todo: getter and setter
    //dimensions
    float width, height; //(jpremec) todo: getter and setter
    //direction of movement
    DirectionX movementDirX{DirectionX::kPositive};
    DirectionY movementDirY{DirectionY::kNegative};
    //float movementDirectionX, movementDirectionY;
    float speed{2.0};
private:
    
};

#endif