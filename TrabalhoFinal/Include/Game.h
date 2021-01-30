#include "../Include/Input.h"
#include "../Include/Elements.h"

const int velocity[4] = {50, 100, 200, 500};

class Game : private Input, Board, Snake, Feed
{
protected:
    char status;
    int score;
    int dificulty;
    Position board_size;
public:
    Game(Position board_size, int dificulty);
    ~Game();
    void run_game();
    direction key_to_move(keys last_key, keys k);
    void print_result();
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