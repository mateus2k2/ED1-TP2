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
};

// Manter como especificado
void lerUPAS(TADupa *upas, int qtd) {
 for (int i = 0; i < qtd; i++){
    scanf("%s", upas[i].nome);
    scanf("%i", &upas[i].emergencia);
    scanf("%i", &upas[i].urgencia);
    scanf("%i", &upas[i].semUrgencia);

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
    printf("%i\n", upas[i].semUrgencia);

}

}
