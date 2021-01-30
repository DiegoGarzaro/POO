#include <iostream>
#include <Windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;

// Defines
#define TAM_LIN 15
#define TAM_COL 30
#define TAM_BORDER 2

// Enums
enum direction
{
    DIR_UP = 1,
    DIR_DOWN,
    DIR_RIGHT,
    DIR_LEFT
};

// Structs
typedef struct Struct_Position
{
    int x;
    int y;
} Position;

// Class Limits
class Limits
{
private:
    int sizeX;
    int sizeY;
public:
    Limits();
    ~Limits();
    void set_sizeX(int x);
    void set_sizeY(int y);
    int get_sizeX();
    int get_sizeY();
};

// Class Board -> Tabuleiro
class Board
{
private:
    char **table; // Board
    Position limit;
public:
    Board(int lin, int col);
    ~Board();
    void init_board();
    void set_cursor_position(int x, int y);
    void update_board(vector<Position> snake, Position feed);
    void print_board();
};

// Class Snake -> Cobra
class Snake
{
private:
    vector<Position> body;
    int size;
    int cont;
    Position limit;
public:
    Snake(int x, int y);
    ~Snake();
    void add_segment();                 // Increase the size of the body
    void update_position(int x, int y); // Update the segments position
    void move(direction dir);           // Release a movement
    int verify_colision();              // Verify if the snake colided with itself or with the wall
    vector<Position> get_snake();       // Get the snake vector
    int get_size();                     // Get the size of the snake
};

// Class Feed -> Comida
class Feed
{
private:
    Position feed;
    Position limit;
public:
    Feed(int x, int y);
    ~Feed();
    void new_feed(vector<Position> snake);
    int valida_feed(Position nfeed, vector<Position> snake);
    Position get_feed_position();
};