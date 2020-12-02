/**
 * POO - Lista 4 - Exercício 2
 * Autor: Diego R. Garzaro
 * Data: 26/11/2020
 * 
 * 2) Implemente um programa que realize operações aritméticas em números complexos, mas
 * dessa vez utilizando uma classe para representar o número complexo. Crie os seguintes
 * métodos para:
 * 
 * • Construtor que deverá inicializar o valor do número complexo.
 * • Adição, subtração, multiplicação e divisão de dois números complexos.
 * • Imprimir o número na forma retangular.
 * • Imprimir o número na forma polar.
 * • Crie um destrutor.
 * • Criar um programa principal para testar a classe.
 * • Os dados da classe devem ser privados.
 * • Para entrada e saída de dados utilize o comando cin e cout.
 * • Criar os arquivos Complexo.h, Complexo.cpp e main.cpp. 
 * */

#include "Complexo.h"

int main(){
    char num[2][100];
    int i;

    for(i = 0; i<100; i++){
        num[0][i] = ' ';
        num[1][i] = ' ';
    }


    cout << "\n\t INSTRUCOES\n\nExemplo de entrada de numero complexo:\nDigite o 1o numero complexo: -1+j2" << endl << endl;
    cout << "Digite o 2o numero complexo: 3-j4" << endl << endl;
    cout << "Aperte Enter para iniciar a calculadora de numeros complexos..." << endl;
    cin.getline(num[0], 1);

    for(i = 0; i < 2; i++){
        cout << "Digite o " << i+1 << "o numero complexo: ";
        cin.getline(num[i], 100);
    }
    cout << "Os numeros complexos digitados foram: " << num[0] << " e " << num[1] << endl;

    ComplexCalculator calculo1(num);

    calculo1.imprime_retangular(calculo1.soma_complexo());
    calculo1.imprime_polar(calculo1.soma_complexo());


/*
    for(i = 0; i < 2; i++){
        for(j = 0, k = 0; num[i][j] != '\0'; j++){
            if((num[i][j] == '+' || num[i][j] == '-') && j != 0){
                isImag = 1;
                k=0;
            }
            if(isImag == 0){
                real[i][k] = num[i][j];
                k++;
            }
            else{
                if(num[i][j] != 'i' && num[i][j] != 'j')
                {
                    imag[i][k] = num[i][j];
                    k++;
                }
            }
        }
        cout << endl << i+1 << "o Numero\nReal: " << atof(real[i]) << "\nImaginario: " << atof(imag[i]) << endl;
        isImag = 0;
    }
    */

    return 0;
}