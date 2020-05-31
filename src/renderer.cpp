#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width(screen_width),
      screen_height(screen_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Breakout Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_SOFTWARE);
  if (nullptr == sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Ball const &ball, Paddle const &paddle, Board const &board)
{

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render ball
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  SDL_Point ball_position;
  ball_position.x = ball.x;
  ball_position.y = ball.y;
  Renderer::DrawCircle(sdl_renderer, ball_position, 10);

  // Render paddle
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_Rect block;
  block.x = paddle.x;
  block.y = paddle.y;
  block.w = paddle.width;
  block.h = paddle.height;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render board
  for (int i = 0; i < board_parameters::board_width; i++)
  {
    for (int j = 0; j < board_parameters::board_height; j++)
    {
      Brick brick = board.bricks[i][j];
      // check if the brick exists
      if (!brick.state)
      {
        continue;
      }
      SDL_Rect sdl_brick;
      sdl_brick.x = board.x + i * board_parameters::board_brick_width;
      sdl_brick.y = board.y + j * board_parameters::board_brick_height;
      sdl_brick.w = board_parameters::board_brick_width;
      sdl_brick.h = board_parameters::board_brick_height;
      SDL_SetRenderDrawColor(sdl_renderer, 0xfd, 0x82, 0x1a, 0xFF);
      SDL_RenderDrawRect(sdl_renderer, &sdl_brick);
    }
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps, Ball &ball)
{
  std::string title{};
  if (!ball.isBallAlive()) 
    title = "GAME OVER";
  else
    title = "Breakout Score: " + std::to_string(score) + " FPS: " + std::to_string(fps);
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

// function to render a circle (ball)
void Renderer::DrawCircle(SDL_Renderer *renderer, SDL_Point center, int radius)
{
  for (int w = 0; w < radius * 2; w++)
  {
    for (int h = 0; h < radius * 2; h++)
    {
      int dx = radius - w; // horizontal offset
      int dy = radius - h; // vertical offset
      if ((dx * dx + dy * dy) <= (radius * radius))
      {
        SDL_RenderDrawPoint(renderer, center.x + dx, center.y + dy);
      }
    }
  }
}