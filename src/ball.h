#ifndef BALL_H_
#define BALL_H_

#include <math.h>

#include "entity.h"
#include "display_params.h"

class Ball : public Entity
{
public:
    enum class Direction { kPositive, kNegative }; 

    Ball(DisplayParams displayParams);
    ~Ball();
    
    void Update() override;
    void ChangeDirectionX();
    void ChangeDirectionY();
    void CheckPlayingFieldCollisions();

    //position
    //float x, y; //(jpremec) todo: getter and setter
    //dimensions
    //float width, height; //(jpremec) todo: getter and setter
    //direction of movement

    bool alive{true};
private:
    const float speed{2.0};
    const std::size_t screen_width;
    const std::size_t screen_height;

    Direction movementDirX{Direction::kPositive};
    Direction movementDirY{Direction::kNegative};
};

#endif