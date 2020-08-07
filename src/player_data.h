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
    // Default Constructor
    Player();
    // Constructor with Arguments
     Player (string *, int*, int*, string*);
    // // Destructor
    ~Player();
    // Copy Semantics
        // Copy Constructor
        Player (const Player &source);
        // Copy assignment operator overloading
        Player& operator= (const Player &source);
    // Move Semantics
        // Move constructor
        Player (Player &&source);
        // Move assignment operator overloading
        Player& operator= (Player &&source);
    //Getters
    string GetName ()const;
    int GetScore ()const;
    int GetLevel ()const;
    string Player::GetTime()const;
    //Setters

    void SetName( string *name);
    void SetScore (int *score);
    void SetLevel (int *level);
    void SetPlayTime ();

    // (>) operator overloading for player scores comparison
    bool operator> (const Player&b); 
    private:
    string * _name;
    int * _score, * _level;
    string *_play_time;
};

#endif 