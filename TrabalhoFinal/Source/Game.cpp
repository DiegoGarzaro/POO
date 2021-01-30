#include "../Include/Game.h"

Game::Game(Position board_size, int dificulty) : Input(), Board(board_size.x, board_size.y),
                                                 Snake(board_size.x, board_size.y), Feed(board_size.x, board_size.y)
{
    this->status = 0;
    this->score = 0;
    this->dificulty = dificulty;
    this->board_size = board_size;
}

Game::~Game()
{
    this->status = 0;
    this->score = 0;
    this->dificulty = 0;
}

void Game::run_game()
{
    int special_key = 0;
    Input i1;
    keys key = KEY_NONE, last_key = KEY_NONE, aux_key = KEY_NONE;
    Board b1(this->board_size.x, this->board_size.y);
    Snake s1(this->board_size.x, this->board_size.y);
    Feed f1(this->board_size.x, this->board_size.y);
    // ADD DIRECTION
    vector<Position> sn = s1.get_snake();
    b1.update_board(sn, f1.get_feed_position());
    while (this->status == 0)
    {
        aux_key = key;
        key = i1.Listen();
        if (aux_key != key)
        {
            if(special_key == 1){
                special_key = 0;
            }
            if ((aux_key == KEY_RIGHT || aux_key == KEY_LEFT) && (key == KEY_LEFT || key == KEY_RIGHT))
            {
                key = aux_key;
            }
            else if ((aux_key == KEY_UP || aux_key == KEY_DOWN) && (key == KEY_DOWN || key == KEY_UP))
            {
                key = aux_key;
            }
            else
            {
                last_key = aux_key;
            }
        }
        if(key == KEY_V && special_key == 0){
            // Key V
            //cout << "\n\n\n LETTER V";
            this->dificulty += 1;
            if(this->dificulty > 3){
                this-> dificulty = 0;
            }
            this->status = 0;
            //key = last_key;
            special_key = 1;
        }
        if(key == KEY_F && special_key == 0){
            // Key F
            //cout << "\n\n\n LETTER F";
            f1.new_feed(sn);
            this->status = 0;
            //key = last_key;
            special_key = 1;
        }
        if(key == KEY_ESC){
            this->status = 1;
        }
        if (key > KEY_NONE && key < KEY_ESC)
        {
            direction direction = this->key_to_move(last_key, key);
            s1.move(direction);
            sn = s1.get_snake();
            if (sn[0].x == f1.get_feed_position().x && sn[0].y == f1.get_feed_position().y)
            {
                f1.new_feed(sn);
                s1.add_segment();
                this->score += 10;
            }
            if (s1.verify_colision() == TRUE)
            {
                this->status = 1;
            }
            else if (s1.get_size() >= ((this->board_size.x - 2) * (this->board_size.y - 2)))
            {
                this->status = 2;
            }
            if (this->status == 0)
            {
                b1.update_board(sn, f1.get_feed_position());
                cout << "\n\n"
                     << "Dificulty: " << this->dificulty << "\nDirection: " << key;
                cout << endl
                     << "Score: " << this->score;
            }
        }
        if(this->status != 0){
            cout << "\n\nERRO DE STATUS";
        }
        Sleep(velocity[this->dificulty]);
    }
    this->print_result();
}

direction Game::key_to_move(keys last_key, keys k)
{
    direction dir;
    if(k != KEY_UP && k == KEY_DOWN && k == KEY_RIGHT && k == KEY_LEFT){
        k = last_key;
    }
    switch (k)
    {
    case KEY_UP:
        dir = DIR_UP;
        break;
    case KEY_DOWN:
        dir = DIR_DOWN;
        break;
    case KEY_RIGHT:
        dir = DIR_RIGHT;
        break;
    case KEY_LEFT:
        dir = DIR_LEFT;
        break;
    default:
        break;
    }
    return dir;
}

void Game::print_result()
{
    switch (this->status)
    {
    case 0:
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t"
             << "GAME OVER! :(";
        cout << "\n\t\t\t"
             << "Score: " << this->score << "\n\n\n\n\n";
    case 1:
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t"
             << "GAME OVER! :(";
        cout << "\n\t\t\t"
             << "Score: " << this->score << "\n\n\n\n\n";
        break;
    case 2:
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t"
             << "YOU WIN! CONGRATS! :D";
        cout << "\n\t\t\t"
             << "Score: " << this->score << "\n\n\n\n\n";
        break;
    default:
        break;
    }
}