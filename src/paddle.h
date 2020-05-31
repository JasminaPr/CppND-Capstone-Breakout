#ifndef PADDLE_H_
#define PADDLE_H_

#include <cstddef>
#include "display_params.h"

class Paddle
{
public:
    enum class Direction
    {
        kLeft,
        kRight
    };

    Paddle(DisplayParams displayParams);
    Paddle();
    ~Paddle();

    void Update(); // override

    void CheckPaddleBorders();

    //dimensions
    float width, height; //(jpremec) todo: getter and setter
                         //position
    float x, y;          //(jpremec) todo: getter and setter

private:
    friend class Controller;

    Direction direction;
    float speed{15.0};
    const std::size_t screen_width;
};

#endif