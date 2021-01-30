#include <iostream>
#include <string.h>

using namespace std;

class Conta
{
protected:
    char nome[30];
    int numero;
    float saldo;

public:
    Conta();
    Conta(char *, int, float);
    void depositar(int);
    virtual void extrato();
};

class ContaComum : public Conta
{
public:
    ContaComum();
    ContaComum(char *, int, float);
    void extrato();
};

class ContaPoupanca : public Conta
{
private:
    char aniversario[11];

public:
    ContaPoupanca();
    ContaPoupanca(char *, int, float, char *);
    void extrato();
};