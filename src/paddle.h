#ifndef PADDLE_H_
#define PADDLE_H_

#include <cstddef>

class Paddle
{
public:
    enum class Direction { kLeft, kRight }; //works for paddle, not ball

    Paddle(std::size_t screen_width, std::size_t screen_height, std::size_t grid_width, std::size_t grid_height);
    Paddle();
    ~Paddle();

    void Update();

    //position
    float x, y; //(jpremec) todo: getter and setter
    //dimensions
    float paddleWidth, paddleHeight; //(jpremec) todo: getter and setter

    Direction direction;

    float speed{0.1f}; // taken from snake todo

private:
};

#endif