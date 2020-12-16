#include "Classe.h"

int main(){
    // Dados Empresa
    string nome = "RU Centro Politecnico";
    string endereco = "Av. Cel. Francisco H. dos Santos, 210";
    string cidade = "Curitiba";
    string estado = "Parana";
    string cep = "81531-970";
    string telefone = "(41) 3361-3248";

    // Dados Restaurante
    string tipo_comida = "Comida caseira, incluindo carnes, saladas, feijao e sobremesas, alem de matinais, em refeitorio universitario.";
    string preco_medio = "1.30";

    cout << endl << "Criando Classe com dados modelo...\nInicio do teste..." << endl;

    Restaurante r1(nome, endereco, cidade, estado, cep, telefone, tipo_comida, preco_medio);
    cout << "\nImpressao dos dados do restaurante:" << endl;
    r1.putdata();
    cout << endl << "Teste de entrada dos dados do usuario:" << endl;
    r1.getdata();
    cout << "\nImpressao dos novos dados entrados pelo usuario:\n";
    r1.putdata();
    cout << "\nFim do teste...\n";

    return 0;
}