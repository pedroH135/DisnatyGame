#ifndef PERFIS_H
#define PERFIS_H


typedef struct personagem {
    //caracteristicas imutáveis
    int id;                         
    char nome[50];                  
    int idade;                      
    int talento;                    //de 1 a 5
    //caracteristicas de skill/fisicas
    int poder_fisico;               
    int potencial_evolucao;         //de 2 a 10
    //caracteristica de experiencia
    int carisma;                    
    int tatica_militar;             
    int administracao;              
    //caracteristica de legado
    int fertilidade;
    //hierarquia
    char classe[20];                  //Rei, Duque ou Comum
    //recursos
    int dinheiro;
    int seguidores;
    //lista encadeada
    struct personagem *prox;
} personagem;

typedef struct morto {
    int id;
    char nome[50];
    int idade_morte;
    int carisma;
    int tatica_militar;
    int administracao;

    struct morto *prox;
} morto;
#endif