/**
 * Jogo da Velha
 * Autor: Diego R. Garzaro
 * Data: 08/11/2020
 * GRR20172364
 * 
 * Atividade para materia de Programação Orientada a Objeto
 * 
 * a) Permitir movimentos alternados de dois jogadores A e B.
 * b) Identificar se um movimento pode ser realizado ou nao.
 * c) Identificar o termino de um jogo, indicando as tres possiveis situacoes: A ganhou, B ganhou, Empate.
 * d) Construir um "tabuleiro" que permita a represetacao das jogadas. 
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Definicoes
#define ROW 3
#define COL 3

// Enums
enum status_game {JOGANDO, A_GANHOU, B_GANHOU, EMPATE} status;
enum turn_game {A_JOGANDO = 1, B_JOGANDO} turn;

// Funcoes
char **cria_tabuleiro();
void imprime_tabuleiro(char **table);
void instrucoes(void);
bool verifica_jogada(char **table, int row, char col);
void insere_jogada(char **table, int row, char col);
int verifica_resultado(char **table);

int main(){
    char **table = cria_tabuleiro();
    status = JOGANDO;
    turn = A_JOGANDO;
    bool isValid = false;
    int row;
    char col;
    
    instrucoes();
    getchar();
    setbuf(stdin, NULL);
    while(status == JOGANDO){
        // Recebe entrada
        do{
            row = 0;
            col = 0;
            printf("Posicao jogador %d: ", turn);
            scanf("%d%c", &row, &col);
            setbuf(stdin, NULL);
            // Verifica entrada
            isValid = verifica_jogada(table, row, col);
            if (isValid == false){
                imprime_tabuleiro(table);
                printf("Entrada invalida!! Por favor, digite uma posicao disponivel no tabuleiro\n");
            }
        } while(isValid == false);
        isValid = false;
        // Insere jogada
        insere_jogada(table, row, col);
        // Imprime tabuleiro
        imprime_tabuleiro(table);
        // Verifica vencedor
        status = verifica_resultado(table);
    }
    free(table);
    return 0;
}

void insere_jogada(char **table, int row, char col){
    switch (toupper(col))
    {
    case 'A':
        col = 0;
        break;
    case 'B':
        col = 1;
        break;
    case 'C':
        col = 2;
        break;
    default:
        break;
    }

    if(turn == A_JOGANDO){
        table[row-1][col] = 'X';
        turn = B_JOGANDO;
    }
    else{
        table[row-1][col] = 'O';
        turn = A_JOGANDO;
    }

}

bool verifica_jogada(char **table, int row, char col){
    bool valid = true;

    if(row >= 1 && row <= 3);
    else{
        valid = false;
    }
    if(toupper(col) == 'A' || toupper(col) == 'B' || toupper(col) == 'C');
    else{
        valid = false;
    }

    switch (toupper(col))
    {
    case 'A':
        col = 0;
        break;
    case 'B':
        col = 1;
        break;
    case 'C':
        col = 2;
        break;
    default:
        break;
    }

    if(valid == true){
        if(table[row-1][col] != ' '){
            valid = false;
        }
    }

    return valid;
}


int verifica_resultado(char **table){
    // Code
    int result = JOGANDO;
    char vencedor = 0;
    int count_blank = 0;
    int i, j;

    // Verificacao horizontal
    for(i = 0; i < ROW; i++){
        if(table[i][0] == table[i][1] && table[i][0] == table[i][2] && table[i][0] != ' '){
            vencedor = table[i][0];
            i = ROW;
        }
    }

    // Verificacao vertical
    for(j = 0; j < COL; j++){
        if(table[0][j] == table[1][j] && table[0][j] == table[2][j] && table[0][j] != ' '){
            vencedor = table[0][j];
            j = COL;
        }
    }

    // Verificacao diagonal principal
    if(table[0][0] == table[1][1] && table[0][0] == table[2][2] && table[0][0] != ' '){
        vencedor = table[0][0];
    }

    // Verificacao diagonal secundaria
    if(table[2][0] == table[1][1] && table[2][0] == table[0][2] && table[2][0] != ' '){
        vencedor = table[2][0];
    }

    // Verifica se todas as posicoes estao ocupadas
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            if (table[i][j] == ' '){
                count_blank++;
            }
        }
    }

    if(count_blank == 0){
        if (vencedor == 0)
            vencedor = EMPATE;
    }

    if(vencedor != 0){
        if(vencedor == 'X'){
            result = A_GANHOU;
            printf("\nJogador %d foi o vencedor do jogo!\n", result);
        }
        else if(vencedor == 'O'){
            result = B_GANHOU;
            printf("\nJogador %d foi o vencedor do jogo!\n", result);
        }
        else{
            result = EMPATE;
            printf("\nEMPATE!! Nao houve vencedores no jogo!\n");
        }
        
    }

    return result;
}

char **cria_tabuleiro(){
    char **table = (char**) malloc (ROW * sizeof(char*));
    int i, j;

    for(i = 0; i < ROW; i++){
        table[i] = (char *) malloc (COL * sizeof(char *));
    }

    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            table[i][j] = ' ';
        }
    }

    return table;
}

void imprime_tabuleiro(char **table){
    int i, j;
    printf("\nJOGO DA VELHA\n");
    
    for(i = 0; i < ROW; i++){
        printf("\n|---|---|---|\n|");
        for(j = 0; j < COL; j++){
            printf(" %c |", table[i][j]);
        }
    }
    printf("\n|---|---|---|\n\n");
}

void instrucoes(void){
    printf("\n      JOGO DA VELHA\n\n\tINTRUCOES\n\n");
    printf("Para selecionar a posicao de cada peca, digite a linha (1, 2, 3) e a coluna (A, B, C) sem espacos, por exemplo:\n");
    printf("Posicao jogador 1: 1B\n");
    printf("Posicao jogador 2: 3C\n");
    printf("|---|---|---|\n");
    printf("|   | X |   |\n");
    printf("|---|---|---|\n");
    printf("|   |   |   |\n");
    printf("|---|---|---|\n");
    printf("|   |   | O |\n");
    printf("|---|---|---|\n");
    printf("\nPressione Enter para continuar e iniciar o jogo!\n");
}