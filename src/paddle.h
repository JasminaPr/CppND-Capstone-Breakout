#ifndef PADDLE_H_
#define PADDLE_H_

class Paddle
{
public:
    enum class Direction { kLeft, kRight }; //works for paddle, not ball

    Paddle();
    ~Paddle();

    void Update();

    //position
    float x, y; //(jpremec) todo: getter and setter
    //dimensions
    float paddleWidth, paddleHeight; //(jpremec) todo: getter and setter

private:
};

#endif