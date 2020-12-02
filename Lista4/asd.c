#include <stdlib.h>
#include <stdio.h>

int main(){

    char palavra[5] = "ALOHA";
    int i = 0;
    char letra;


    for(i = 0; i < 5;){
        scanf("%c", &letra);
        setbuf(stdin, NULL);        // Limpa buffer de entrada do teclado
        if(letra == palavra[i]){
            printf("%da letra %c\n", i+1, letra);
            i++;
        }
        else{
            printf("%da letra %c - letra errada\n", i+1, letra);
        }
    }
    printf("\nALOHA!!\n");

    return 0;
}