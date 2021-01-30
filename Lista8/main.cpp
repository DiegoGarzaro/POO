#include "Classe.h"

int main(){

    char nome[2][30] = {"Diego", "Renan"};
    int numero[2] = {12345678, 87654321};
    float saldo[2] = {125.72, 463.37};
    char aniversario[11] = "26/12/1995";

    Conta *p[2];
    ContaComum cc1(nome[0], numero[0], saldo[0]);
    ContaPoupanca cp1(nome[1], numero[1], saldo[1], aniversario);

    p[0] = &cc1;
    p[1] = &cp1;

    int i;
    for(i = 0; i < 2; i++){
        cout << endl << "Conta " << i+1 << ":";
        p[i]->extrato();
    }

    p[0]->depositar(10);
    p[1]->depositar(20);
    cout << endl << "Foi efetuado deposito de 10 reais na conta 1, e 20 reais na conta 2" << endl;

    for(i = 0; i < 2; i++){
        cout << endl << "Conta " << i+1 << ":";
        p[i]->extrato();
    }

    return 0;
}