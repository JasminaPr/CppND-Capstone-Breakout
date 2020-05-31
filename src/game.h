#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "ball.h"
#include "paddle.h"
#include "board.h"
#include "display_params.h"

class Game {
 public:
  Game(DisplayParams &displayParams);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;

 private:
  Ball ball;
  Paddle paddle;
  Board board;
  
  int score{0};

  void Update();

  void CheckBallPaddleColisions();
  void CheckBrickColisions();
};

#endif