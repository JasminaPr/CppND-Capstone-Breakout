#ifndef PADDLE_H_
#define PADDLE_H_

#include <cstddef>
#include "display_params.h"

class Paddle
{
public:
    enum class Direction { kLeft, kRight };

    Paddle(DisplayParams displayParams);
    Paddle();
    ~Paddle();

    void Update(); // override

    //dimensions
    float paddleWidth, paddleHeight; //(jpremec) todo: getter and setter
//position
    float x, y; //(jpremec) todo: getter and setter

    

private:
friend class Controller;
Direction direction;
//position
    
float speed{15.0}; 
};

#endif