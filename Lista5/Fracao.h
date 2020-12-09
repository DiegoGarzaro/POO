#include <iostream>

using namespace std;

class Fracao
{
private:
    int num;
    int den;
public:
    // Construtores
    Fracao (int num, int den);
    Fracao();
    // Destrutor
    ~Fracao();
    // Getters
    int get_numerador() const;
    int get_denominador() const;
    // Operacoes Aritmeticas
    Fracao operator +(const Fracao& fr2);
    Fracao operator -(const Fracao& fr2);
    Fracao operator *(const Fracao& fr2);
    Fracao operator /(const Fracao& fr2);
    // Incremento e Decremento Pre e Pos Fixadas
    Fracao operator ++();
    Fracao operator ++(int);
    Fracao operator --();
    Fracao operator --(int);
    // Simplifica Fracao
    Fracao simplifica(Fracao& fr);
    int max_div_comum(int numerador, int denominador, int numb);
};