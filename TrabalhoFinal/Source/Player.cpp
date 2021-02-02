#include "../Include/Player.h"

Person::Person(){
    this->name.clear();
    this->name.append("NULL");
}

Person::Person(string name){
    this->name = name;
}

Person::~Person(){
    this->name.clear();
}

void Person::set_name(string name){
    this->name = name;
}

string Person::get_name(){
    return this->name;
}

void Person::print(){
    cout << this->name;
}

Player::Player() : Person(){
    this->score = 0;
    this->rank = 0;
}

Player::Player(string name, int score) : Person(name){
    this->score = score;
    this->rank = 0;
}

Player::~Player(){
    this->score = 0;
}

int Player::get_score(){
    return this->score;
}

int Player::get_ranking(){
    return this->rank;
}

void Player::set_score(int score){
    this->score = score;
}

void Player::set_ranking(int rank){
    this->rank = rank;
}

void Player::print(){
    cout << this->score;
}