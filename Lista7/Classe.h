#include <iostream>
#include <iomanip>
#include <string>

class Motor
{
private:
    int NumCilindro;
    int Potencia;
public:
    Motor();
    Motor(int NumCilindro, int Potencia);
    ~Motor();
    void getdata();
    void putdata();
};

class Veiculo
{
private:
    int Peso;
    int VelocMax;
    float Preco;
public:
    Veiculo();
    Veiculo(int Peso, int VelocMax, float Preco);
    ~Veiculo();
    void getdata();
    void putdata();
};

class CarroPasseio: private Motor, Veiculo
{
private:
    std::string Cor;
    std::string Modelo;
public:
    CarroPasseio();
    CarroPasseio(int NumCilindro, int Potencia, int Peso, int VelocMax, float Preco, std::string Cor, std::string Modelo);
    ~CarroPasseio();
    void getdata();
    void putdata();
};

class Caminhao: private Motor, Veiculo
{
private:
    int Toneladas;
    int AlturaMax;
    int Comprimento;
public:
    Caminhao();
    Caminhao(int NumCilindro, int Potencia, int Peso, int VelocMax, float Preco, int Toneladas, int AlturaMax, int Comprimento);
    ~Caminhao();
    void getdata();
    void putdata();
};