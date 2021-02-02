#include "../Include/Game.h"
#include "../Include/Player.h"
#include <iostream>
#include <fstream>
#include "math.h"
#include <limits>
#include <ios>

using namespace std;

class UserInterface : private Game, Player, Limit
{
private:
    Game g1;
public:
    UserInterface();
    ~UserInterface();
    int page1();
    int page2();
    int call_menu();
    void handle_menu(int choice);
    void play_game();
    Player get_player();
    void classify();
    void load_ranking(Player p, char *file_name);
    int string_to_int(string value);
};