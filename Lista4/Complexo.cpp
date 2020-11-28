#include "Complexo.h"

ComplexCalculator::ComplexCalculator(float i1, float j1, float i2, float j2){
    c_num = (Complex_Number*) malloc (2 * sizeof(Complex_Number*));
    c_num[0].x = i1;
    c_num[0].y = j1;
    c_num[1].x = i2;
    c_num[1].y = j2;
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
    cout << "Memoria utilizada na classe para armazenar os numeros complexos foi liberada" << endl;
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
        result.x = NULL;
        result.y = NULL;
    }
    return result;
}