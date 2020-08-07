#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "game_history.h"
#include "player_data.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  std::string player_name, player_time_stamp;
  int player_level;
     History history;
     Player player;

  int kMode;
  std::cout << "Welcome to Snake Game!\n";
  std::cout << "Press 1 to Play.\n";
  std::cout << "Press 2 to open the Hall of Fame\n";
  std::cin >> kMode;
  

  if (kMode != 1 && kMode != 2 && kMode != 3) 
  {
    std::cout << "WARNING: Wrong choice, please choose on of the following options: \n";
    std::cout << "Press 1 to Play.\n";
    std::cout << "Press 2 to open the Hall of Fame\n";    
    std::cin >> kMode;
  }
  if (kMode == 2){
        auto hall_of_fame = history.ReadHistory();
        if (hall_of_fame.size() > 0)
        {
            history.DisplayHistory();
            history.DisplayHighScore();
        }
        else
        {
            std::cout << "No previous data is saved!" << std::endl;
        }
        return 0;
  }
  if(kMode == 1){
    std::cout << "Please enter your name\n";
    std::cin >> player_name;
    std::cout << "Please enter level of difficulty\n";
    std::cin >> player_level;
    player.SetName(player_name);
    player.SetLevel(player_level);
    // player.SetPlayTime();
  }
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  int player_score = game.GetScore();
  player.SetScore(player_score);
  history.SaveHistory(player);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}