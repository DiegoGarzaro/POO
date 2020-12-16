#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Empresa{
    private:
        string nome;
        string endereco;
        string cidade;
        string estado;
        string cep;
        string telefone;
    public:
        Empresa();
        Empresa(string name, string address, string city, string state, string c_cep, string phone);
        ~Empresa();
        void getdata();
        void putdata();
};

class Restaurante: public Empresa{
    private:
        string tipo_comida;
        string preco_medio;
    public:
        Restaurante();
        Restaurante(string name, string address, string city, string state, string c_cep, string phone, string kind_food, string mean_price);
        ~Restaurante();
        void getdata();
        void putdata();
};