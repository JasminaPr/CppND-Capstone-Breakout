#ifndef BALL_H_
#define BALL_H_

#include <math.h>

#include "entity.h"
#include "display_params.h"

class Ball : public Entity
{
public:
    enum class Direction
    {
        kPositive,
        kNegative
    };

    Ball(DisplayParams &displayParams);
    ~Ball();

    void Update() override;
    void ChangeDirectionX();
    void ChangeDirectionY();

    // getter
    bool isBallAlive() { return alive; }

private:
    void CheckPlayingFieldCollisions();

    const float speed{2.0};
    const std::size_t screen_width;
    const std::size_t screen_height;
    bool alive{true};

    Direction movementDirX{Direction::kPositive};
    Direction movementDirY{Direction::kNegative};
};

#endif