/*
Titulo: Exercicio 1
Autor: Diego R. Garzaro

Proposta:
Faça uma função que receba três números inteiros como parâmetros, representando horas,
minutos e segundos e os converta em segundo. Exemplo: 2 h, 40 min e 10 s correspondem a
9610 segundos.
*/

#include <stdio.h>
#include <stdlib.h>

int convert2seg(int hora, int min, int seg);

int main(){
    int hora, min, seg, total_seg;

    printf("Entre com 3 numeros inteiros separados por espaco, representando a hora, minuto e segundo, respectivamente\n");
    scanf("%d %d %d", &hora, &min, &seg);

    total_seg = convert2seg(hora, min, seg);

    printf("\n%d h, %d min e %d s correspondem a %d segundos.\n", hora, min, seg, total_seg);

    return 0;
}

int convert2seg(int hora, int min, int seg){
    int t_seg = 0;
    t_seg = seg + min*60 + hora*3600;
    return t_seg;
}