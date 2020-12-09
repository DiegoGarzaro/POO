/**
 * POO -> Lista 5 -> Exercício 3
 * Author: Diego R. Garzaro
 * Date: 06/12/2020
 * 
 * Defina uma classe chamada fração. Esta classe deve armazenar o
 * numerador e o denominador de uma fração em duas variáveis inteiras.
 * Inclua:
 * • Dois construtores: o primeiro sem argumentos e o outro que recebe
 * numerador e denominador da fração;
 * • Uma função membro que retorna o numerador e outra que retorna o
 * denominador;
 * • As operações de adição, subtração, multiplicação e divisão;*
 * • As operações de incremento e decremento pré e pós-fixadas; *
 * • Criar um programa principal para testar a classe.
 * * Obrigatório o uso de Sobrecarga de Operadores.
 * 
 * */

#include "Fracao.h"

void input(int* num1, int* den1, int* num2, int* den2);
void tester(Fracao& fr, Fracao& fr2);

int main(){
    int *num1 = new int, *den1 = new int;
    int *num2 = new int, *den2 = new int;

    input(num1, den1, num2, den2);

    Fracao fr(*num1, *den1);
    Fracao fr2(*num2, *den2);

    tester(fr, fr2);

    delete num1, num2, den1, den2;

    return 0;
}

// Entrada dos Dados
void input(int* num1, int* den1, int* num2, int* den2){
    cout << "Digite o numerador da fracao 1: ";
    cin >> *num1;
    cout << "Digite o denominador da fracao 1: ";
    cin >> *den1;
    cout << endl << "Numerador 1 digitado: " << *num1 << endl << "Denominador 1 digitado: " << *den1 << endl << endl;

    cout << "Digite o numerador da fracao 2: ";
    cin >> *num2;
    cout << "Digite o denominador da fracao 2: ";
    cin >> *den2;
    cout << endl << "Numerador 2 digitado: " << *num2 << endl << "Denominador 2 digitado: " << *den2 << endl << endl;
}

// Executa teste da Classe Fracao
void tester(Fracao& fr, Fracao& fr2){
    Fracao result;

    cout << endl << "\tINICIO DO TESTE\n\nNumerador da Fracao1: " << fr.get_numerador() << endl << "Denominador da Fracao1: " << fr.get_denominador() << endl;

    cout << endl << "Incremento Pre-Fixado:";
    ++fr;
    cout << endl << "++Fracao1:\nNumerador da Fracao1: " << fr.get_numerador() << endl << "Denominador da Fracao1: " << fr.get_denominador() << endl;
    cout << endl << "Incremento Pos-Fixado:";
    result = fr++;
    cout << endl << "Resultado = Fracao1++:\nNumerador do Resultado: " << result.get_numerador() << endl << "Denominador do Resultado: " << result.get_denominador() << endl;
    cout << endl << "Numerador da Fracao1: " << fr.get_numerador() << endl << "Denominador da Fracao1: " << fr.get_denominador() << endl;

    cout << endl << "Decremento Pre-Fixado:";
    --fr;
    cout << endl << "--Fracao1:\nNumerador da Fracao1: " << fr.get_numerador() << endl << "Denominadro da classe: " << fr.get_denominador() << endl;
    cout << endl << "Decremento Pos-Fixado:";
    result = fr--;
    cout << endl << "Resultado = Fracao1--:\nNumerador do Resultado: " << result.get_numerador() << endl << "Denominador do Resultado: " << result.get_denominador() << endl;
    cout << endl << "Numerador da Fracao1: " << fr.get_numerador() << endl << "Denominadro da Fracao1: " << fr.get_denominador() << endl;

    cout << endl << "Soma de Fracoes:" << endl;
    result = fr + fr2;
    cout << "Operacao: Fracao1 + Fracao2";
    cout << endl << "Numerador do Resultado: " << result.get_numerador() << endl << "Denominador do Resultado: " << result.get_denominador() << endl;

    cout << endl << "Subtracao de Fracoes:" << endl;
    result = result - fr2;
    cout << "Operacao: Resultado da soma - Fracao2";
    cout << endl << "Numerador do Resultado: " << result.get_numerador() << endl << "Denominador do Resultado: " << result.get_denominador() << endl;

    cout << endl << "Multiplicacao de Fracoes:" << endl;
    result = fr * fr2;
    cout << "Operacao: Fracao1 * Fracao2";
    cout << endl << "Numerador do Resultado: " << result.get_numerador() << endl << "Denominador do Resultado: " << result.get_denominador() << endl;

    cout << endl << "Divisao de Fracoes:" << endl;
    result = result / fr2;
    cout << "Operacao: Resultado da multiplicacao / Fracao2";
    cout << endl << "Numerador do Resultado: " << result.get_numerador() << endl << "Denominador do Resultado: " << result.get_denominador() << endl;
}