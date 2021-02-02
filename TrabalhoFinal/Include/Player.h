#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;

public:
    Person();
    Person(string name);
    ~Person();
    string get_name();
    void set_name(string name);
    virtual void print();
};

class Player : public Person
{
protected:
    int score;
    int rank;
public:
    Player();
    Player(string name, int score);
    ~Player();
    int get_score();
    int get_ranking();
    void set_score(int score);
    void set_ranking(int rank);
    void print();
};