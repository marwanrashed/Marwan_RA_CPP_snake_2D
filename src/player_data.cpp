#include "player_data.h"

// Constructor with arguments
Player::Player (string name, int score, int level): _name(name), _score(score), _level(level){

}
// Constructor 
Player::Player () {
    // cout << "New Player is Constructed" << endl;
}
// Destructor
Player::~Player() {
    //cout << "Player is destroyed now" << endl;
}
// Copy Constructor 
Player::Player (const Player &source) {
    // cout << "COPYING content of instance " << &source << " to instance " << this << endl;
    this->_name = source._name;
    this->_score = source._score;
    this->_level = source._level;
}
// copy assignment overloading operator 
Player& Player::operator= (const Player &source) {
    // cout << "ASSIGNING content of instance " << &source << " to instance " << this << endl;
    if (this == &source)
        return *this;
    this->_name = source._name;
    this->_score = source._score;
    this->_level = source._level;
    return *this;
}
// move constructor 
Player::Player (Player &&source) {
    // cout << "Moving instance: " << &source << "To instance: " << this << endl;
    // move data
    this->_name = source._name;
    this->_score = source._score;
    this->_level = source._level;
    // delete original data
    source._name = "Dummy";
    source._score = 0;
    source._level = 0;
}
// Move assignment operator overloading
Player& Player::operator= (Player &&source) {
        // cout << "MOVING (assign) instance " << &source << " to instance " << this << endl;
        if (this == &source)
            return *this;

        // move data
        this->_name = source._name;
        this->_score = source._score;
        this->_level = source._level;

        // delete original data
        source._name = "Dummy";
        source._score = 0;
        source._level = 0;

        return *this;
}

// Overloading > Operator
bool Player::operator < (const Player &b){
        return this->GetScore() > b.GetScore();
      
} 

//Getters
string Player::GetName()const{return _name;}
int Player::GetScore()const {return _score;}
int Player::GetLevel()const{return _level;}

//Setters
void Player::SetName(string name) {this->_name = name;}
void Player::SetScore(int score) {this->_score =score;}
void Player::SetLevel (int level) {this-> _level = level;}
