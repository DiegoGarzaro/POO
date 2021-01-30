#include <iostream>
#include <Windows.h>

// Defines
#define TAM_LIN 100
#define TAM_COL 100

// Class Board
class Board
{
private:
    char **table;
public:
    Board();
    Board(int lin, int col);
    ~Board();
    void create_board();
    void clear_board();
    void update_board();
    void insert(char c, int x, int y);
    void pop(int x, int y);
};