#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>     // time
#include "funcoes.h"

int main(){

    srand(time(NULL));

    personagem *lista = NULL;
    morto *lista_mortos = NULL;
    int n;

    while(1) {

        printf("\n=== MENU ===\n");
        printf("1.Passar um ano\n");
        printf("2.Atribuir classe\n");
        printf("3.Cadastrar personagem\n");
        printf("0.Sair\n");

        scanf("%d", &n);

        switch(n){
            case(1):{
                lista = atualizar_personagens(lista, &lista_mortos);
                salvar_personagens_txt(lista);
                salvar_mortos_txt(lista_mortos);
                break;
            }
            case(2):{
                atribuir_classe(lista);
                break;
            }
            case(3):{
                lista = adicionar_personagem(lista);
                break;
            }
            case 0:
            printf("Encerrando...\n");
            return 0;
        }
    }
}