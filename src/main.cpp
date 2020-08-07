#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "game_history.h"
#include "player_data.h"
#include "game_settings.h"
int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  ProfileManager profileManager;
  Player player;
  History history;
  
  int Display, Game_mode;
  int Default_level = 1;
  int Hard_level = 2;
  string player_name;
  profileManager.WelcomeMenu();
  int Mode = profileManager.Input();
  if (Mode == profileManager.kPlay)
  {
    profileManager.PlayMenu();
    cin >> Game_mode;
    if (Game_mode == profileManager.kDefault){
      profileManager.GetPlayerName();
      player_name = profileManager.Input_string();
      player.SetName(player_name);
      player.SetLevel (Default_level);
      Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, false);
      Controller controller;
      Game game(kGridWidth, kGridHeight);
      game.Run(controller, renderer, kMsPerFrame);
      std::cout << "Game has terminated successfully!\n";
      std::cout << "Score: " << game.GetScore() << "\n";
      std::cout << "Size: " << game.GetSize() << "\n";
      player.SetScore(game.GetScore());
      history.SaveHistory(player);
    }
    else if (Game_mode == profileManager.kDifficulty){

    }
    else if (Game_mode == profileManager.kTheme) {
      profileManager.GetPlayerName();
      player_name = profileManager.Input_string();
      player.SetName(player_name);
      player.SetLevel (Default_level);
      Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, true);
      Controller controller;
      Game game(kGridWidth, kGridHeight);
      game.Run(controller, renderer, kMsPerFrame);
      std::cout << "Game has terminated successfully!\n";
      std::cout << "Score: " << game.GetScore() << "\n";
      std::cout << "Size: " << game.GetSize() << "\n";
      player.SetScore(game.GetScore());
      history.SaveHistory(player);
    }

  }
  else if (Mode == profileManager.kDisplay)
  {
    profileManager.DisplayMenu();
    auto Hall_of_Fame = history.ReadHistory();
    if (!(Hall_of_Fame.size()>0))
      cout << "No previous data is saved!" << endl;
    cin >> Display;
    if (Display == profileManager.kUnordered)
      history.DisplayHistory();
    else if (Display == profileManager.kOrdered)
      history.DisplayOrdered();
    else if (Display == profileManager.kHighest)
      history.DisplayHighScore();
    else if (Display == profileManager.kLowest)
      history.DisplayLowScore();
  }













  // Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  // Controller controller;
  // Game game(kGridWidth, kGridHeight);
  // game.Run(controller, renderer, kMsPerFrame);
  // std::cout << "Game has terminated successfully!\n";
  // std::cout << "Score: " << game.GetScore() << "\n";
  // std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}