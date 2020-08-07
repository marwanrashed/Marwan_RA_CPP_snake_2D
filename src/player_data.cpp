#include "player_data.h"

// Constructor with arguments
Player::Player (string *name, int *score, int *level): _name(name), _score(score), _level(level){}
// Constructor 
Player::Player () {
    cout << "New Player is Constructed" << endl;
}
// Copy Constructor 
Player::Player (const Player &source) {
    cout << "COPYING content of instance " << &source << " to instance " << this << endl;
    _name = source._name;
    _score = source._score;
    _level = source._level;
    _play_time = source._play_time;
}
// copy assignment overloading operator 
Player& Player::operator= (const Player &source) {
    cout << "ASSIGNING content of instance " << &source << " to instance " << this << endl;
    if (this == &source)
        return *this;
    _name = source._name;
    _score = source._score;
    _level = source._level;
    _play_time = source._play_time;
    return *this;
}
// move constructor 
Player::Player (Player &&source) {
    cout << "Moving instance: " << &source << "To instance: " << this << endl;
    // move data
    _name = source._name;
    _score = source._score;
    _level = source._level;
    _play_time = source._play_time;
    // delete original data
    source._name = nullptr;
    source._score = nullptr;
    source._level = nullptr;
    source._play_time = nullptr;
}
// Move assignment operator overloading
Player& Player::operator= (Player &&source) {
        cout << "MOVING (assign) instance " << &source << " to instance " << this << endl;
        if (this == &source)
            return *this;

        // move data
        _name = source._name;
        _score = source._score;
        _level = source._level;
        _play_time = source._play_time;

        // delete original data
        source._name = nullptr;
        source._score = nullptr;
        source._level = nullptr;
        source._play_time = nullptr;

        return *this;
}

// Overloading > Operator
bool Player::operator> (Player &b){
    if (*(this->_score) > *(b._score) && *(this->_level) > *(b._level))
        return true;
    else
        return false;
      
} 

//Getters
string Player::GetName()const{return (*_name);}
int Player::GetScore()const {return (*_score);}
int Player::GetLevel()const{return (*_level);}
string Player::GetTime()const{return to_string((*_play_time));}
//Setters
void Player::SetName(string *name) {this->_name = name;}
void Player::SetScore(int *score) {this->_score =score;}
void Player::SetLevel (int *level) {this-> _level = level;}
void Player::SetPlayTime () {
    auto current_time_stamp = chrono::system_clock::now();
    (*_play_time) = chrono::system_clock::to_time_t(current_time_stamp);
} 