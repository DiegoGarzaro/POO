#include "Classe.h"

// Classe Conta
Conta::Conta()
{
    strcpy(nome, "None");
    numero = 0;
    saldo = 0;
}

Conta::Conta(char *nome, int numero, float saldo)
{
    strcpy(this->nome, nome);
    this->numero = numero;
    this->saldo = saldo;
}

void Conta::depositar(int valor)
{
    this->saldo += valor;
}

void Conta::extrato()
{
    cout << endl
         << "Nome: " << this->nome << endl
         << "Numero: " << this->numero << endl
         << "Saldo: " << this->saldo << endl;
}

ContaComum::ContaComum() : Conta() {}

ContaComum::ContaComum(char *nome, int numero, float saldo) : Conta(nome, numero, saldo) {}

void ContaComum::extrato()
{
    cout << endl
         << "Nome: " << this->nome << endl
         << "Numero: " << this->numero << endl
         << "Saldo: " << this->saldo << endl;
}

ContaPoupanca::ContaPoupanca() : Conta()
{
    strcpy(this->aniversario, "DD/MM/AAAA");
}

ContaPoupanca::ContaPoupanca(char *nome, int numero, float saldo, char *aniversario) : Conta(nome, numero, saldo)
{
    strcpy(this->aniversario, aniversario);
}

void ContaPoupanca::extrato()
{
    cout << endl
         << "Nome: " << this->nome << endl
         << "Numero: " << this->numero << endl
         << "Saldo: " << this->saldo << endl
         << "Aniversario: " << this->aniversario << endl;
}