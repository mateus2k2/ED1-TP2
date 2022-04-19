#include "ordenacao.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
gcc -c ordenacao.c -Wall
gcc -c principal.c -Wall
gcc ordenacao.o principal.o -o exe

gcc *.c -o exe -Wall

./exe < Casos/1.in
*/

int main(){

    TADupa* upas;
    int qtd;

    scanf("%i", &qtd);

    alocarUPAS(&upas, qtd);
    lerUPAS(upas, qtd);
    ordenarUPAS(upas, qtd);
    desalocaUPAS(&upas);

    return 0;
}