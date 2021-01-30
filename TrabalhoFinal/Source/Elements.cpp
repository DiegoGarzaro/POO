#include "../Include/Elements.h"

// Class Limits
Limits::Limits()
{
    this->sizeX = TAM_LIN + TAM_BORDER;
    this->sizeY = TAM_COL + TAM_BORDER;
}

Limits::~Limits() {}

void Limits::set_sizeX(int x)
{
    this->sizeX = x;
}

void Limits::set_sizeY(int y)
{
    this->sizeY = y;
}

int Limits::get_sizeX()
{
    return this->sizeX;
}

int Limits::get_sizeY()
{
    return this->sizeY;
}

// Class Board
Board::Board(int lin, int col)
{
    this->limit.x = lin;
    this->limit.y = col;
    table = new char *[this->limit.x];
    int i;
    for (i = 0; i < this->limit.x; i++)
    {
        table[i] = new char[this->limit.y];
    }
    this->init_board();
}

Board::~Board()
{
    int i;
    for (i = 0; i < this->limit.x; i++)
    {
        delete[] table[i];
    }
    delete[] table;
}

void Board::init_board()
{
    //cout << "\033[H\033[2J"; // Clear screen
    system("cls");
    int i, j;
    for (i = 0; i < this->limit.x; i++)
    {
        for (j = 0; j < this->limit.y; j++)
        {
            if (i == 0 || i == this->limit.x - 1)
            {
                this->table[i][j] = '-';
            }
            else if (j == 0 || j == this->limit.y - 1)
            {
                this->table[i][j] = '|';
            }
            else
            {
                this->table[i][j] = ' ';
            }
        }
    }
}

void Board::update_board(vector<Position> snake, Position feed)
{
    int i, j;
    for (i = 1; i < this->limit.x - 1; i++)
    {
        for (j = 1; j < this->limit.y - 1; j++)
        {
            this->table[i][j] = ' ';
        }
    }
    this->table[feed.x][feed.y] = 'X';
    int sn;
    for (sn = 0; sn < snake.size(); sn++)
    {
        if (sn == 0)
        {
            this->table[snake[sn].x][snake[sn].y] = 'O';
        }
        else
        {
            this->table[snake[sn].x][snake[sn].y] = 'o';
        }
    }
    this->print_board();
}

void Board::set_cursor_position(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(hOut, coord);
}

void Board::print_board()
{
    this->set_cursor_position(0, 0); // set cursor to 0,0 position
    cout << endl
         << "\t\t\t\t\tSNAKE" << endl;
    int i, j;
    for (i = 0; i < this->limit.x; i++)
    {
        cout << "\t\t\t";
        for (j = 0; j < this->limit.y; j++)
        {
            cout << this->table[i][j];
        }
        cout << endl;
    }
}

// Class Snake
Snake::Snake(int x, int y)
{
    this->limit.x = x + TAM_BORDER;
    this->limit.y = y + TAM_BORDER;
    this->size = 2;
    Position s1;
    s1.x = this->limit.x / 2;
    s1.y = this->limit.y / 2;
    body.push_back(s1);
    s1.y++;
    body.push_back(s1);
    this->cont = 0;
}

Snake::~Snake()
{
    body.clear();
    this->size = 0;
    this->cont = 0;
}

void Snake::operator++()
{
    cont++;
}

void Snake::update_position(int x, int y)
{
    int i;
    if (cont != 0)
    {
        cont++;
    }
    if (cont > this->size)
    {
        this->size++;
        body.resize(this->size);
        cont = 0;
    }
    for (i = this->body.size() - 1; i > 0; i--)
    {
        body[i].x = body[i - 1].x;
        body[i].y = body[i - 1].y;
    }
    this->body[0].x = x;
    this->body[0].y = y;
}

void Snake::move(direction dir)
{
    int newX, newY;
    switch (dir)
    {
    case DIR_UP:
        newX = body[0].x - 1;
        newY = body[0].y;
        break;
    case DIR_DOWN:
        newX = body[0].x + 1;
        newY = body[0].y;
        break;
    case DIR_RIGHT:
        newX = body[0].x;
        newY = body[0].y + 1;
        break;
    case DIR_LEFT:
        newX = body[0].x;
        newY = body[0].y - 1;
        break;
    default:
        break;
    }
    this->update_position(newX, newY);
}

int Snake::verify_colision()
{
    int is_colided = 0;
    if(body[0].x >= (limit.x-TAM_BORDER-1) || body[0].y >= (limit.y-TAM_BORDER-1) || body[0].x <= 0 || body[0].y <= 0){
        is_colided = 1;
    }
    int i;
    for(i = 1; i < this->size; i++){
        if((body[0].x == body[i].x) && (body[0].y == body[i].y)){
            is_colided = 1;
        }
    }
    return is_colided;
}

vector<Position> Snake::get_snake()
{
    return body;
}

int Snake::get_size()
{
    return this->size;
}

// Class Feed
Feed::Feed(int x, int y)
{
    this->limit.x = x;
    this->limit.y = y;
    srand(time(NULL));
    feed.x = (rand() % (this->limit.x - TAM_BORDER)) + 1;
    feed.y = (rand() % (this->limit.y - TAM_BORDER)) + 1;
    this->num_feeds = 0;
}

Feed::~Feed()
{
    this->feed.x = 0;
    this->feed.y = 0;
}

void Feed::new_feed(vector<Position> snake)
{
    Position nfeed;
    do
    {
        nfeed.x = (rand() % (this->limit.x - TAM_BORDER)) + 1;
        nfeed.y = (rand() % (this->limit.y - TAM_BORDER)) + 1;
    } while (this->valida_feed(nfeed, snake) == FALSE);
    this->num_feeds++;
    this->feed = nfeed;
}

int Feed::valida_feed(Position nfeed, vector<Position> snake){
    int is_valid = 1;
    if(nfeed.x == this->feed.x && nfeed.y == this->feed.y){
        is_valid = 0;
    }
    else if(nfeed.x == 0 && nfeed.y == 0 && nfeed.x == (limit.x-2) && nfeed.y == (limit.y-2)){
        is_valid = 0;
    }
    else{
        int i;
        for(i = 0; i < snake.size(); i++){
            if((nfeed.x == snake[i].x) && (nfeed.y == snake[i].y)){
                is_valid = 0;
            }
        }
    }
    return is_valid;
}

Position Feed::get_feed_position()
{
    return this->feed;
}