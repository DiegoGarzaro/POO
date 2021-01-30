#include "Classes.h"

// Class Board
Board::Board(){
    table = new char*[TAM_LIN];
    int i;
    for(i = 0; i < TAM_LIN; i++){
        table[i] = new char[TAM_COL];
    }
}

Board::Board(int lin, int col){
    table = new char*[lin];
    int i;
    for(i = 0; i < lin; i++){
        table[i] = new char[col];
    }
}

Board::~Board(){
    int i;
    for(i = 0; table[i] != '\0'; i++){
        delete [] table[i];
    }
    delete [] table;
}