#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "display_params.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  DisplayParams displayParams;
  displayParams.screen_width = kScreenWidth;
  displayParams.screen_height = kScreenHeight;
  displayParams.grid_width = kGridWidth;
  displayParams.grid_height = kGridHeight;

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(displayParams);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  return 0;
}