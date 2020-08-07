#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include "player_data.h"
#include "game_history.h"
#include "renderer.h"
#include "game.h"
#include "controller.h"
using namespace std;

class ProfileManager {
    public:
        void WelcomeMenu ();
        int Input ();
        string Input_string ();
        void PlayMenu ();
        void DisplayMenu ();
        void GetPlayerName ();

        enum MODE{kPlay = 1, kDisplay = 2, kUnordered = 3, kOrdered = 4, kHighest = 5, kLowest = 6, kDefault = 7 ,kDifficulty = 8, kTheme =9};
};


class GameModes : public Game {

};

#endif