#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "SDL.h"
#include "snake.h"
#include <vector>


class Controller {
 public:
  Controller(int optionKeys);
  void HandleInput(bool &running, Snake &snake) const;

 private:
  std::vector<SDL_Keycode> keys;
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif
