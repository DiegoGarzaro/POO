#include "../Include/UserInterface.h"

Menu::Menu(){
    this->opcao = 0;
}

Menu::~Menu(){
    this->opcao = 0;
}

int Menu::call_menu(){
    int escolha;
    escolha = page1();
    escolha *= 10;
    escolha += page2();
}