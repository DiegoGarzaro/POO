#include "../Include/Input.h"
#include "../Include/Elements.h"

// Defines
// Board size
#define TAM_LIN 15
#define TAM_COL 30
#define TAM_BORDER 2
#define LIMIT_X 17
#define LIMIT_Y 32

const int velocity[4] = {50, 100, 200, 500};
const char directions_name[5][9] = {"None", "Up   ", "Down ", "Right", "Left "};
const char dificulties_name[5][10] = {"Very Hard", "Hard", "Normal", "Easy", "Challenge"};
const char velocity_names[4][10] = {"10x ", "5x  ", "2.5x", "1x  "};

class Game : public Input, private Board, Snake, Feed
{
protected:
    char status;
    int score;
    int dificulty;
    int update_game;
    int menu;
    clock_t time;
    Position board_size;
public:
    Game();
    ~Game();
    int page1();
    int page2();
    int call_menu();
    int get_dificulty();
    int get_score();
    void set_dificulty(int d);
    void handle_menu(int choice);
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