#ifndef PLAYER_H
#define PLAYER_H

#include "controller.h"
#include "snake.h"


class Player{
  public:
    Player(Controller c, std::size_t width, std::size_t height);
    void SetScore();
    int GetSize() const;
    int GetScore() const;

    Controller controller;
    Snake snake;
  private:
    int score{0};
};

#endif
