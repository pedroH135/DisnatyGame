#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

int main(){

    srand(time(NULL));

    personagem *lista = NULL;
    familia *lista_f = NULL;
    int n, a, g, ano = 0;

    // 🔥 CARREGAR JOGO SALVO
    lista = carregar_personagens(&PROX_ID, &ID_LEGADO, &ano);
    lista_f = carregar_familias();

    carregar_nomes("nomes_masculinos.txt", nomes_masculinos, &total_masculinos);
    carregar_nomes("nomes_femininos.txt", nomes_femininos, &total_femininos);

    while(1) {

        printf("\n=== MENU ===\n");
        printf("1. Passar um ano\n");
        printf("2. Atribuir\n");
        printf("3. Cadastrar personagem\n");
        printf("4. Ajustar dinheiro/seguidores\n");
        printf("5. Personagem morreu (manual)\n");
        printf("6. Batalha\n");
        printf("0. Sair\n");

        scanf("%d", &n);

        switch(n){

            case 1: {
                lista = atualizar_personagens(lista, lista_f);

                salvar_personagens_txt(lista);
                salvar_mortos_txt(lista);
                gerar_relatorios_familias(lista_f, lista);
                gerar_ranking_anual(lista);
                salvar_governantes_txt(lista);

                ano++;
                printf("Ano %d", ano);
                break;
            }

            case 2: {
                printf("1. Atribuir Mestre\n");
                printf("2. Atribuir Classe\n");
                printf("3. Atribuir Familia\n");
                printf("4. Fazer Casamento\n");
                printf("5. Tornar Player\n");
                printf("6. Territorio\n");

                scanf("%d", &a);

                switch(a){
                    case 1:
                        atribuir_mestre(lista);
                        salvar_personagens_txt(lista);
                        salvar_governantes_txt(lista);
                        break;
                    case 2:
                        atribuir_classe(lista);
                        salvar_personagens_txt(lista);
                        salvar_governantes_txt(lista);
                        break;
                    case 3:
                        lista_f = atribuir_familia(lista, lista_f);
                        salvar_personagens_txt(lista);
                        gerar_relatorios_familias(lista_f, lista);
                        salvar_governantes_txt(lista);
                        break;
                    case 4:
                        realizar_casamento(lista);
                        break;
                    case 5:
                        atribuir_player(lista);
                        break;
                    case 6:
                        territorio(lista);
                        salvar_governantes_txt(lista);
                        break;
                }
                break;
            }

            case 3: {
                lista = adicionar_personagem(lista);
                salvar_personagens_txt(lista);
                break;
            }

            case 4: {
                ajustar_recursos_manual(lista);
                salvar_personagens_txt(lista);
                salvar_governantes_txt(lista);
                break;
            }

            case 5: {
                matar_personagem_manual(lista); // 🔥 agora só marca eh_vivo = 0
                salvar_personagens_txt(lista);
                salvar_mortos_txt(lista);
                salvar_governantes_txt(lista);
                break;
            }

            case 6: {
                printf("> Selecione o tipo de batalha\n");
                printf("1. 1 v 1 Corpo a Corpo\n");
                printf("2. 1 v 1 Destreza com arma\n");
                printf("3. 1 v 1 Luta armada\n");
                printf("4. Front de guerra\n");

                scanf("%d", &g);

                switch(g){
                    case 1:
                        batalha_corpo_a_corpo(lista);
                        break;
                    case 2:
                        desafio_de_destreza(lista);
                        break;
                    case 3:
                        batalha_armada(lista);
                        break;
                    case 4:
                        front_de_guerra(lista);
                        salvar_personagens_txt(lista);
                        salvar_governantes_txt(lista);
                        break;
                }
                break;
            }

            case 0: {
                salvar_estado_jogo(lista, lista_f, ano);
                printf("Encerrando...\n");
                return 0;
            }

            default:
                printf("Opcao invalida!\n");
        }
    }
}