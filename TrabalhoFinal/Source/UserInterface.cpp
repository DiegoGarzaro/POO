#include "../Include/UserInterface.h"

UserInterface::UserInterface()
{
    Game g1(Limit().get_sizeX(), Limit().get_sizeY());
}

UserInterface::~UserInterface(){}

int UserInterface::call_menu()
{
    int escolha;
    escolha = page1();
    cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    escolha *= 10;
    if (escolha > 0)
        escolha += page2();
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    return escolha;
}

int UserInterface::page1()
{
    system("cls");
    int item = 1;
    Input i1;
    keys k = KEY_NONE;
    keys last_key = KEY_NONE;
    cout << "\n\n\t\tSNAKE"
         << "\n\n\n\t\t> PLAY <\n\n\t\tEXIT\n\n\n";
    while (k != KEY_ENTER)
    {
        last_key = k;
        k = i1.Listen();
        if (k != KEY_NONE)
        {
            system("cls");
            switch (k)
            {
            case KEY_UP:
                if (item > 0)
                {
                    cout << "\n\n\t\tSNAKE"
                         << "\n\n\n\t\t> PLAY <\n\n\t\tEXIT\n\n\n";
                    item = 1;
                }
                else
                {
                    cout << "\n\n\t\tSNAKE"
                         << "\n\n\n\t\t> PLAY <\n\n\t\tEXIT\n\n";
                    item = 1;
                }
                break;
            case KEY_DOWN:
                if (item <= 0)
                {
                    cout << "\n\n\t\tSNAKE"
                         << "\n\n\n\t\tPLAY\n\n\t\t> EXIT <\n\n\n";
                    item = 0;
                }
                else
                {
                    cout << "\n\n\t\tSNAKE"
                         << "\n\n\n\t\tPLAY\n\n\t\t> EXIT <\n\n\n";
                    item = 0;
                }
                break;
            }
            //cout << "\nTecla: " << k << " | Item: " << item << endl;
        }
    }
    return item;
}

int UserInterface::page2()
{
    system("cls");
    int item = 0;
    Input i1;
    keys k = KEY_NONE;
    keys last_key = KEY_NONE;
    cout << "\n\n\t\tSNAKE"
         << "\n\n\n\t\t> CHALLENGE <\n\n\t\tEASY\n\n\t\tNORMAL\n\n\t\tHARD\n\n\t\tVERY HARD\n\n\n\n";
    cout << "\tRanking is only available in Challenge Mode!\n\n\n";
    while (k != KEY_ENTER)
    {
        last_key = k;
        k = i1.Listen();
        if (last_key != k)
        {
            if (k == KEY_DOWN && item < 4)
            {
                item++;
            }
            if (k == KEY_UP && item > 0)
            {
                item--;
            }
            system("cls");
            switch (item)
            {
            case 0:
                cout << "\n\n\t\tSNAKE"
                     << "\n\n\n\t\t> CHALLENGE <\n\n\t\tEASY\n\n\t\tNORMAL\n\n\t\tHARD\n\n\t\tVERY HARD\n\n\n\n";
                cout << "\tRanking is only available in Challenge Mode!\n\n\n";
                break;
            case 1:
                cout << "\n\n\t\tSNAKE"
                     << "\n\n\n\t\tCHALLENGE\n\n\t\t> EASY <\n\n\t\tNORMAL\n\n\t\tHARD\n\n\t\tVERY HARD\n\n\n\n";
                cout << "\tRanking is only available in Challenge Mode!\n\n\n";
                break;
            case 2:
                cout << "\n\n\t\tSNAKE"
                     << "\n\n\n\t\tCHALLENGE\n\n\t\tEASY\n\n\t\t> NORMAL <\n\n\t\tHARD\n\n\t\tVERY HARD\n\n\n\n";
                cout << "\tRanking is only available in Challenge Mode!\n\n\n";
                break;
            case 3:
                cout << "\n\n\t\tSNAKE"
                     << "\n\n\n\t\tCHALLENGE\n\n\t\tEASY\n\n\t\tNORMAL\n\n\t\t> HARD <\n\n\t\tVERY HARD\n\n\n\n";
                cout << "\tRanking is only available in Challenge Mode!\n\n\n";
                break;
            case 4:
                cout << "\n\n\t\tSNAKE"
                     << "\n\n\n\t\tCHALLENGE\n\n\t\tEASY\n\n\t\tNORMAL\n\n\t\tHARD\n\n\t\t> VERY HARD <\n\n\n\n";
                cout << "\tRanking is only available in Challenge Mode!\n\n\n";
                break;
            }
            //cout << "\nTecla: " << k << " | Item: " << item << endl;
        }
    }
    return item;
}

