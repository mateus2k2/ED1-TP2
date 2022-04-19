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

    clock_t tic = clock();

    TADupa* upas;
    int qtd;

    scanf("%i", &qtd);

    alocarUPAS(&upas, qtd);
    lerUPAS(upas, qtd);
    ordenarUPAS(upas, qtd);
    desalocaUPAS(&upas);

    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    return 0;
}