#ifndef PERFIS_H
#define PERFIS_H

typedef enum{
    // principais
    FLEUMATICO,
    COLERICO,
    MELANCOLICO,
    SANGUINEO,

    // secundários
    AMBICIOSO,
    VALENTE,
    CRUEL,
    TEIMOSO, //
    PATRIOTA,
    ESTUDIOSO,
    IMPULSIVO,
    PSICOPATA,
    DEDICADO,
    LEAL,
    DESLEAL,
    BRINCALHAO,
    COVARDE,
    JUSTO,
    //Novos
    BONDOSO,
    MALIGNO,
    CALMO,
    DILIGENTE,
    PREGUICOSO,
    VINGATIVO,
    ARROGANTE,
    INSENCIVEL,

    TRACO_NENHUM
} Traco;

typedef enum{
    //Armas
    KATANA,
    ESPADA,
    KATANA_DUPLA,
    NUNCHAKUS,
    ARCO_E_FLECHA,
    BESTA,
    KUNAIS,
    ESCUDO,
    CORRENTES,
    MACHADO,
    MARTELO,
    LANCA,
    CLAVA,
    BASTAO,
    //Artes Marciais
    BOXE,
    AIKIDO,
    JUDO,
    KONG_FU,
    KARATE,
    JIU_JITSU,
    KICKBOXING,
    CAPOEIRA,
    SUMO,

    ESTILO_NENHUM
} Estilo_de_luta;

typedef struct personagem {
    int eh_vivo; // 1 = vivo, 0 = morto
    int eh_player;
    //caracteristicas imutáveis
    int id;
    int sexo;                       //se 1-masculino se 2-feminino                         
    char nome[50];  
    char sobrenome[50];              
    int idade;                      
    int talento;                    //de 1 a 5
    //caracteristicas de skill/fisicas
    int destreza;
    Estilo_de_luta estilo_de_luta;
    int poder_fisico;
    int poder_fisico_maximo;               
    int potencial_evolucao;         //de 2 a 10
    //caracteristica de experiencia
    int carisma;                    
    int tatica_militar;             
    int administracao;
    int conhecimento;              
    //caracteristica de legado
    int fundador_familia;    // 1 = fundador | 0 = não fundador
    int familia_id;
    int conjuge_id;
    int id_pai;
    int id_mae;
    int filhos_ids[20];   // ou ponteiro depois
    int qtd_filhos;

    int fertilidade;
    //hierarquia
    int territorio;
    char classe[20];                  //Rei, Duque ou Comum
    int id_mestre;
    int id_pupilo;
    //recursos
    int dinheiro;
    int seguidores;
    //caracteristicas herdaveis
    int nivel_intelecto;
    int nivel_beleza;
    int eh_gigante;
    int eh_anao;
    //personalidade
    Traco principal;
    Traco traco2;
    Traco traco3;
    //doencas e eventos
    int iluminado;
    int imortal;
    int lepra;
    int cancer;
    //lista encadeada
    struct personagem *prox;
} personagem;

typedef struct familia {
    int id;
    char nome[50];

    int fundador_id;

    struct familia *prox;
} familia;

// No final de fichas.h, antes do #endif
typedef struct lista_familias {
    familia *topo;
} lista_familias;

// Estrutura para ordenar os rankings sem alterar a lista original
typedef struct {
    char nome_completo[101];
    int valor;
    Estilo_de_luta estilo;
} ItemRanking;

#endif