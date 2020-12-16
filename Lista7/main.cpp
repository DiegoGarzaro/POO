#include "Classe.h"

void teste_Motor(int NumCilindro, int Potencia);
void testeVeiculo(int Peso, int VelocMax, float Preco);
void testeCarroPasseio(int NumCilindro, int Potencia, int Peso, int VelocMax, float Preco, std::string Cor, std::string Modelo);
void testeCaminhao(int NumCilindro, int Potencia, int Peso, int VelocMax, float Preco, int Toneladas, int AlturaMax, int Comprimento);

int main(){
    // Dados para teste - Motor
    int NumCilindro = 200;
    int Potencia = 400;

    // Dados para teste - Veiculo
    int Peso = 960;
    int VelocMax = 350;
    float Preco = 1360000;

    // Dados para teste - Carro Passeio
    std::string Cor = "Preto";
    std::string Modelo = "Mercedes-Benz";

    // Dados para teste - Caminhao
    int Toneladas = 2;
    int AlturaMax = 12;
    int Comprimento = 42;

    // Testes
    std::cout << std::endl << "****************** INICIO DO TESTE ******************" << std::endl << std::endl;
    
    teste_Motor(NumCilindro, Potencia);
    testeVeiculo(Peso, VelocMax, Preco);
    testeCarroPasseio(NumCilindro, Potencia, Peso, VelocMax, Preco, Cor, Modelo);
    testeCaminhao(NumCilindro, Potencia, Peso, VelocMax, Preco, Toneladas, AlturaMax, Comprimento);

    std::cout << std::endl << "****************** FINAL DO TESTE ******************" << std::endl << std::endl;

    return 0;
}

void teste_Motor(int NumCilindro, int Potencia){
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << std::endl << "\tTESTE MOTOR" << std::endl;
    Motor m1(NumCilindro, Potencia);
    m1.putdata();
    m1.getdata();
    m1.putdata();
    std::cout << "-----------------------------------------------------" << std::endl;
}

void testeVeiculo(int Peso, int VelocMax, float Preco){
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << std::endl << "\tTESTE VEICULO" << std::endl;
    Veiculo v1(Peso, VelocMax, Preco);
    v1.putdata();
    v1.getdata();
    v1.putdata();
    std::cout << "-----------------------------------------------------" << std::endl;    
}

void testeCarroPasseio(int NumCilindro, int Potencia, int Peso, int VelocMax, float Preco, std::string Cor, std::string Modelo){
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << std::endl << "\tTESTE CARRO PASSEIO" << std::endl;
    CarroPasseio cp1(NumCilindro, Potencia, Peso, VelocMax, Preco, Cor, Modelo);
    cp1.putdata();
    cp1.getdata();
    cp1.putdata();
    std::cout << "-----------------------------------------------------" << std::endl;
}

void testeCaminhao(int NumCilindro, int Potencia, int Peso, int VelocMax, float Preco, int Toneladas, int AlturaMax, int Comprimento){
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << std::endl << "\tTESTE CAMINHAO" << std::endl;
    Caminhao c1(NumCilindro, Potencia, Peso, VelocMax, Preco, Toneladas, AlturaMax, Comprimento);
    c1.putdata();
    c1.getdata();
    c1.putdata();
    std::cout << "-----------------------------------------------------" << std::endl;
}