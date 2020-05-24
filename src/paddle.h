#ifndef PADDLE_H_
#define PADDLE_H_

class Paddle
{
public:
    //enum class Direction { kUp, kDown, kLeft, kRight }; //works for paddle, not ball

    Paddle();
    ~Paddle();

    void Update();
 
    float paddleWidth, paddleHeight;
private:
};

#endif