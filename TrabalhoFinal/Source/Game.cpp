#include "../Include/Game.h"

Game::Game(Position board_size, int dificulty) : Input(), Board(board_size.x, board_size.y),
                                                 Snake(board_size.x, board_size.y), Feed(board_size.x, board_size.y)
{
    this->status = 0;
    this->score = 0;
    this->dificulty = dificulty;
    this->board_size = board_size;
    this->update_game = 0;
    this->time = clock() + velocity[this->dificulty];
}

Game::~Game()
{
    this->status = 0;
    this->score = 0;
    this->dificulty = 0;
    this->update_game = 0;
    this->time = 0;
}

void Game::run_game()
{
    int is_position_changed = 0;
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
        if(is_position_changed == FALSE){
            key = i1.Listen();
        }
        if (aux_key != key)
        {
            is_position_changed = TRUE;
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
        if (key == KEY_ESC)
        {
            this->status = 1;
        }
        if (key > KEY_NONE && key < KEY_ESC && this->update_game == TRUE)
        {
            direction direction = this->key_to_move(last_key, key);
            s1.move(direction);
            sn = s1.get_snake();
            if (sn[0].x == f1.get_feed_position().x && sn[0].y == f1.get_feed_position().y)
            {
                f1.new_feed(sn);
                ++s1;
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
                     << "Dificulty: " << dificulties_name[this->dificulty] << "\nDirection: " << directions_name[direction];
                cout << endl
                     << "Score: " << this->score;
            }
            this->update_game = FALSE;
            is_position_changed = FALSE;
        }
        stop_watch(velocity[this->dificulty]);
    }
    this->print_result();
}

direction Game::key_to_move(keys last_key, keys k)
{
    direction dir;
    if (k != KEY_UP && k == KEY_DOWN && k == KEY_RIGHT && k == KEY_LEFT)
    {
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
             << "GAME OVER!";
        cout << "\n\t\t\t"
             << "Score: " << this->score << "\n\n\n\n\n";
    case 1:
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t"
             << "GAME OVER!";
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

void Game::stop_watch(int timeout)
{
    if (clock() >= this->time)
    {
        this->time = clock() + timeout;
        this->update_game = TRUE;
    }
}