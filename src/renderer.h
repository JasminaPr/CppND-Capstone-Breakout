#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "ball.h"
#include "paddle.h"
#include "board.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render(Ball const &ball, Paddle const &paddle, Board const &board);
  void UpdateWindowTitle(int score, int fps, Ball &ball);
  void DrawCircle(SDL_Renderer *renderer, SDL_Point center, int radius);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif