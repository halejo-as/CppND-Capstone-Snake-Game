#include <iostream>
#include <memory>
#include <vector>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "player.h"
int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};



  int nPlayer;
  std::cout << "Welcome to SNAKE 2.0!\n";
  std::cout << "Enter number of players (1 or 2)\n";
  std::cin >> nPlayer;

  while(nPlayer< 1 || nPlayer > 2){
    std::cout << "Enter number of players (1 or 2)\n";
    std::cin >> nPlayer;
  }

  std::vector<std::shared_ptr<Player>> players;
  for(int i = 1; i<=nPlayer;i++){
    std::string name;
    std::cout << "Enter name for the player"<< i <<"\n";
    std::cin>>name;
    players.emplace_back(new Player(name,Controller(i),kGridWidth,kGridHeight));
  }


  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Game game(kGridWidth, kGridHeight);
  for (auto p :players)
    game.push_back(p);

  game.Run(renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  int winner = 0;
  std::string winnerName;
  for(auto p: players){
    std::cout << p->GetName() << " score: " << p->GetScore()<<"\n";
    if(winner < p->GetScore())
      winnerName = p->GetName();
  }
  if (nPlayer==2){
    std::cout <<"THE WINNER IS " << winnerName<< "\n";
  }

  return 0;
}
