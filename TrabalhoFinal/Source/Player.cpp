#include "../Include/Player.h"

Person::Person(){
    this->nome.clear();
    this->nome.append("NULL");
}

Person::Person(string nome){
    this->nome = nome;
}

Person::~Person(){
    this->nome.clear();
}

void Person::set_name(string nome){
    this->nome = nome;
}

string Person::get_nome(){
    return this->nome;
}

void Person::print(){
    cout << this->nome;
}

Player::Player() : Person(){
    this->score = 0;
    this->rank = 0;
}

Player::Player(string nome, int score) : Person(nome){
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