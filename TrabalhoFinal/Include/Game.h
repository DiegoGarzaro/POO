#include "../Include/Input.h"
#include "../Include/Elements.h"

const int velocity[4] = {50, 100, 200, 500};
const char directions_name[5][9] = {"None", "Up   ", "Down ", "Right", "Left "};
const char dificulties_name[4][10] = {"Very Hard", "Hard", "Normal", "Easy"};

class Game : private Input, Board, Snake, Feed
{
protected:
    char status;
    int score;
    int dificulty;
    int update_game;
    clock_t time;
    Position board_size;
public:
    Game(Position board_size, int dificulty);
    ~Game();
    void run_game();
    direction key_to_move(keys last_key, keys k);
    void print_result();
    void stop_watch(int timeout);
};


/**
 * TODO (26/01/2021)
 * 
 * - Add condition to avoid the new feed in the same position that the body of the snake;
 * - Create Menu (if it's possible);
 * - Polimorfismo;
 * - Sobrecarga de operadores;
 * - Funcao virtual.
 * */