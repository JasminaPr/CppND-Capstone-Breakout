#include "controller.h"
#include <iostream>
#include "SDL.h"
//#include "paddle.h"

void Controller::SetPaddleX(Paddle &paddle, Paddle::Direction input) const
{
  paddle.direction = input;

  switch (paddle.direction)
  {
  case Paddle::Direction::kLeft:
    paddle.x -= paddle.speed;
    break;
  case Paddle::Direction::kRight:
    paddle.x += paddle.speed;
    break;
  }
}

void Controller::HandleInput(bool &running, Paddle &paddle) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym) {
        case SDLK_LEFT:
          SetPaddleX(paddle, Paddle::Direction::kLeft);
          break;

        case SDLK_RIGHT:
          SetPaddleX(paddle, Paddle::Direction::kRight);
          break;
      }
    }
  }
}