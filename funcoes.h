#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fichas.h"
#include "funcoes_aux.h"
int PROX_ID = 1;

//calcula o ganho de dinheiro anual
int ganho_dinheiro_anual(personagem *p) {

    int d6 = rand()%6 + 1;

    int base = d6 * mult_classe(p->classe);

    float mult = mult_adm(p->administracao);

    int ganho = (int)(base * mult);

    return ganho;
}
//calcula o ganho de seguidores anual
int ganho_seguidores_anual(personagem *p) {

    int d6 = rand()%6 + 1;

    int total = d6;

    if (p->carisma >= 40)
        total *= 2;
    else
        total += bonus_carisma(p->carisma);

    total *= mult_classe(p->classe);

    return total;
}

//salva os personagens mortos em um txt
void salvar_mortos_txt(morto *lista) {

    FILE *arq = fopen("mortos.txt", "w");
    if (!arq) return;

    fprintf(arq, "===== PERSONAGENS MORTOS =====\n\n");

    while (lista) {
        fprintf(arq, "ID: %d\n", lista->id);
        fprintf(arq, "Nome: %s\n", lista->nome);
        fprintf(arq, "Idade da morte: %d\n", lista->idade_morte);
        fprintf(arq, "Carisma: %d\n", lista->carisma);
        fprintf(arq, "Tatica Militar: %d\n", lista->tatica_militar);
        fprintf(arq, "Administracao: %d\n", lista->administracao);
        fprintf(arq, "-------------------\n");

        lista = lista->prox;
    }

    fclose(arq);
}

void aplicar_heranca(personagem *lista, personagem *morto) {
    int qtd;

    printf("\nPersonagem %s morreu!\n", morto->nome);

    do {
        printf("Quantos herdeiros? (1 a 4): ");
        scanf("%d", &qtd);
    } while (qtd < 1 || qtd > 4);

    personagem *herdeiros[4];
    int id;

    for (int i = 0; i < qtd; i++) {
        printf("Digite o ID do herdeiro %d: ", i+1);
        scanf("%d", &id);

        herdeiros[i] = buscar_por_id(lista, id);

        if (herdeiros[i] == NULL) {
            printf("ID nao encontrado! Tente novamente.\n");
            i--;
        }
    }

    int dinheiro_parte = morto->dinheiro / qtd;
    int seguidores_parte = morto->seguidores / qtd;

    for (int i = 0; i < qtd; i++) {
        herdeiros[i]->dinheiro += dinheiro_parte;
        herdeiros[i]->seguidores += seguidores_parte;
    }

    printf("Heranca dividida com sucesso!\n");
}

personagem* morte_personagem(personagem *lista, int id) {
    personagem *morto = buscar_por_id(lista, id);

    if (morto == NULL) {
        printf("Personagem nao encontrado.\n");
        return lista;
    }

    aplicar_heranca(lista, morto);
    lista = remover_personagem(lista, id);

    return lista;
}

//adiciona personagem a lista dos mortos
morto* adicionar_morto(morto *lista_mortos, personagem *p) {

    morto *novo = malloc(sizeof(morto));
    if (!novo) return lista_mortos;

    novo->id = p->id;
    strcpy(novo->nome, p->nome);
    novo->idade_morte = p->idade;
    novo->carisma = p->carisma;
    novo->tatica_militar = p->tatica_militar;
    novo->administracao = p->administracao;
    novo->prox = NULL;

    if (lista_mortos == NULL)
        return novo;

    morto *m = lista_mortos;
    while (m->prox)
        m = m->prox;

    m->prox = novo;

    return lista_mortos;
}

