#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fichas.h"
#define MAX_NOMES 2000
#define TAM_NOME 50

char nomes_masculinos[MAX_NOMES][TAM_NOME];
char nomes_femininos[MAX_NOMES][TAM_NOME];

int total_masculinos = 0;
int total_femininos = 0;


int sortear_intelecto_inicial() {
    int r = rand() % 100 + 1;
    if (r == 1) return 4;   // Gênio (1/100)
    if (r <= 3) return 3;  // Inteligente (2/100 aprox)
    if (r <= 6) return 2;  // Esperto
    if (r <= 16) return 1; // Hábil
    if (r >= 99) return -2; // Burro
    if (r >= 97) return -1; // Deslechado
    return 0;
}

int sortear_beleza_inicial() {
    int r = rand() % 300 + 1; // Range maior para acomodar todas as chances
    if (r <= 3) return 4;   // Lendária (1/100)
    if (r <= 9) return 3;   // Muito Bonito (1/50)
    if (r <= 19) return 2;  // Bonito (1/30)
    if (r <= 39) return 1;  // Atraente (1/15)
    if (r >= 295) return -2; // Muito Feio (1/60)
    if (r >= 283) return -1; // Pouco Atraente (1/25)
    return 0;
}

int calcular_heranca_intelecto(int nivel_pai) {
    if (nivel_pai == 0) return sortear_intelecto_inicial();

    int d10 = rand() % 10 + 1;
    
    if (d10 <= 3) return nivel_pai - 1; // Cai um nível
    if (d10 <= 7) return nivel_pai;     // Mantém
    return nivel_pai + 1;               // Sobe um nível (10 no d10)
}

int calcular_heranca_beleza(int nivel_pai) {
    if (nivel_pai == 0) return sortear_intelecto_inicial();

    int d10 = rand() % 10 + 1;
    
    if (d10 <= 3) return nivel_pai - 1; // Cai um nível
    if (d10 <= 7) return nivel_pai;     // Mantém
    return nivel_pai + 1;               // Sobe um nível (10 no d10)
}

const char* txt_intelecto(int nivel) {
    if (nivel >= 4) return " > Genio";
    if (nivel == 3) return " > Inteligente";
    if (nivel == 2) return " > Esperto";
    if (nivel == 1) return " > Habil";
    if (nivel == -1) return " > Deslechado";
    if (nivel <= -2) return " > Burro";
    return "";
}

const char* txt_beleza(int nivel) {
    switch (nivel) {
        case 4:  return " > Beleza Lendaria";
        case 3:  return " > Muito Bonito";
        case 2:  return " > Bonito";
        case 1:  return " > Atraente";
        case -1: return " > Pouco Atraente";
        case -2: return " > Muito Feio";
        default: return "";
    }
}
//Gera nomes automaticamentes
void gerar_nome_auto(int sexo, char *destino) {
    if (sexo == 1)
        strcpy(destino, nomes_masculinos[rand() % total_masculinos]);
    else
        strcpy(destino, nomes_femininos[rand() % total_femininos]);
}

//Conversor para algorismos romanos
void numero_para_romano(int num, char *romano) {

    char *romanos[] = {
        "", " I", " II", " III", " IV",
        " V", " VI", " VII", " VIII", " IX",
        " X", " XI", " XII", " XIII", " XIV",
        " XV", " XVI", " XVII", " XVIII", " XIX",
        " XX"
    };

    if (num >= 1 && num <= 20)
        strcpy(romano, romanos[num]);
    else
        sprintf(romano, "%d", num);
}

//Funcao para contar a repeticao do nome na familia
int contar_nome_familia(personagem *lista, int familia_id, char *nome) {
    int count = 0;

    personagem *p = lista;
    while (p) {
        if (p->familia_id == familia_id &&
            strcmp(p->nome, nome) == 0) {
            count++;
        }
        p = p->prox;
    }

    return count;
}

