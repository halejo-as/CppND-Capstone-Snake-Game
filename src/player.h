#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "snake.h"


class Player{
  public:
    Player(std::string n, std::size_t width, std::size_t height);
    void SetScore();
    int GetSize() const;
    int GetScore() const;
    std::string GetName() const;

    Snake snake;
    int color[4] {0,0,0,1};
  private:
    std::string name;
    int score{0};
};

#endif
