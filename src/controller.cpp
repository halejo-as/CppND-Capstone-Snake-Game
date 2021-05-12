#include "controller.h"
#include <iostream>

Controller::Controller(int optionKeys){
  if(optionKeys == 1){
    keys.push_back(SDLK_UP);
    keys.push_back(SDLK_DOWN);
    keys.push_back(SDLK_LEFT);
    keys.push_back(SDLK_RIGHT);
  }
  else{
    keys.push_back(SDLK_w);
    keys.push_back(SDLK_s);
    keys.push_back(SDLK_a);
    keys.push_back(SDLK_d);
  }
}

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {

      SDL_Keycode input_key = e.key.keysym.sym;
      if(input_key == keys[0])
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
      else if(input_key == keys[1])
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
      else if(input_key == keys[2])
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
      else if(input_key == keys[3])
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
    }
  }
}
