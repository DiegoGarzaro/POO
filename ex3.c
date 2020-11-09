/**
 * Titulo: Exercicio 3
 * Autor: Diego R. Garzaro
 * 
 * Proposta:
 * Faça uma função que receba, por referência, a altura (alt) e o sexo de uma pessoa e retorne
 * o seu peso ideal. Para homens calcular o peso ideal usando a fórmula (1) e, para mulheres a
 * fórmula (2).
 * 
 * (1) P = 72,7 ∗ alt − 58
 * (2) P = 62,1 ∗ alt − 44,7
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float peso_ideal(float alt, char sexo[]);

int main(){
    char sexo[10];
    float altura, peso;
    int i;

    for (i = 0; i < 10; i++)
    {
        sexo[i] = 0;
    }
    

    printf("Digite seu sexo (Masculino ou Feminino): ");
    fgets(sexo, 10, stdin);
    setbuf(stdin, NULL);
    
    printf("Digite sua altura (Ex: 1.73): ");
    scanf("%f", &altura);

    for (i = 0; sexo[i]!= '\0'; i++){
        if(sexo[i] == '\n'){
            sexo[i] = '\0';
        }
    }

    peso = peso_ideal(altura, sexo);

    printf("\nO peso ideal para uma pessoa %s, com a altura de: %.2f m, e de: %.2f kg\n", sexo, altura, peso);

    return 0;
}

float peso_ideal(float alt, char sexo[]){
    float peso;

    if (strncmp(strlwr(sexo), "masculino", 1) == 0){
        // Homem
        peso = (72.7 * alt) - 58;
    }
    else{
        // Mulher
        peso = (62.1 * alt) - 44.7;
    }

    return peso;
}