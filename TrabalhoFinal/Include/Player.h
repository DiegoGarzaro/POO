#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string nome;

public:
    Person();
    Person(string nome);
    ~Person();
    string get_nome();
    void set_name(string nome);
    virtual void print();
};

class Player : public Person
{
protected:
    int score;
    int rank;
public:
    Player();
    Player(string nome, int score);
    ~Player();
    int get_score();
    int get_ranking();
    void set_score(int score);
    void set_ranking(int rank);
    void print();
};