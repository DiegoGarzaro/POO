/**
 * Exercicio 3
 * Autor: Diego R. Garzaro
 * Data: 18/11/2020
 * 
 * Implementar um programa em C++, usando paradigma de orientação a objetos, que:
 * • Receba a data de nascimento do usuário;
 * • Faça a validação da data;
 * • Imprima: Data por extenso, signo e se o ano é bissexto.
 * Os dados da classe devem ser privados.
 * 
 * 
 * */

#include <iostream>
using namespace std;

// Definicoes
#define DIA_BIS 29

// Global Variables
const char month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char signos[12][15] = {"Aries", "Touro", "Gemeos", "Cancer", "Leao", "Virgem", "Libra", "Escorpiao", "Sagitario", "Capricornio", "Aquario", "Peixes"};
const char mes_extenso[12][15] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

enum meses_ano
{
    JAN = 0,
    FEV,
    MAR,
    ABR,
    MAI,
    JUN,
    JUL,
    AGO,
    SET,
    OUT,
    NOV,
    DEZ
};

enum signos
{
    ARIES = 0,
    TOURO,
    GEMEOS,
    CANCER,
    LEAO,
    VIRGEM,
    LIBRA,
    ESCORPIAO,
    SAGITARIO,
    CAPRICORNIO,
    AQUARIO,
    PEIXES
};

// Classes
class Birth_Info
{
    private:
        int dia_nasc, mes_nasc, ano_nasc, signo;
        int ano_bis;
        int valida_entrada(int dia, int mes, int ano);
        void trata_dados();
    public:
        int nascimento_usuario(char date[10]);
        int imprime_infos();
};

int Birth_Info::valida_entrada(int dia, int mes, int ano)
{
    // If the data is valid return true, else return false to a new input data user
    if (ano < 0 || mes < 0 || mes > 12)
    {
        return 0;
    }
    else if (dia < 1 || dia > month_day[mes])
    {
        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
        {
            if (dia == DIA_BIS && mes == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        return 1;
    }
}

void Birth_Info::trata_dados()
{
    if ((ano_nasc % 4 == 0 && ano_nasc % 100 != 0) || ano_nasc % 400 == 0)
    {
        ano_bis = 1;
    }

    if ((dia_nasc >= 21 && mes_nasc == MAR) || (dia_nasc <= 20 && mes_nasc == ABR))
    {
        signo = ARIES;
    }
    else if ((dia_nasc >= 21 && mes_nasc == ABR) || (dia_nasc <= 20 && mes_nasc == MAI))
    {
        signo = TOURO;
    }
    else if ((dia_nasc >= 21 && mes_nasc == MAI) || (dia_nasc <= 20 && mes_nasc == JUN))
    {
        signo = GEMEOS;
    }
    else if ((dia_nasc >= 21 && mes_nasc == JUN) || (dia_nasc <= 22 && mes_nasc == JUL))
    {
        signo = CANCER;
    }
    else if ((dia_nasc >= 23 && mes_nasc == JUL) || (dia_nasc <= 22 && mes_nasc == AGO))
    {
        signo = LEAO;
    }
    else if ((dia_nasc >= 23 && mes_nasc == AGO) || (dia_nasc <= 22 && mes_nasc == SET))
    {
        signo = VIRGEM;
    }
    else if ((dia_nasc >= 23 && mes_nasc == SET) || (dia_nasc <= 22 && mes_nasc == OUT))
    {
        signo = LIBRA;
    }
    else if ((dia_nasc >= 23 && mes_nasc == OUT) || (dia_nasc <= 21 && mes_nasc == NOV))
    {
        signo = ESCORPIAO;
    }
    else if ((dia_nasc >= 22 && mes_nasc == NOV) || (dia_nasc <= 21 && mes_nasc == DEZ))
    {
        signo = SAGITARIO;
    }
    else if ((dia_nasc >= 22 && mes_nasc == DEZ) || (dia_nasc <= 20 && mes_nasc == JAN))
    {
        signo = CAPRICORNIO;
    }
    else if ((dia_nasc >= 21 && mes_nasc == JAN) || (dia_nasc <= 18 && mes_nasc == FEV))
    {
        signo = AQUARIO;
    }
    else if ((dia_nasc >= 19 && mes_nasc == FEV) || (dia_nasc <= 20 && mes_nasc == MAR))
    {
        signo = PEIXES;
    }
}

int Birth_Info::nascimento_usuario(char date[10])
{
    int dia = (date[0]-48) * 10 + (date[1]-48);
    int mes = (date[3]-48) * 10 + (date[4]-48) - 1;
    int ano = (date[6]-48) * 1000 + (date[7]-48) * 100 + (date[8]-48) * 10 + (date[9]-48);
    int valid = valida_entrada(dia, mes, ano);
    if (valid == 1)
    {
        dia_nasc = dia;
        mes_nasc = mes;
        ano_nasc = ano;
        return 1;
    }
    else
    {
        return 0;
    }
}

int Birth_Info::imprime_infos()
{
    if (dia_nasc == 0)
    { // erro
        return 0;
    }
    else
    {
        trata_dados();
        cout << "\nData de Nascimento: " << dia_nasc << " de " << mes_extenso[mes_nasc] << " de " << ano_nasc << endl;
        cout << "Signo: " << signos[signo] << endl;
        if (ano_bis == 1)
        {
            cout << "E bissexto.\n";
        }
        else
        {
            cout << "Nao e bissexto.\n";
        }
    }
}

// Main
int main()
{
    Birth_Info user;
    char date[10];
    int dia, mes, ano, isValid = 0;

    while(!isValid){
        cout << "\nEntre com uma data: ";
        cin >> date;
        
        isValid = user.nascimento_usuario(date);
    }
    user.imprime_infos();

    return 0;
}