void UserInterface::handle_menu(int choice)
{
    switch (choice)
    {
    case 0:
        exit(1);
        break;
    case 10:
        this->g1.set_dificulty(4);
        break;
    case 11:
        this->g1.set_dificulty(3);
        break;
    case 12:
        this->g1.set_dificulty(2);
        break;
    case 13:
        this->g1.set_dificulty(1);
        break;
    case 14:
        this->g1.set_dificulty(0);
        break;
    }
}

void UserInterface::play_game()
{
    g1.run_game();
}

Player UserInterface::get_player()
{
    system("cls");
    string name;
    cout << "\n\n\t\t Type your nickname [3 letters only]: ";
    getline(cin, name);
    cout << name;
    Player p(name, this->g1.get_score());
    return p;
}

void UserInterface::classify()
{
    int is_qualified;
    if (this->g1.get_dificulty() == 4)
    {
        Player p1 = get_player();
        system("cls");
        cout << "\n\n\t\t";
        cout << "Player: " << p1.get_name() << endl
             << "\t\tScore: ";
        p1.print();
        Sleep(2000);
        char file_name[15] = "ranking.txt";
        this->load_ranking(p1, file_name);
    }
    else
    {
        return;
    }
}

void UserInterface::load_ranking(Player p, char *file_name)
{
    int exist_file = 0;
    Player p_list[11];
    p_list[10] = p;
    ifstream file;
    file.open(file_name);
    if (file)
    {
        // load
        char c, category = 0; // 3 categorias: Person name, Player Score, Player Ranking
        string temp_name;
        string temp_score;
        int temp_rank;
        int i = 0, cont = 0;
        while (!file.eof())
        {
            file >> c;
            if (c != ',')
            {
                switch (category)
                {
                case 0:
                    temp_name.push_back(c);
                    break;
                case 1:
                    temp_score.push_back(c);
                    break;
                case 2:
                    temp_rank = c - 48;
                    category++;
                }
            }
            else
            {
                category++;
                i = 0;
            }
            if (category > 2)
            {
                p_list[cont].set_name(temp_name);
                p_list[cont].set_score(string_to_int(temp_score));
                p_list[cont].set_ranking(temp_rank);

                temp_name.clear();
                temp_score.clear();

                cont++;
                category = -1;
            }
        }
        exist_file = 1;
    }
    file.close();
    if (exist_file == 0)
    {
        //cout << "\n\n\t\tARQUIVO NAO EXISTE\n\n";
        ofstream outfile;
        outfile.open(file_name);
        outfile << p.get_name();
        outfile << ',';
        outfile << p.get_score();
        outfile << ',';
        outfile << p.get_ranking();
        //}
        outfile.close();
        cout << "\n\n";
        cout << p.get_ranking() + 1 << ". " << p.get_name() << " .......... " << p.get_score() << endl;
    }
    else
    {
        Player aux;
        int i, j;
        for (i = 0; i < 11; i++)
        {
            for (j = i; j < 11; j++)
            {
                if (p_list[j].get_score() > p_list[i].get_score())
                {
                    aux = p_list[i];
                    p_list[i] = p_list[j];
                    p_list[j] = aux;
                }
            }
        }
    }

    int i;
    system("cls");
    cout << "\n\n\t\tTOP 10 - PLAYERS RANKING\n\n";
    for (i = 0; i < 10; i++)
    {
        p_list[i].set_ranking(i);
        if (p_list[i].get_name() != "NULL")
            cout << "\t" << p_list[i].get_ranking() + 1 << ". " << p_list[i].get_name()[0] << p_list[i].get_name()[1] << p_list[i].get_name()[2] << " ............................... " << p_list[i].get_score() << endl;
    }

    // writing file
    ofstream outfile;
    outfile.open(file_name);
    for (i = 0; i < 10; i++)
    {
        if (i != 0)
        {
            outfile << ',';
        }
        outfile << p_list[i].get_name();
        outfile << ',';
        outfile << p_list[i].get_score();
        outfile << ',';
        outfile << p_list[i].get_ranking();
    }
    outfile.close();

    cout << "\n\n\t";
    system("PAUSE");
}

int UserInterface::string_to_int(string value)
{
    int i;
    int result = 0;
    for (i = 0; i < value.size(); i++)
    {
        result += (value[i] - 48) * pow(10, ((value.size() - 1) - i));
    }
    return result;
}