//salva as informações dos personagens em um .txt
void salvar_personagens_txt(personagem *lista) {

    if (lista == NULL) {
        printf("Nenhum personagem para salvar.\n");
        return;
    }

    FILE *arq = fopen("personagens.txt", "w");

    if (arq == NULL) {
        printf("Erro ao criar arquivo.\n");
        return;
    }

    personagem *p = lista;

    fprintf(arq, "===== LISTA DE PERSONAGENS =====\n\n");

    while (p != NULL) {

        fprintf(arq, "ID: %d\n", p->id);
        fprintf(arq, "Nome: %s\n", p->nome);
        fprintf(arq, "Idade: %d\n", p->idade);
        fprintf(arq, "Talento: %d\n", p->talento);

        fprintf(arq, "Poder Fisico: %d\n", p->poder_fisico);

        fprintf(arq, "Carisma: %d\n", p->carisma);
        fprintf(arq, "Tat. Militar: %d\n", p->tatica_militar);
        fprintf(arq, "Administracao: %d\n", p->administracao);

        fprintf(arq, "Dinheiro: %d\n", p->dinheiro);
        fprintf(arq, "Seguidores: %d\n", p->seguidores);

        fprintf(arq, "-----------------------------\n");

        p = p->prox;
    }

    fclose(arq);

    printf("Arquivo personagens.txt gerado com sucesso.\n");
}

//adiciona o personagem manualmente
personagem* adicionar_personagem(personagem *lista) {

    personagem *novo = malloc(sizeof(personagem));

    if (novo == NULL) {
        printf("Erro de memoria!\n");
        return lista;
    }

    novo->id = PROX_ID++;

    printf("Nome: ");
    scanf(" %49[^\n]", novo->nome);

    // valores automáticos
    novo->idade = 0;
    novo->talento = rand()%5 + 1;        // 1–5
    novo->poder_fisico = rand()%5 + 1;   // 1–5

    // iniciar demais atributos
    novo->potencial_evolucao = 0;
    novo->carisma = 0;
    novo->tatica_militar = 0;
    novo->administracao = 0;
    novo->fertilidade = 0;
    novo->dinheiro = 0;
    novo->seguidores = 0;
    strcpy(novo->classe, "Comum");
    novo->prox = NULL;

    printf("\nPersonagem criado!\n");
    printf("Talento sorteado: %d\n", novo->talento);
    printf("Poder fisico inicial: %d\n", novo->poder_fisico);

    // inserir no final da lista
    if (lista == NULL)
        return novo;

    personagem *p = lista;
    while (p->prox != NULL)
        p = p->prox;

    p->prox = novo;

    return lista;
}

//cria um personagem automaticamente
personagem* cadastrar_filho_auto(personagem *lista, char nome_pai[], int sexo) {

    personagem *novo = malloc(sizeof(personagem));
    if (!novo) return lista;

    novo->id = PROX_ID++;

    if (sexo == 1){
        printf("Digite o nome do filho de %s: ", nome_pai);
        scanf("%49s", novo->nome);
    }

    else{
        printf("Digite o nome da filha de %s: ", nome_pai);
        scanf("%49s", novo->nome);
    }

    novo->idade = 0;
    novo->talento = rand()%5 + 1;
    novo->poder_fisico = rand()%5 + 1;

    novo->potencial_evolucao = 0;
    novo->carisma = 0;
    novo->tatica_militar = 0;
    novo->administracao = 0;
    novo->fertilidade = 0;
    novo->dinheiro = 0;
    novo->seguidores = 0;
    strcpy(novo->classe, "Comum");
    novo->prox = NULL;

    printf(">> Novo personagem nasceu: %s (ID %d)\n",
           novo->nome, novo->id);

    if (lista == NULL)
        return novo;

    personagem *p = lista;
    while (p->prox != NULL)
        p = p->prox;

    p->prox = novo;

    return lista;
}