// Função de comparação para o qsort (Ordem Decrescente)
int comp_ranking(const void *a, const void *b) {
    return ((ItemRanking*)b)->valor - ((ItemRanking*)a)->valor;
}
//Tipos de classe
int mult_classe(char classe[]) {
    if (strcmp(classe, "Rei") == 0) return 3;
    if (strcmp(classe, "Duque") == 0) return 2;
    return 1;
}
//Bonus administracao
float mult_adm(int adm) {
    if (adm >= 80) return 5.0;
    if (adm >= 60) return 4.0;
    if (adm >= 45) return 3.0;
    if (adm >= 30) return 2.0;
    if (adm >= 15) return 1.5;
    return 1.0;
}
//bonus carisma
int bonus_carisma(int car) {
    if (car >= 80) return 5;
    if (car >= 60) return 4;
    if (car >= 45) return 3;
    if (car >= 30) return 2;
    if (car >= 15) return 1;
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

const char* buscar_sobrenome_por_id(personagem *lista, int id) {
    if (id <= 0) return ""; // Proteção contra IDs inválidos
    
    personagem *atual = lista;
    while (atual != NULL) {
        if (atual->id == id) return atual->sobrenome;
        atual = atual->prox;
    }
    return "Desconhecido";
}

const char* buscar_nome_por_id(personagem *lista, int id) {
    if (id <= 0) return "Desconhecido"; // Proteção contra IDs inválidos
    
    personagem *atual = lista;
    while (atual != NULL) {
        if (atual->id == id) return atual->nome;
        atual = atual->prox;
    }
    return "Desconhecido";
}

const char* nome_estilo(Estilo_de_luta e) {

    switch(e) {
        case KATANA: return "Katana";
        case ESPADA: return "Espada";
        case KATANA_DUPLA: return "Katana Dupla";
        case NUNCHAKUS: return "Nunchakus";
        case ARCO_E_FLECHA: return "Arco e Flecha";
        case BESTA: return "Besta";
        case KUNAIS: return "Kunais";
        case ESCUDO: return "Escudo";
        case CORRENTES: return "Correntes";
        case MACHADO: return "Machado";
        case MARTELO: return "Martelo";
        case LANCA: return "Lanca";
        case CLAVA: return "Clava";
        case BASTAO: return "Bastao";
        case BOXE: return "Boxe";
        case AIKIDO: return "Aikido";
        case JUDO: return "Judo";
        case KONG_FU: return "Kong Fu";
        case KARATE: return "Karate";
        case JIU_JITSU: return "Jiu Jitsu";
        case KICKBOXING: return "Kickboxing";
        case CAPOEIRA: return "Capoeira";
        case SUMO: return "Sumo";
        case ESTILO_NENHUM: return "Nenhum";

        default: return "Nenhum";
    }
}
// Função auxiliar para buscar família por ID
familia* buscar_familia_id(familia *lista, int id) {
    while (lista != NULL) {
        if (lista->id == id) return lista;
        lista = lista->prox;
    }
    return NULL;
}

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
//
Traco sortear_traco_principal() {
    return rand() % 4;
}

Estilo_de_luta sortear_estilo_de_luta() {
    return (Estilo_de_luta)(rand() % ESTILO_NENHUM);
}

Traco sortear_traco_secundario() {
    return 4 + rand() % 22;
}

const char* nome_traco(Traco t) {
    switch(t) {
        case FLEUMATICO: return "Fleumatico";
        case COLERICO: return "Colerico";
        case MELANCOLICO: return "Melancolico";
        case SANGUINEO: return "Sanguineo";

        case AMBICIOSO: return "Ambicioso";
        case VALENTE: return "Valente";
        case CRUEL: return "Cruel";
        case TEIMOSO: return "Teimoso";
        case PATRIOTA: return "Patriota";
        case ESTUDIOSO: return "Estudioso";
        case IMPULSIVO: return "Impulsivo";
        case PSICOPATA: return "Psicopata";
        case DEDICADO: return "Dedicado";
        case LEAL: return "Leal";
        case DESLEAL: return "Desleal";
        case BRINCALHAO: return "Brincalhao";
        case COVARDE: return "Covarde";
        case JUSTO: return "Justo";
        case BONDOSO: return "Bondoso";
        case MALIGNO: return "Maligno";
        case CALMO: return "Calmo";
        case DILIGENTE: return "Diligente";
        case PREGUICOSO: return "Peguicoso";
        case VINGATIVO: return "Vingativo";
        case ARROGANTE: return "Arrogante";
        case INSENCIVEL: return "Insensivel";

        default: return "Nenhum";
    }
}
