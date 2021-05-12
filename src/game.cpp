#include "game.h"
#include <iostream>
#include "SDL.h"
#include <thread>
#include <future>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      snake2(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Controller const &controller2, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    //std::thread t = std::thread(&Controller::HandleInput,&controller,std::ref(running),std::ref(snake));
    //std::thread t2 = std::thread(&Controller::HandleInput,&controller2,std::ref(running),std::ref(snake2));
    //controller.HandleInput(running, snake);
    //controller2.HandleInput(running, snake2);
    std::future<void> future = std::async(&Controller::HandleInput, &controller, std::ref(running),std::ref(snake));
    //Update();
    std::future<void> future2 = std::async(&Controller::HandleInput, &controller2, std::ref(running),std::ref(snake2));
    Update();
    renderer.Render(snake, snake2, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    /*if (frame_end - title_timestamp >= 10) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }*/

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
    //t.join();
    //t2.join();
  }
}

void Game::PlaceFood() {
  for(int nFood = food.size(); nFood<foodMax; nFood++){
    int x, y;
    SDL_Point f;
    while (true) {
      x = random_w(engine);
      y = random_h(engine);
      // Check that the location is not occupied by a snake item before placing
      // food.
      if (!snake.SnakeCell(x, y)) {
        f.x = x;
        f.y = y;
        break;
      }
    }
    food.push_back(f);
  }
}

void Game::Update() {
  if (!snake.alive || !snake2.alive) return;


  snake.Update();
  snake2.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  int new2_x = static_cast<int>(snake2.head_x);
  int new2_y = static_cast<int>(snake2.head_y);

  // Check if there's food over here
  for(auto f = food.begin(); f != food.end(); ++f){
    if (f->x == new_x && f->y == new_y) {
      food.erase(f);
      score++;
      // grow snake and increase speed.
      snake.GrowBody();
      snake.speed += 0.02;
      break;
    }
    if (f->x == new2_x && f->y == new2_y) {
      food.erase(f);
      score++;
      // grow snake and increase speed.
      snake2.GrowBody();
      snake2.speed += 0.02;
      break;
    }
  }
  PlaceFood();
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