//atribui uma nova classe ao personagem
void atribuir_classe(personagem *lista) {

    int id;
    int op;

    printf("Digite o ID do personagem: ");
    scanf("%d", &id);

    personagem *p = buscar_por_id(lista, id);

    if (!p) {
        printf("Personagem não encontrado.\n");
        return;
    }

    printf("\nClasse atual: %s\n", p->classe);
    printf("1 - Rei\n");
    printf("2 - Duque\n");
    printf("3 - Comum\n");
    printf("Escolha: ");
    scanf("%d", &op);

    switch(op) {
        case 1:
            strcpy(p->classe, "Rei");
            break;
        case 2:
            strcpy(p->classe, "Duque");
            break;
        case 3:
            strcpy(p->classe, "Comum");
            break;
        default:
            printf("Opcao invalida.\n");
            return;
    }

    printf("Classe atualizada para %s\n", p->classe);
}

//atualizar o personagem quando o ano passa
personagem* atualizar_personagens(personagem *lista, morto **lista_mortos){

    personagem *p = lista;
    personagem *ant = NULL;

    while(p!=NULL){
    p->idade+=1;
    int i_i=indice_idade(p->idade);
    p->potencial_evolucao=p->talento+i_i;

    //teve filho?
    if(p->idade>16)
    {
        p->fertilidade=rand() % 20 + 1;
        p->fertilidade+=i_i;
        int sexo=rand() % 2 + 1;
        if(p->fertilidade > 22) {
        if(sexo==1)
            printf("%s teve um filho\n", p->nome);
        else
            printf("%s teve uma filha\n", p->nome);

        lista = cadastrar_filho_auto(lista, p->nome, sexo);
    }


    }

    int p_f=rand() % 40 + 20;
    p_f+=p->potencial_evolucao;
    if(i_i==1) p_f-=40;
    if(i_i==2) p_f-=30;
    if(i_i==3) p_f-=20;
    if(i_i==4) p_f-=10;
    if(p_f < 0) p->poder_fisico -= 6;
    else if(p_f <= 7) p->poder_fisico -= 5;
    else if(p_f <= 12) p->poder_fisico -= 4;
    else if(p_f <= 18) p->poder_fisico -= 3;
    else if(p_f <= 25) p->poder_fisico -= 2;
    else if(p_f <= 30) p->poder_fisico -= 1;
    else if(p_f <= 35) p->poder_fisico += 1;
    else if(p_f <= 40) p->poder_fisico += 2;
    else if(p_f <= 43) p->poder_fisico += 3;
    else if(p_f <= 47) p->poder_fisico += 4;
    else if(p_f <= 49) p->poder_fisico += 5;
    else p->poder_fisico += 6;


    //atribuindo pontos de experiencia extra
    //carisma
    int car=rand() % 20 + 1;
    car+=p->potencial_evolucao;
    if(car>18) p->carisma+=1;
    if(car>24) p->carisma+=2;
    if(car>28) p->carisma+=3;
    //tatica_militar
    int t_m=rand() % 20 + 1;
    t_m+=p->potencial_evolucao;
    if(t_m>18) p->tatica_militar+=1;
    if(t_m>24) p->tatica_militar+=2;
    if(t_m>28) p->tatica_militar+=3;
    //administracao
    int adm=rand() % 20 + 1;
    adm+=p->potencial_evolucao;
    if(adm>18) p->administracao+=1;
    if(adm>24) p->administracao+=2;
    if(adm>28) p->administracao+=3;

    // ----- GANHO DE RECURSOS -----
    int ganho_din = ganho_dinheiro_anual(p);
    p->dinheiro += ganho_din;

    int ganho_seg = ganho_seguidores_anual(p);
    p->seguidores += ganho_seg;
    //-------------------------------


    // ----- CHECAR MORTE -----
    if (p->poder_fisico <= 0) {

    printf(";-; %s morreu aos %d anos!\n", p->nome, p->idade);

    aplicar_heranca(lista, p);

    // salva antes de remover
    *lista_mortos = adicionar_morto(*lista_mortos, p);

    personagem *remover = p;

      if (ant == NULL)
        lista = p->prox;
    else
        ant->prox = p->prox;

    p = p->prox;
    free(remover);

    continue;
    }
    //--------------------------

    ant = p;
    p = p->prox;
    }
    return lista;
}