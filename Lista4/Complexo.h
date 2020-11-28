#include <iostream>
using namespace std;

typedef struct Complex_Number{
    float x;
    float y;
} Complex_Number;

class ComplexCalculator{
    private:
        Complex_Number *c_num;
        ComplexCalculator();
    public:
        ComplexCalculator(float i1, float j1, float i2, float j2);
        ~ComplexCalculator();
        Complex_Number soma_complexo();
        Complex_Number subtrai_complexo();
        Complex_Number multiplica_complexo();
        Complex_Number divide_complexo();
        void imprime_retangular(Complex_Number num);
        void imprime_polar(Complex_Number num);
};