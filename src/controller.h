#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <memory>
#include "SDL.h"
#include "snake.h"
#include "player.h"



class Controller {
 public:
  Controller(int);
  void HandleInput(bool &running) const;
  void push_back(std::shared_ptr<Player> p);
  std::vector<std::shared_ptr<Player>> players {};

 private:
  int nControllers{1};
  std::vector<SDL_Keycode> keys;
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif
