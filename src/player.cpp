#include "player.h"

Player::Player(Controller c, std::size_t width, std::size_t height)
  :controller(c),
  snake(width,height){}

int Player::GetScore() const {return score;}
void Player::SetScore() { score++;}

int Player::GetSize() const{return snake.size;}

