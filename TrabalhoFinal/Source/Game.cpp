#include "../Include/Game.h"

Game::Game() : Board(LIMIT_X, LIMIT_X),
               Snake(LIMIT_X, LIMIT_X), Feed(LIMIT_X, LIMIT_X)
{
    this->status = 0;
    this->score = 0;
    this->dificulty = 0;
    this->board_size.x = LIMIT_X;
    this->board_size.y = LIMIT_Y;
    this->update_game = 0;
    this->time = clock() + velocity[this->dificulty];
}

Game::Game(int sizeX, int sizeY) : Board(sizeX, sizeY),
                                   Snake(sizeX, sizeY), Feed(sizeX, sizeY)
{
    this->status = 0;
    this->score = 0;
    this->dificulty = 0;
    this->board_size.x = sizeX;
    this->board_size.y = sizeY;
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

int Game::get_dificulty()
{
    return this->dificulty;
}

int Game::get_score()
{
    return this->score;
}

void Game::set_dificulty(int d)
{
    this->dificulty = d;
}

void Game::run_game()
{
    int is_position_changed = 0;
    int delay;
    Input i1;
    keys key = KEY_NONE, last_key = KEY_NONE, atual_key = KEY_NONE;
    Board b1(this->board_size.x, this->board_size.y);
    Snake s1(this->board_size.x, this->board_size.y);
    Feed f1(this->board_size.x, this->board_size.y);
    // ADD DIRECTION
    s1.new_game();
    this->status = 0;
    this->score = 0;
    vector<Position> sn = s1.get_snake();
    b1.update_board(sn, f1.get_feed_position());
    if (this->dificulty == 4)
    {
        delay = 3;
    }
    else
    {
        delay = this->dificulty;
    }
    while (this->status == 0)
    {
        if (key != KEY_NONE)
        {
            atual_key = key;
        }
        if (is_position_changed == FALSE)
        {
            key = i1.Listen();
        }
        if (atual_key != key && key != KEY_NONE)
        {
            is_position_changed = TRUE;
            if ((atual_key == KEY_RIGHT || atual_key == KEY_LEFT) && (key == KEY_LEFT || key == KEY_RIGHT))
            {
                key = atual_key;
            }
            else if ((atual_key == KEY_UP || atual_key == KEY_DOWN) && (key == KEY_DOWN || key == KEY_UP))
            {
                key = atual_key;
            }
            else
            {
                last_key = atual_key;
                atual_key = key;
            }
        }
        if (atual_key == KEY_ESC)
        {
            this->status = 1;
        }
        if (atual_key > KEY_NONE && atual_key < KEY_ESC && this->update_game == TRUE)
        {
            direction direction = this->key_to_move(last_key, atual_key);
            s1.move(direction);
            sn = s1.get_snake();
            if (sn[0].x == f1.get_feed_position().x && sn[0].y == f1.get_feed_position().y)
            {
                f1.new_feed(sn);
                ++s1;
                this->score += 10;
            }
            if (this->dificulty == 4)
            {
                if (score < 60)
                {
                    delay = 3;
                }
                else if (score >= 60 && score < 150)
                {
                    delay = 2;
                }
                else if (score >= 150 && score < 300)
                {
                    delay = 1;
                }
                else
                {
                    delay = 0;
                }
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
                     << "Velocity: " << velocity_names[delay];
                cout << endl
                     << "Score: " << this->score;
            }
            this->update_game = FALSE;
            is_position_changed = FALSE;
        }
        stopwatch(velocity[delay]);
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

void Game::stopwatch(int timeout)
{
    if (clock() >= this->time)
    {
        this->time = clock() + timeout;
        this->update_game = TRUE;
    }
}

Limit::Limit()
{
    this->size_X = TAM_LIN + TAM_BORDER;
    this->size_Y = TAM_COL + TAM_BORDER;
}

Limit::~Limit() {}

int Limit::get_sizeX()
{
    return this->size_X;
}

int Limit::get_sizeY()
{
    return this->size_Y;
}

void Limit::set_sizeX(int x)
{
    this->size_X = x;
}

void Limit::set_sizeY(int y)
{
    this->size_Y = y;
}