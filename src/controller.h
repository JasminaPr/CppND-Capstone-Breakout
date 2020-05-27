#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "paddle.h"

class Controller {
 public:
  //void HandleInput(bool &running, Snake &snake, Paddle &paddle) const;
  void HandleInput(bool &running, Paddle &paddle) const;

 private:
  void SetPaddleX(Paddle &paddle, Paddle::Direction input) const;
};

#endif