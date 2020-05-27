#include "controller.h"
#include <iostream>
#include "SDL.h"
//#include "paddle.h"

void Controller::ChangeDirection(Paddle &paddle, Paddle::Direction input,
                                 Paddle::Direction opposite) const {
  if (paddle.direction != opposite) paddle.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Paddle &paddle) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_LEFT:
          ChangeDirection(paddle, Paddle::Direction::kLeft,
                          Paddle::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(paddle, Paddle::Direction::kRight,
                          Paddle::Direction::kLeft);
          break;
      }
    }
  }
}