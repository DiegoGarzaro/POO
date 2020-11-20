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
#define NUM_OPERAT 4
#define CHAR_A 65

// Structs
typedef struct rat_number
{
    int numerador;
    int denominador;
} rational_number;

// Functions Declaration
rational_number *recebe_entrada(void);
rational_number soma_fracao(rational_number fr1, rational_number fr2);
rational_number subtrai_fracao(rational_number fr1, rational_number fr2);
rational_number multiplica_fracao(rational_number fr1, rational_number fr2);
rational_number divide_fracao(rational_number fr1, rational_number fr2);
rational_number simplifica_fracao(rational_number fr);
int max_div_comum(int numerador, int denominador, int num);
rational_number *exec_math_operation(rational_number fr1, rational_number fr2);
void imprime_modelo(rational_number *fr, rational_number *math_op_fr);
void imprime_fracao(rational_number fr);
void imprime_float(rational_number fr);

// Global Variables
const char math_operations[] = {43, 45, 42, 47};

// Main
int main()
{
    rational_number *numb = recebe_entrada();
    rational_number *math_op_fraction = exec_math_operation(numb[0], numb[1]);
    imprime_modelo(numb, math_op_fraction);
    free(numb);
    free(math_op_fraction);

    return 0;
}

// Functions
rational_number *recebe_entrada()
{
    rational_number *num = (rational_number *)malloc(INPUT_SIZE * sizeof(rational_number *));
    int i;

    for (i = 0; i < INPUT_SIZE; i++)
    {
        printf("Numero racional %c:\n", i + CHAR_A);
        printf("Numerador: ");
        scanf("%d", &num[i].numerador);
        setbuf(stdin, NULL);
        printf("Denominador: ");
        scanf("%d", &num[i].denominador);
        setbuf(stdin, NULL);
    }
    return num;
}

rational_number soma_fracao(rational_number fr1, rational_number fr2)
{
    rational_number num;
    num.numerador = (fr1.numerador * fr2.denominador) + (fr2.numerador * fr1.denominador);
    num.denominador = (fr1.denominador * fr2.denominador);
    return num;
}

rational_number subtrai_fracao(rational_number fr1, rational_number fr2)
{
    rational_number num;
    num.numerador = (fr1.numerador * fr2.denominador) - (fr2.numerador * fr1.denominador);
    num.denominador = (fr1.denominador * fr2.denominador);
    return num;
}

rational_number multiplica_fracao(rational_number fr1, rational_number fr2)
{
    rational_number num;
    num.numerador = (fr1.numerador * fr2.numerador);
    num.denominador = (fr1.denominador * fr2.denominador);
    return num;
}

rational_number divide_fracao(rational_number fr1, rational_number fr2)
{
    rational_number num;
    num.numerador = (fr1.numerador * fr2.denominador);
    num.denominador = (fr1.denominador * fr2.numerador);
    return num;
}

rational_number simplifica_fracao(rational_number fr)
{
    rational_number simp_num;
    int mdc;
    if (fr.numerador == 0 || fr.denominador == 0)
    {
        mdc = 1;
    }
    else
    {
        mdc = max_div_comum(fr.numerador, fr.denominador, fr.denominador);
    }
    //printf("\nMDC: %d\n", mdc);
    simp_num.numerador = fr.numerador / mdc;
    simp_num.denominador = fr.denominador / mdc;
    return simp_num;
}

int max_div_comum(int numerador, int denominador, int num)
{
    if ((numerador % num != 0) || (denominador % num != 0))
    {
        return max_div_comum(numerador, denominador, num - 1);
    }
    else
    {
        return num;
    }
}

rational_number *exec_math_operation(rational_number fr1, rational_number fr2)
{
    rational_number *fractions = (rational_number *)malloc(NUM_OPERAT * sizeof(rational_number *));
    fractions[0] = soma_fracao(fr1, fr2);
    fractions[1] = subtrai_fracao(fr1, fr2);
    fractions[2] = multiplica_fracao(fr1, fr2);
    fractions[3] = divide_fracao(fr1, fr2);
    return fractions;
}

void imprime_modelo(rational_number *fr, rational_number *math_op_fr)
{
    int i;
    printf("\n");
    for (i = 0; i < INPUT_SIZE; i++)
    {
        printf("%c = ", i + CHAR_A);
        imprime_fracao(fr[i]);
        printf(" = ");
        imprime_fracao(simplifica_fracao(fr[i]));
        printf(" = ");
        imprime_float(simplifica_fracao(fr[i]));
        printf("\n");
    }
    for (i = 0; i < NUM_OPERAT; i++)
    {
        printf("A %c B = ", math_operations[i]);
        imprime_fracao(math_op_fr[i]);
        printf(" = ");
        imprime_fracao(simplifica_fracao(math_op_fr[i]));
        printf(" = ");
        imprime_float(simplifica_fracao(math_op_fr[i]));
        printf("\n");
    }
}

void imprime_fracao(rational_number fr)
{
    printf("%d/%d", fr.numerador, fr.denominador);
}

void imprime_float(rational_number fr)
{
    if (fr.denominador == 0)
    {
        printf("Nao e possivel dividir por 0");
    }
    else
    {
        printf("%.3lf", (double)fr.numerador / fr.denominador);
    }
}