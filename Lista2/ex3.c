/**
 * Arithmetic Operations on Rational Numbers
 * Author: Diego R. Garzaro
 * Date: 10/11/2020
 * GRR20172364 
 * 
 * Faça um programa que realize operações aritméticas em números racionais. Crie uma
 * estrutura para representar o número racional utilizando variáveis inteiras para representar o
 * numerador e denominador. Crie as seguintes funções para:
 * 
 * • Criar dois números racionais.
 * • Adição, subtração, multiplicação e divisão entre dois números racionais.
 * • Imprimir o número na forma racional, ex: “a/b”.
 * • Imprimir o número na forma de ponto flutuante, ex: “3.14”.
 * • Simplificar um número racional.
 * 
 * */

#include <stdio.h>
#include <stdlib.h>

// Defines
#define INPUT_SIZE 2

// Structs
typedef struct rat_number
{
    int numerador;
    int denominador;
} rational_number;

// Functions Declaration
rational_number *recebe_entrada(void);
rational_number soma_fracao(rational_number fr1, rational_number fr2);              // TODO
rational_number subtrai_fracao(rational_number fr1, rational_number fr2);           // TODO
rational_number multiplica_fracao(rational_number fr1, rational_number fr2);        // TODO
rational_number divide_fracao(rational_number fr1, rational_number fr2);            // TODO
rational_number simplifica_fracao(rational_number fr);
int max_div_comum(int numerador, int denominador, int num);
void imprime_fracao(rational_number fr);
void imprime_float(rational_number fr);

// Main
int main()
{
    rational_number *numb = recebe_entrada();
    int i;

    imprime_fracao(numb[0]);
    imprime_float(numb[0]);
    imprime_fracao(numb[1]);
    imprime_float(numb[1]);
    printf("\n\n");
    imprime_fracao(simplifica_fracao(numb[0]));

    return 0;
}

// Functions
rational_number *recebe_entrada(){
    rational_number *num = (rational_number*) malloc (INPUT_SIZE * sizeof(rational_number*));
    int i;
    
    for(i = 0; i < INPUT_SIZE; i++){
        printf("Digite o numerador do numero %c: ", i+65);
        scanf("%d", &num[i].numerador);
        setbuf(stdin, NULL);
        printf("Digite o denominador do numero %c: ", i+65);
        scanf("%d", &num[i].denominador);
        setbuf(stdin, NULL);
    }
    return num;
}

rational_number soma_fracao(rational_number fr1, rational_number fr2){
    // code
    rational_number num;
    num.numerador = (fr1.numerador * fr2.denominador) + (fr2.numerador * fr1.denominador);
    num.denominador = (fr1.denominador * fr2.denominador);
    return num;
}

rational_number subtrai_fracao(rational_number fr1, rational_number fr2){
    // code
    rational_number num;
    num.numerador = (fr1.numerador * fr2.denominador) - (fr2.numerador * fr1.denominador);
    num.denominador = (fr1.denominador * fr2.denominador);
    return num;
}

rational_number multiplica_fracao(rational_number fr1, rational_number fr2){
    // code
    rational_number num;
    num.numerador = (fr1.numerador * fr2.numerador);
    num.denominador = (fr1.denominador * fr2.denominador);
    return num;
}

rational_number divide_fracao(rational_number fr1, rational_number fr2){
    // code
    rational_number num;
}

rational_number simplifica_fracao(rational_number fr){
    // code
    rational_number simp_num;
    int mdc = max_div_comum(fr.numerador, fr.denominador, fr.denominador);
    printf("\nMDC: %d\n", mdc);
    simp_num.numerador = fr.numerador / mdc;
    simp_num.denominador = fr.denominador / mdc;
    return simp_num;
}

int max_div_comum(int numerador, int denominador, int num){
    if((numerador % num != 0) || (denominador % num != 0)){
        return max_div_comum(numerador, denominador, num-1);
    }
    else{
        return num;
    }
}

void imprime_fracao(rational_number fr){
    printf("%d/%d", fr.numerador, fr.denominador);
}

void imprime_float(rational_number fr){
    printf("%.2lf", ((double)fr.numerador / (double)fr.denominador));
}