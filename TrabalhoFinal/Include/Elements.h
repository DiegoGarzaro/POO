#include <iostream>
#include <Windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;

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

// Class Board -> Tabuleiro
class Board
{
private:
    char **table; // Board
    Position limit;
public:
    Board(int lin, int col);            // Constructor
    ~Board();                           // Destructor
    void init_board();                  // Clear the attributes 
    void set_cursor_position(int x, int y); // Set cursor position of the console
    void update_board(vector<Position> snake, Position feed);   // Update the snake and feed inside the board
    void print_board();                 // Print the board on the console
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
    Snake(int x, int y);                // Constructor
    ~Snake();                           // Destructor
    void new_game();                    // Clear the attributes to start a new game
    void operator++();                  // Increase the size of the body
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
    int num_feeds;
public:
    Feed(int x, int y);                 // Constructor
    ~Feed();                            // Destructor
    void new_feed(vector<Position> snake);  // Generate a new position the feed
    int valida_feed(Position nfeed, vector<Position> snake);    // Verify if the new position generated is valid
    Position get_feed_position();       // Return the position of the new feed
};