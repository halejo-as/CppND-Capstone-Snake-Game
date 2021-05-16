#include "game.h"
#include <iostream>
#include "SDL.h"
#include <thread>
#include <future>
#include <chrono>

Game::Game(std::size_t grid_width, std::size_t grid_height, std::shared_ptr<Controller> c)
    : controller(c),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}
/*Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      snake2(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}*/

void Game::Run(Renderer &renderer,
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

    std::future<void> ftr = std::async(&Controller::HandleInput, *controller, std::ref(running));
    //controller->HandleInput(running);
    Update();
    renderer.Render(controller->players, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}


void Game::PlaceFood() {
  for(int nFood = food.size(); nFood<foodMax; nFood++){
    int x, y;
    SDL_Point f;
    bool place = false;
    while (!place) {
      x = random_w(engine);
      y = random_h(engine);
      place = true;
      // Check that the location is not occupied by a snake item before placing
      // food.

      for(auto p : controller->players){
        if (p->snake.SnakeCell(x, y)) {
          place = false;
        }
      }
    }
    f.x = x;
    f.y = y;
    food.push_back(f);
  }
}

void Game::Update() {
  for(auto p : controller->players){
    if (!p->snake.alive) return;
    p->snake.Update();
  }

  for(auto p: controller->players){
    int new_x = static_cast<int>(p->snake.head_x);
    int new_y = static_cast<int>(p->snake.head_y);

    // Check if there's food over here
    for(auto f = food.begin(); f != food.end(); ++f){
      if (f->x == new_x && f->y == new_y) {
        food.erase(f);
        p->SetScore();
        std::cout<<p->GetName()<< " has"<<" score " << p->GetScore()<<"\n";
        // grow snake and increase speed.
        p->snake.GrowBody();
        p->snake.speed += 0.02;
        break;
      }
    }
    PlaceFood();
  }
}

