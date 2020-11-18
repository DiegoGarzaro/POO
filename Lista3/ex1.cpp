#include <iostream>
using namespace std;

// Class
class Retangulo
{
private:
    int altura, comprimento;
    float area, perimetro;
    float calc_area();
    float calc_perimetro();

public:
    void inicializa(int alt, int comp);
    void calcula();
    void imprime_calculo();
};

float Retangulo::calc_area()
{
    return (altura * comprimento);
}

float Retangulo::calc_perimetro()
{
    return 2 * (altura + comprimento);
}

void Retangulo::inicializa(int alt, int comp)
{
    altura = alt;
    comprimento = comp;
}

void Retangulo::calcula()
{
    area = calc_area();
    perimetro = calc_perimetro();
}

void Retangulo::imprime_calculo()
{
    cout << "Altura: " << altura << "\nComprimento: " << comprimento;
    cout << "\nArea: " << area << "\nPerimetro: " << perimetro << "\n";
}

// Main
int main()
{
    int alt, comp;
    Retangulo ret;

    cout << "\nDigite o valor da altura do retangulo: ";
    cin >> alt;
    cout << "Digite o valor do comprimento do retangulo: ";
    cin >> comp;

    ret.inicializa(alt, comp);
    ret.calcula();
    ret.imprime_calculo();

    return 0;
}