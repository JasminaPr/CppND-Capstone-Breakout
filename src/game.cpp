#include "game.h"
#include <iostream>
#include "SDL.h"
#include "paddle.h"
#include <algorithm>
#include <vector>

Game::Game(DisplayParams displayParams)
    : ball(displayParams),
      screen_width(displayParams.screen_width),
      paddle(displayParams)
{
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, paddle);
    Update();
    renderer.Render(ball, paddle, board);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update()
{
  if (!ball.alive)
    return;

  ball.Update();
  paddle.Update();
  
  Game::CheckBallPaddleColisions();
  Game::CheckBrickColisions();
  
}

void Game::CheckBallPaddleColisions()
{
  if ((ball.x >= paddle.x) && (ball.x <= paddle.x + paddle.width))
  {
    if ((ball.y >= paddle.y))
    {
      ball.ChangeDirectionY();
    }
  }
}

void Game::CheckBrickColisions()
{
  for (int i = 0; i < board_parameters::board_width; i++)
  {
    for (int j = 0; j < board_parameters::board_height; j++)
    {
      Brick brick = board.bricks[i][j];

      if (brick.state)
      {
        // brick x and y coordinates
        float brickx = board.x + i * board_parameters::board_brick_width;
        float bricky = board.y + j * board_parameters::board_brick_height;

        if ((ball.x <= brickx + board_parameters::board_brick_width) && (ball.x >= brickx) &&
            (ball.y <= bricky + board_parameters::board_brick_height) && (ball.y >= bricky))
        {
          board.bricks[i][j].state = false;
          score++;

          float distXLeft = ball.x - brickx;                                        
          float distXRight = brickx + board_parameters::board_brick_width - ball.x;
          float distYUp = ball.x - bricky;                                          
          float distYDown = bricky + board_parameters::board_brick_height - ball.y; 
          std::vector<float> distances = {distXLeft, distXRight, distYUp, distYDown};
          std::vector<float>::iterator result = std::min_element(distances.begin(), distances.end());
          int idx = std::distance(distances.begin(), result);

          if ((idx == 0) || (idx == 1))
          {
            ball.ChangeDirectionX();
          }

          if ((idx == 2) || (idx == 3))
          {
            ball.ChangeDirectionY();
          }
        }
      }
    }
  }
}

int Game::GetScore() const { return score; }

