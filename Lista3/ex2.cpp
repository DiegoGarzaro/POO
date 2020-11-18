#include <iostream>
#include <math.h>
using namespace std;

// Define
#define PI 3.14159

// Class
class Circulo
{
private:
    float raio, centro_x, centro_y, area, circunf;
    void calculo_area();
    void calculo_circunf();

public:
    void init(float r);
    void aumentar_raio(float perc);
    void definir_centro(float x, float y);
    void imprimir_raio();
    void imprimir_centro();
    void imprimir_circunf_area();
};

void Circulo::calculo_area()
{
    area = PI * pow(raio, 2);
}

void Circulo::calculo_circunf()
{
    circunf = 2 * PI * raio;
}

void Circulo::init(float r)
{
    raio = r;
    centro_x = 0;
    centro_y = 0;
}

void Circulo::aumentar_raio(float perc)
{
    raio += (raio * (perc / 100));
}

void Circulo::definir_centro(float x, float y)
{
    centro_x = x;
    centro_y = y;
}

void Circulo::imprimir_raio()
{
    cout << "\nRaio: " << raio << "\n";
}

void Circulo::imprimir_centro()
{
    cout << "\nCentro\nX: " << centro_x << "\nY: " << centro_y << "\n";
}

void Circulo::imprimir_circunf_area()
{
    calculo_area();
    calculo_circunf();
    cout << "\nCircunferencia: " << circunf << "\nArea: " << area << "\n";
}

int main()
{
    float raio, perc_aumento, axis_x, axis_y;
    Circulo circ;

    cout << "Digite o valor do raio do circulo: ";
    cin >> raio;

    circ.init(raio);
    circ.imprimir_raio();
    circ.imprimir_centro();
    circ.imprimir_circunf_area();

    cout << "\nDeseja redimensionar o tamanho do raio? Se sim, digite a porcentagem (0% - 100%): ";
    cin >> perc_aumento;

    circ.aumentar_raio(perc_aumento);
    circ.imprimir_raio();

    cout << "\nDigite a posicao do circulo no plano XY\nX: ";
    cin >> axis_x;
    cout << "Y: ";
    cin >> axis_y;

    circ.definir_centro(axis_x, axis_y);
    circ.imprimir_centro();

    return 0;
}