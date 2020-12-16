/**
 * POO -> Lista 7
 * Author: Diego R. Garzaro
 * GRR20172364
 * 
 * 1) Crie a classe Motor que contém NumCilindro (int) e Potencia (int). Inclua um
 * construtor sem argumentos que inicialize os dados com zeros e um construtor que inicialize
 * os dados com os valores recebidos como argumento. Acrescente uma função para entrada
 * de dados, getdata(), e uma função que imprima os dados, putdata().
 * 
 * 2) Escreva a classe Veiculo contendo Peso em quilos (int), VelocMax em km/h (int) e
 * Preco em R$ (float). Inclua um construtor sem argumentos que inicialize os dados com
 * zeros e um construtor que inicialize os dados com os valores recebidos como argumento.
 * Acrescente uma função para a entrada de dados, getdata(), e uma função que imprima os
 * dados, putdata().
 * 
 * 3) Crie a classe CarroPasseio usando as classes Motor e Veiculo como base. Inclua Cor
 * (string) e Modelo (string). Inclua um construtor que inicialize os dados com zeros e um
 * construtor que inicialize os dados com os valores recebidos como argumento. Acrescente
 * uma função para a entrada de dados, getdata(), e uma função que imprima os dados,
 * putdata().
 * 
 * 4) Crie a classe Caminhao derivada das classes Motor e Veiculo. Inclua Toneladas (carga
 * máxima), AlturaMax (int) e Comprimento (int). Inclua um construtor que inicialize os
 * dados com zeros e um construtor que inicialize os dados com os valores recebidos como
 * argumento. Acrescente uma função para a entrada de dados, getdata(), e uma função que
 * imprima os dados, putdata().
 * 
 * 5) Crie um programa para testar as classes dos exercícios 1, 2, 3 e 4.
 * 
 * */

#include "Classe.h"

// Classe Motor
Motor::Motor()
{
    this->NumCilindro = 0;
    this->Potencia = 0;
}

Motor::Motor(int NumCilindro, int Potencia)
{
    this->NumCilindro = NumCilindro;
    this->Potencia = Potencia;
}

Motor::~Motor() {}

void Motor::getdata()
{
    std::cout << std::endl
              << "\tENTRADA DADOS MOTOR:" << std::endl;
    std::cout << "Digite o numero de cilindros: ";
    std::cin >> this->NumCilindro;
    std::cout << "Digite a potencia: ";
    std::cin >> this->Potencia;
}

void Motor::putdata()
{
    std::cout << std::endl
              << "-------DADOS DO MOTOR  -------" << std::endl;
    std::cout << "Numero de cilindros: " << this->NumCilindro << std::endl;
    std::cout << "Potencia: " << this->Potencia << std::endl;
}

// Classe Veiculo
Veiculo::Veiculo()
{
    this->Peso = 0;
    this->VelocMax = 0;
    this->Preco = 0;
}

Veiculo::Veiculo(int Peso, int VelocMax, float Preco)
{
    this->Peso = Peso;
    this->VelocMax = VelocMax;
    this->Preco = Preco;
}

Veiculo::~Veiculo() {}

void Veiculo::getdata()
{
    std::cout << std::endl
              << "\tENTRADA DADOS VEICULO:" << std::endl;
    std::cout << "Digite o peso [kg]: ";
    std::cin >> this->Peso;
    std::cout << "Digite a velocidade maxima [km/h]: ";
    std::cin >> this->VelocMax;
    std::cout << "Digite o preco [R$]: ";
    std::cin >> this->Preco;
    std::cin.ignore(256, '\n');
}

void Veiculo::putdata()
{
    std::cout << std::endl
              << "-------DADOS DO VEICULO-------" << std::endl;
    std::cout << "Peso: " << this->Peso << " kg" << std::endl;
    std::cout << "Velocidade maxima: " << this->VelocMax << " km/h" << std::endl;
    std::cout << "Preco: R$ " << this->Preco << std::endl;
}

// Classe Carro Passeio
CarroPasseio::CarroPasseio() : Motor(), Veiculo()
{
    this->Cor = "";
    this->Modelo = "";
}

CarroPasseio::CarroPasseio(int NumCilindro, int Potencia, int Peso, int VelocMax, float Preco, std::string Cor, std::string Modelo)
    : Motor(NumCilindro, Potencia),
      Veiculo(Peso, VelocMax, Preco)
{
    this->Cor = Cor;
    this->Modelo = Modelo;
}

CarroPasseio::~CarroPasseio() {}

void CarroPasseio::getdata()
{
    Motor::getdata();
    Veiculo::getdata();
    std::cout << std::endl
              << "\tENTRADA DADOS CARRO PASSEIO:" << std::endl;
    std::cout << "Digite a cor: ";
    std::getline(std::cin, this->Cor);
    std::cout << "Digite o modelo: ";
    std::getline(std::cin, this->Modelo);
}

void CarroPasseio::putdata()
{
    Motor::putdata();
    Veiculo::putdata();
    std::cout << std::endl
              << "----DADOS CARRO PASSEIO----" << std::endl;
    std::cout << "Cor: " << this->Cor << std::endl;
    std::cout << "Modelo: " << this->Modelo << std::endl;
}

// Classe Caminhao
Caminhao::Caminhao() : Motor(), Veiculo()
{
    this->Toneladas = 0;
    this->AlturaMax = 0;
    this->Comprimento = 0;
}

Caminhao::Caminhao(int NumCilindro, int Potencia, int Peso, int VelocMax, float Preco, int Toneladas, int AlturaMax, int Comprimento)
    : Motor(NumCilindro, Potencia),
      Veiculo(Peso, VelocMax, Preco)
{
    this->Toneladas = Toneladas;
    this->AlturaMax = AlturaMax;
    this->Comprimento = Comprimento;
}

Caminhao::~Caminhao() {}

void Caminhao::getdata()
{
    Motor::getdata();
    Veiculo::getdata();
    std::cout << std::endl
              << "\tENTRADA DADOS CAMINHAO:" << std::endl;
    std::cout << "Digite quantas toneladas de carga maxima: ";
    std::cin >> this->Toneladas;
    std::cout << "Digite a altura maxima [m]: ";
    std::cin >> this->AlturaMax;
    std::cout << "Digite o comprimento [m]: ";
    std::cin >> this->Comprimento;
}

void Caminhao::putdata()
{
    Motor::putdata();
    Veiculo::putdata();
    std::cout << std::endl
              << "-------DADOS CAMINHAO------" << std::endl;
    std::cout << "Toneladas (carga maxima): " << this->Toneladas << std::endl;
    std::cout << "Altura maxima: " << this->AlturaMax << " m" << std::endl;
    std::cout << "Comprimento: " << this->Comprimento << " m" << std::endl;
}