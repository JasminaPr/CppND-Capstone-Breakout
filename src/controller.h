#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "paddle.h"

class Controller {
 public:
  void HandleInput(bool &running, Paddle &paddle) const;

 private:
  void SetPaddleX(Paddle &paddle, Paddle::Direction input) const;
};

#endif