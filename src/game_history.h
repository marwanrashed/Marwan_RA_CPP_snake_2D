#ifndef GAME_HISTORY_H
#define GAME_HISTORY_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime> 
#include<map>
#include "player_data.h"
using namespace std;

class History {
    public:
    // Default Constructor
    History ();
    // Methods
    void SaveHistory (Player& player);
    vector<shared_ptr<Player>> ReadHistory ();
    vector<Player> SortPlayers();
    void DisplayHistory();
    Player GetHighScore();
    void DisplayHighScore();

    private:
    
    vector <shared_ptr<Player>> _players_history;

};

#endif