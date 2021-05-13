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

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  std::shared_ptr<Player> p1(new Player(Controller(2),kGridWidth,kGridHeight));
  std::shared_ptr<Player> p2(new Player(Controller(2),kGridWidth,kGridHeight));
  Game game(kGridWidth, kGridHeight);
  game.push_back(p1);
  game.push_back(p2);
  game.Run(renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << p1->GetScore() << "\n";
  std::cout << "Size: " << p1->GetSize() << "\n";
  return 0;
}
