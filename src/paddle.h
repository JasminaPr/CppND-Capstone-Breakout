#ifndef PADDLE_H_
#define PADDLE_H_

#include <cstddef>
#include "display_params.h"

class Paddle
{
public:
    enum class Direction { kLeft, kRight }; //works for paddle, not ball

    Paddle(DisplayParams displayParams);
    Paddle();
    ~Paddle();

    void Update();

    //position
    float x, y; //(jpremec) todo: getter and setter
    //dimensions
    float paddleWidth, paddleHeight; //(jpremec) todo: getter and setter

    Direction direction;

    float speed{15.0}; // taken from snake todo

private:
};

#endif