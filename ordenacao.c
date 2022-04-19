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

void troca(TADupa *upas, int i, int j){
    int emergencia;
    int urgencia;
    int semUrgencia;
    char nome[100];
    
    emergencia = (upas)[i].emergencia;
    (upas)[i].emergencia = (upas)[j].emergencia;
    (upas)[j].emergencia = emergencia;

    urgencia = (upas)[i].urgencia;
    (upas)[i].urgencia = (upas)[j].urgencia;
    (upas)[j].urgencia = urgencia;

    semUrgencia = (upas)[i].semUrgencia;
    (upas)[i].semUrgencia = (upas)[j].semUrgencia;
    (upas)[j].semUrgencia = semUrgencia;

    strcpy(nome, (upas)[i].nome);
    strcpy((upas)[i].nome, (upas)[j].nome);
    strcpy((upas)[j].nome, nome);

}

int compara(TADupa *upas, int i, TADupa tmp){

//retorna 1 se i for maior que tmp
//retorna -1 se i for menor que tmp
//retorna 0 se i for igual a tmp




}


void quick_sort(TADupa *upas, int left, int right) {
    int i = left;
    int j = right;

    TADupa tmp;

    tmp.emergencia = upas[(left + right) / 2].emergencia;
    tmp.urgencia = upas[(left + right) / 2].urgencia;
    tmp.semUrgencia = upas[(left + right) / 2].semUrgencia;
    tmp.pessoal = upas[(left + right) / 2].pessoal;
    strcpy(tmp.nome, upas[(left + right) / 2].nome);
     

    while(i <= j) {
        //saber se o "i" é maior que o "tmp"
        while(compara(upas, i, tmp) == 1 && i < right) {
            i++;
        }
        //saber se o "i" é menor que o "tmp"
        while(compara(upas, i, tmp) == -1 && j > left) {
            j--;
        }
        if(i <= j) {
            troca(upas, i, j);
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
