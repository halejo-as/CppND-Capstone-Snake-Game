#include "player.h"

Player::Player(std::string n,  std::size_t width, std::size_t height)
  : name(n),
  snake(width,height){
    for(int i=0;i<3;i++){
      color[i] = std::rand()%256;
    }
  }

int Player::GetScore() const {return score;}
void Player::SetScore() { score++;}

int Player::GetSize() const{return snake.size;}
std::string Player::GetName() const {return name;}

