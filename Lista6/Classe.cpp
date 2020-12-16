#include "Classe.h"

Empresa::Empresa(){
    nome = "";
    endereco = "";
    cidade = "";
    estado = "";
    cep = "";
    telefone = "";
}

Empresa::Empresa(string name, string address, string city, string state, string c_cep, string phone)
{
    nome = name;
    endereco = address;
    cidade = city;
    estado = state;
    cep = c_cep;
    telefone = phone;
}

Empresa::~Empresa(){}

void Empresa::getdata(){
    cout << "\n\tENTRADA DOS DADOS DA EMPRESA" << endl << endl;
    cout << "Nome da Empresa: ";
    getline(cin, nome);
    cout << "Endereco: ";
    getline(cin, endereco);
    cout << "Cidade: ";
    getline(cin, cidade);
    cout << "Estado: ";
    getline(cin, estado);
    cout << "CEP: ";
    getline(cin, cep);
    cout << "Telefone: ";
    getline(cin, telefone);
    cin.clear();
}

void Empresa::putdata(){
    cout << endl << "-------DADOS EMPRESARIAIS-------" << endl;
    cout << "Nome da Empresa: " << nome << endl;
    cout << "Endereco: " << endereco << endl;
    cout << "Cidade: " << cidade << endl;
    cout << "Estado: " << estado << endl;
    cout << "CEP: " << cep << endl;
    cout << "Telefone: " << telefone << endl;
}

Restaurante::Restaurante():Empresa(){
    tipo_comida = "";
    preco_medio = "";
}

Restaurante::Restaurante(string name, string address, string city, string state, string c_cep, string phone,
                         string kind_food, string mean_price) : Empresa(name, address, city, state, c_cep, phone)
{
    tipo_comida = kind_food;
    preco_medio = mean_price;
}

Restaurante::~Restaurante(){}

void Restaurante::getdata(){
    Empresa::getdata();
    cout << "\n\tENTRADA DOS DADOS DO RESTAURANTE" << endl << endl;
    cout << "Tipo de Comida: ";
    getline(cin, tipo_comida);
    cout << "Preco medio da comida: R$ ";
    getline(cin, preco_medio);
    cin.clear();
}

void Restaurante::putdata(){
    Empresa::putdata();
    cout << endl << "-------DADOS RESTAURANTE -------" << endl;
    cout << "Tipo de comida: " << tipo_comida << endl;
    cout << "Preco medio da comida: R$ " << preco_medio << endl;
}