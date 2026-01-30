#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fichas.h"

//Tipos de classe
int mult_classe(char classe[]) {
    if (strcmp(classe, "Rei") == 0) return 3;
    if (strcmp(classe, "Duque") == 0) return 2;
    return 1;
}
//Bonus administracao
float mult_adm(int adm) {
    if (adm >= 40) return 4.0;
    if (adm >= 30) return 3.0;
    if (adm >= 20) return 2.0;
    if (adm >= 10) return 1.5;
    return 1.0;
}
//bonus carisma
int bonus_carisma(int car) {
    if (car >= 30) return 3;
    if (car >= 20) return 2;
    if (car >= 10) return 1;
    return 0;
}
//calcular o indice_idade
int indice_idade(int idade){
    if(idade >=65) return 1;
    if(idade >=50 && idade<65) return 2;
    if(idade >=35 && idade<50) return 3;
    if((idade >=20 && idade<35) || idade<10) return 4;
    if(idade >=10 && idade<20) return 5;

    return 0;
}
//busca o personagem por seu id
personagem* buscar_por_id(personagem *lista, int id) {
    while (lista != NULL) {
        if (lista->id == id)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}
//
personagem* remover_personagem(personagem *lista, int id) {
    personagem *atual = lista;
    personagem *anterior = NULL;

    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return lista;

    if (anterior == NULL)
        lista = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    return lista;
}
