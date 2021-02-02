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
    clock_t time;
    Position board_size;
public:
    Game();
    Game(int sizeX, int sizeY);
    ~Game();
    int get_dificulty();
    int get_score();
    void set_dificulty(int d);
    void run_game();
    direction key_to_move(keys last_key, keys k);
    void print_result();
    void stopwatch(int timeout);
};

class Limit{
    private:
    int size_X;
    int size_Y;
    public:
    Limit();
    ~Limit();
    int get_sizeX();
    int get_sizeY();
    void set_sizeX(int x);
    void set_sizeY(int y);
};