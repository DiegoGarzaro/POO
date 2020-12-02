#include "Complexo.h"

ComplexCalculator::ComplexCalculator(char num[2][100]){
    c_num = (Complex_Number*) malloc (2 * sizeof(Complex_Number*));
    int i, j, k;
    int isImag = 0;
    char real[2][30], imag[2][30];

    for(i = 0; i<10; i++){
        for(j = 0;j < 30;j++){
            real[0][i] = ' ';
            imag[0][i] = ' ';
            real[1][i] = ' ';
            imag[1][i] = ' ';
        }
    }

    for(i = 0; i < 2; i++){
        for(j = 0, k = 0; num[i][j] != '\0'; j++){
            if((num[i][j] == '+' || num[i][j] == '-') && j != 0){
                isImag = 1;
                k=0;
            }
            if(isImag == 0){
                real[i][k] = num[i][j];
                k++;
            }
            else{
                if(num[i][j] != 'i' && num[i][j] != 'j')
                {
                    imag[i][k] = num[i][j];
                    k++;
                }
            }
        }
        cout << endl << i+1 << "o Numero\nReal: " << atof(real[i]) << "\nImaginario: " << atof(imag[i]) << endl;
        isImag = 0;
    }
    c_num[0].x = atof(real[0]);
    c_num[0].y = atof(imag[0]);
    c_num[1].x = atof(real[1]);
    c_num[1].y = atof(imag[1]);
}

ComplexCalculator::ComplexCalculator(){
    c_num = (Complex_Number*) malloc (2 * sizeof(Complex_Number*));
    c_num[0].x = 0;
    c_num[0].y = 0;
    c_num[1].x = 0;
    c_num[1].y = 0;
}

ComplexCalculator::~ComplexCalculator(){
    free(c_num);
    cout << "Destrutor: Memoria utilizada na classe para armazenar os numeros complexos foi liberada" << endl;
}

Complex_Number ComplexCalculator::soma_complexo(){
    Complex_Number result;
    result.x = c_num[0].x + c_num[1].x;
    result.y = c_num[0].y + c_num[1].y;
    return result;
}

Complex_Number ComplexCalculator::subtrai_complexo(){
    Complex_Number result;
    result.x = c_num[0].x - c_num[1].x;
    result.y = c_num[0].y - c_num[1].y;
    return result;
}

Complex_Number ComplexCalculator::multiplica_complexo(){
    Complex_Number result;
    result.x = (c_num[0].x * c_num[1].x) - (c_num[0].y * c_num[1].y);
    result.y = (c_num[0].x * c_num[1].y) + (c_num[0].y * c_num[1].x);
    return result;
}

Complex_Number ComplexCalculator::divide_complexo(){
    Complex_Number result, conjugado;
    conjugado.x = c_num[1].x;
    conjugado.y = -c_num[1].y;
    if(((c_num[1].x * conjugado.x) - (c_num[1].y * conjugado.y)) != 0 && ((c_num[1].x * conjugado.y) + (c_num[1].y * conjugado.x)) != 0){
        result.x = ((c_num[0].x * conjugado.x) - (c_num[0].y * conjugado.y)) / ((c_num[1].x * conjugado.x) - (c_num[1].y * conjugado.y));
        result.y = ((c_num[0].x * conjugado.y) + (c_num[0].y * conjugado.x)) / ((c_num[1].x * conjugado.y) + (c_num[1].y * conjugado.x));
    }
    else{
        cout << "Nao e possivel fazer divisao por 0" << endl;
        result.x = 0;
        result.y = 0;
    }
    return result;
}

void ComplexCalculator::imprime_retangular(Complex_Number num){
    cout << "Real: " << num.x << endl << "Imaginario: " << num.y << endl;
}

void ComplexCalculator::imprime_polar(Complex_Number num){
    if(num.y == 0){
        cout << "Nao e possivel fazer divisao por 0" << endl;
        return;
    }
    double z = sqrt(pow(num.x,2) + pow(num.y,2));
    float theta = atan(num.y/num.x) * (180.0 / 3.14159);
    cout << z << " |" << theta << " graus" << endl;
}