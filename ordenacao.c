#include "ordenacao.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct upa{
    char nome[100];
    int emergencia;
    int urgencia;
    int semUrgencia;
    int pessoal;
};

// Manter como especificado
void lerUPAS(TADupa *upas, int qtd) {
    for (int i = 0; i < qtd; i++){
        scanf("%s", upas[i].nome);
        scanf("%i", &upas[i].emergencia);
        scanf("%i", &upas[i].urgencia);
        scanf("%i", &upas[i].semUrgencia);
        scanf("%i", &upas[i].pessoal);
    }

}

void alocarUPAS(TADupa **upas, int qtd){
  
    *upas = (TADupa*) malloc(sizeof(TADupa) * qtd);

    if (*upas == NULL ) {
        printf ("Memoria insuficiente !\n");
        exit (1);
    }
  
}

void desalocaUPAS(TADupa **upas) {
    free (*upas);
}

void ordenarUPAS(TADupa *upas, int qtd){

    for (int i = 0; i < qtd; i++){
        printf("%s ", upas[i].nome);
        printf("%i ", upas[i].emergencia);
        printf("%i ", upas[i].urgencia);
        printf("%i ", upas[i].semUrgencia);
        printf("%i\n", upas[i].pessoal);
    }

    quick_sort(upas, 0, qtd - 1);
    printf("---------------------------------------\n");

    for (int i = 0; i < qtd; i++){
        printf("%s ", upas[i].nome);
        printf("%i ", upas[i].emergencia);
        printf("%i ", upas[i].urgencia);
        printf("%i ", upas[i].semUrgencia);
        printf("%i\n", upas[i].pessoal);
    }
}


void quick_sort(TADupa *upas, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = (upas)[(left + right) / 2].emergencia;
     
    while(i <= j) {
        while((upas)[i].emergencia < x && i < right) {
            i++;
        }
        while((upas)[j].emergencia > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = (upas)[i].emergencia;
            (upas)[i].emergencia = (upas)[j].emergencia;
            (upas)[j].emergencia = y;
            i++;
            j--;
        }
    }
     
    if(j > left){
        quick_sort(upas, left, j);
    }
    if(i < right){
        quick_sort(upas, i, right);
    }
}
