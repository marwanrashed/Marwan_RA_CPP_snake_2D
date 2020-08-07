#ifndef GAME_HISTORY_H
#define GAME_HISTORY_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
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
    vector<shared_ptr<Player>> ReadHistory();
    vector<shared_ptr<Player>> SortPlayers(vector<shared_ptr<Player>>& v);
    void DisplayHistory();
    void DisplayOrdered ();
    Player GetHighScore();
    Player GetLowestScore();
    void DisplayHighScore();
    void DisplayLowScore();
    
    private:
    
    vector <shared_ptr<Player>> _players_history;

};

#endif