/**
 * POO - Lista 4 - Exercício 1
 * Autor: Diego R. Garzaro
 * Date: 05/12/2020
 * 
 * */

#include <iostream>
#include <math.h>
using namespace std;

typedef struct Complex{
    float real;
    float imag;
} Complex;

class complexo
{
private:
    Complex *c_num;
public:
    // Construtores
    complexo();
    complexo(float x, float y);
    // Destrutor
    ~complexo();
    // Prints
    float imprime_real();
    float imprime_imag();
    // Operacoes Aritmeticas
    Complex soma_complexo(Complex num);
    Complex subtrai_complexo(Complex num);
    Complex multiplica_complexo(Complex num);
    Complex divide_complexo(Complex num);
    // Operacoes Aritmeticas de Atribuicao
    complexo operator += (Complex num);
    complexo operator -= (Complex num);
    complexo operator *= (Complex num);
    complexo operator /= (Complex num);
    // Operacoes Relacionais
    bool operator > (Complex num);
    bool operator >= (Complex num);
    bool operator < (Complex num);
    bool operator <= (Complex num);
    bool operator == (Complex num);
    bool operator != (Complex num);
};

// Construtores
complexo::complexo(float x, float y)
{
    c_num = new Complex;
    c_num->real = x;
    c_num->imag = y;
}

complexo::complexo()
{
    c_num = new Complex;
    c_num->real = 0;
    c_num->imag = 0;
}

// Destrutor
complexo::~complexo()
{
    delete c_num;
    cout << endl << "Destrutor: Memoria foi desalocada..." << endl;
}

// Prints
float complexo::imprime_real(){
    return c_num->real;
}

float complexo::imprime_imag(){
    return c_num->imag;
}

// Operacoes Aritmeticas
Complex complexo::soma_complexo(Complex num){
    Complex result;
    result.real = c_num->real + num.real;
    result.imag = c_num->imag + num.imag;
    return result;
}

Complex complexo::subtrai_complexo(Complex num){
    Complex result;
    result.real = c_num->real - num.real;
    result.imag = c_num->imag - num.imag;
    return result;
}

Complex complexo::multiplica_complexo(Complex num){
    Complex result;
    result.real = (c_num->real * num.real) - (c_num->imag * num.imag);
    result.imag = (c_num->real * num.imag) + (c_num->imag * num.real);
    return result;
}

Complex complexo::divide_complexo(Complex num){
    Complex result, conjugado;
    conjugado.real = num.real;
    conjugado.imag = num.imag * (-1);
    float num_real = (c_num->real * conjugado.real) - (c_num->imag * conjugado.imag);
    float num_imag = (c_num->real * conjugado.imag) + (c_num->imag * conjugado.real);
    float den = pow(num.real,2) + pow(num.imag,2);
    if(den == 0){
        cout << "Nao e possivel fazer divisao por 0." << endl;
        result.real = 0;
        result.imag = 0;
    }
    else{
        result.real = num_real / den;
        result.imag = num_imag / den;
    }
    return result;
}

// Operacoes Aritmeticas de Atribuicao
complexo complexo::operator += (Complex num){
    *c_num = soma_complexo(num);
    return *this;
}
complexo complexo::operator -= (Complex num){
    *c_num = subtrai_complexo(num);
    return *this;
}
complexo complexo::operator *= (Complex num){
    *c_num = multiplica_complexo(num);
    return *this;
}
complexo complexo::operator /= (Complex num){
    *c_num = divide_complexo(num);
    return *this;
}

// Operacoes Relacionais
bool complexo::operator > (Complex num){
    return (c_num->real > num.real && c_num->imag > num.imag);
}
bool complexo::operator >= (Complex num){
    return (c_num->real >= num.real && c_num->imag >= num.imag);
}
bool complexo::operator < (Complex num){
    return (c_num->real < num.real && c_num->imag < num.imag);
}
bool complexo::operator <= (Complex num){
    return (c_num->real <= num.real && c_num->imag < num.imag);
}
bool complexo::operator == (Complex num){
    return (c_num->real == num.real && c_num->imag == num.imag);
}
bool complexo::operator != (Complex num){
    return !(c_num->real == num.real && c_num->imag == num.imag);
}


int main(){
    complexo num(1, -2);
    Complex c;
    c.real = -5;
    c.imag = 9;

    cout << "O numero complexo atual e: " << endl << "Real: " << num.imprime_real() << endl << "Imaginario: " << num.imprime_imag() << endl;
    num += c;
    cout << "O numero complexo atual e: " << endl << "Real: " << num.imprime_real() << endl << "Imaginario: " << num.imprime_imag() << endl;
    num -= c;
    cout << "O numero complexo atual e: " << endl << "Real: " << num.imprime_real() << endl << "Imaginario: " << num.imprime_imag() << endl;
    num *= c;
    cout << "O numero complexo atual e: " << endl << "Real: " << num.imprime_real() << endl << "Imaginario: " << num.imprime_imag() << endl;
    num /= c;
    cout << "O numero complexo atual e: " << endl << "Real: " << num.imprime_real() << endl << "Imaginario: " << num.imprime_imag() << endl;

    cout << "O numero complexo: " << endl << num.imprime_real() << " j" << num.imprime_imag() << endl << " > " << c.real << " j" << c.imag << " ?" << (num > c);
    cout << "O numero complexo: " << endl << num.imprime_real() << " j" << num.imprime_imag() << endl << " >= " << c.real << " j" << c.imag << " ?" << (num >= c);
    cout << "O numero complexo: " << endl << num.imprime_real() << " j" << num.imprime_imag() << endl << " < " << c.real << " j" << c.imag << " ?" << (num < c);
    cout << "O numero complexo: " << endl << num.imprime_real() << " j" << num.imprime_imag() << endl << " <= " << c.real << " j" << c.imag << " ?" << (num <= c);
    cout << "O numero complexo: " << endl << num.imprime_real() << " j" << num.imprime_imag() << endl << " == " << c.real << " j" << c.imag << " ?" << (num == c);
    cout << "O numero complexo: " << endl << num.imprime_real() << " j" << num.imprime_imag() << endl << " != " << c.real << " j" << c.imag << " ?" << (num != c);

    return 0;
}