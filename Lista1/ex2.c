/* 
Titulo: Exercicio 2
Autor: Diego R. Garzaro

Proposta:
Faça uma função que receba, por parâmetro, um valor inteiro e positivo N e retorne o valor
de S, onde a primeira parcela da soma tem N = 1, a segunda parcela tem N = 2, ..., até N ser igual
ao valor digitado.

S = 2/4 + 5/5 + 10/6 + 17/7 + 28/8 + ... + (n^2+1)/(n+3)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *somatorio(int n);

int main(){
    int *sum, n;

    printf("Digite um numero inteiro positivo N: ");
    scanf("%d", &n);

    sum = somatorio(n);

    printf("\nO valor de S e: \n\n S = %d / %d\n", *sum, *(sum+1));

    return 0;
}

int *somatorio(int n){
    int *p;
    int vec[n][2], sum[2] = {0, 0};
    int  i;
    
    for (i = 1; i <= n; i++){
        vec[i-1][0] = (pow(i, 2) + 1);
        //printf("num: %d, %d\n", i, vec[i-1][0]);
        vec[i-1][1] = (i + 3);
        //printf("den: %d, %d\n", i, vec[i-1][1]);
        printf("S[%d] = %d / %d\n", i, vec[i-1][0], vec[i-1][1]);
        if(sum[0] == 0){
            sum[0] = vec[0][0];
            sum[1] = vec[0][1];
        }
        else{
            int num_aux = (sum[1] * vec[i-1][0]) + (vec[i-1][1] * sum[0]);
            int den_aux = (sum[1] * vec[i-1][1]);
            sum[0] = num_aux;
            sum[1] = den_aux;
        }        
    }
    //printf("\nSomatoria = %d / %d\n", sum[0], sum[1]);

    p = &sum[0];

    return p;
}