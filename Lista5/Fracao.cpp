#include "Fracao.h"

// Construtores
Fracao::Fracao(int num, int den)
{
    this->num = num;
    this->den = den;
}

Fracao::Fracao(){
    this->num = 0;
    this->den = 0;
}

// Destrutor
Fracao::~Fracao()
{
    //cout << "Destrutor: A Memoria foi liberada..." << endl;
}

// Getters
int Fracao::get_numerador() const{
    return this->num;
}

int Fracao::get_denominador() const{
    return this->den;
}

// Operacoes Aritmeticas
Fracao Fracao::operator +(const Fracao& fr2){
    Fracao result;
    if(den == fr2.den){
        result.num = num + fr2.num;
        result.den = den;
    }
    else{
        result.num = ((num * fr2.den) + (fr2.num * den));
        result.den = (den * fr2.den);
    }
    return simplifica(result);
}

Fracao Fracao::operator -(const Fracao& fr2){
    Fracao result;
    if(den == fr2.den){
        result.num = num - fr2.num;
        result.den = den;
    }
    else{
        result.num = ((num * fr2.den) - (fr2.num * den));
        result.den = (den * fr2.den);
    }
    return simplifica(result);
}

Fracao Fracao::operator *(const Fracao& fr2){
    Fracao result;
    result.num = num * fr2.num;
    result.den = den * fr2.den;
    return simplifica(result);
}

Fracao Fracao::operator /(const Fracao& fr2){
    Fracao result;
    result.num = num * fr2.den;
    result.den = den * fr2.num;
    return simplifica(result);
}

// Incremento e Decremento Pre e Pos Fixadas
Fracao Fracao::operator ++(){
    num = num + (den * 1);
    return simplifica(*this);
}

Fracao Fracao::operator ++(int){
    Fracao result;
    result.num = num;
    result.den = den;
    num = num + (den * 1);
    return simplifica(result);
}

Fracao Fracao::operator --(){
    num = num - (den * 1);
    return simplifica(*this);
}

Fracao Fracao::operator --(int){
    Fracao result;
    result.num = num;
    result.den = den;
    num = num - (den * 1);
    return simplifica(result);
}

Fracao Fracao::simplifica(Fracao& fr){
    Fracao simp_fr;
    int mdc;
    if (fr.num == 0 || fr.den == 0)
    {
        mdc = 1;
    }
    else
    {
        mdc = max_div_comum(fr.num, fr.den, fr.den);
    }
    //cout << endl << "MDC: " << mdc << endl;
    simp_fr.num = fr.num / mdc;
    simp_fr.den = fr.den / mdc;
    return simp_fr;
}

int Fracao::max_div_comum(int numerador, int denominador, int numb)
{
    if ((numerador % numb != 0) || (denominador % numb != 0))
    {
        return max_div_comum(numerador, denominador, numb - 1);
    }
    else
    {
        return numb;
    }
}