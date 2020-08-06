#ifndef PLAYER_DATA_H
#define PLAYER_DATA_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime> 
using namespace std;

class Player {
    public:
    Player();

    //Getters
    string GetName ()const;
    int GetScore ()const;
    int GetLevel ()const;
    //Setters

    void SetName( string name);
    void SetScore (int score);
    void SetLevel (int level);
    void SetPlayTime ();

    // (>) operator overloading for player scores comparison
    bool operator> (Player&b); 
    private:
    string _name;
    int _score, _level;
    chrono::system_clock _play_time;
};

#endif 