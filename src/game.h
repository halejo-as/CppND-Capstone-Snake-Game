#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory>
#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  //Game(std::size_t grid_width, std::size_t grid_height);
  Game(std::size_t grid_width, std::size_t grid_height, std::shared_ptr<Controller> c);
  void Run(Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

  std::shared_ptr<Controller> controller;

 private:
  std::vector<SDL_Point> food;
  int foodMax{3};

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;


  void PlaceFood();
  void Update();
};

#endif
