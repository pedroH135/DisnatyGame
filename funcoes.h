#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fichas.h"
#include "funcoes_aux.h"
int PROX_ID = 1;
int ID_LEGADO = 1;
#define ANONIMO -1


void eventos_anuais(personagem *p){

    int acidente = rand() % 75 + 1;
    if(acidente == 75)
    {
        acidente = rand() % 20 + 1;
        printf("%s %s sofreu um acidente ", p->nome, p->sobrenome);
        if(acidente >= 13){
            p->poder_fisico-=5;
            printf("Leve\n");
        }
        else if(acidente < 13 && acidente >= 7){
            p->poder_fisico-=15;
            printf("Mediano\n");
        }
        else if(acidente <7 && acidente >= 3){
            p->poder_fisico-=30;
            printf("Grave\n");
        }
        else{
            p->poder_fisico-=50;
            printf("Gravissimo\n");
        }
    }

    int foi_roubado = rand() % 80 + 1;
    if(foi_roubado == 80)
    {
        foi_roubado = rand() % 20 + 1;
        printf("%s %s foi furtado, e teve uma perca ", p->nome, p->sobrenome);
        if(foi_roubado >= 13){
            p->dinheiro-=50;
            printf("Leve\n");
        }
        else if(foi_roubado < 13 && foi_roubado >= 7){
            p->dinheiro-=100;
            printf("Mediana\n");
        }
        else if(foi_roubado <7 && foi_roubado >= 3){
            p->dinheiro-=200;
            printf("Grave\n");
        }
        else{
            p->dinheiro-=400;
            printf("Gravissima\n");
        }
    }
    
    int encontrou_tesouro = rand() % 80 + 1;
    if(encontrou_tesouro == 80)
    {
        encontrou_tesouro = rand() % 20 + 1;
        printf("%s %s encontrou um tesouro, e teve um ganho ", p->nome, p->sobrenome);
        if(encontrou_tesouro >= 13){
            p->dinheiro+=50;
            printf("Leve\n");
        }
        else if(encontrou_tesouro < 13 && encontrou_tesouro >= 7){
            p->dinheiro+=100;
            printf("Mediano\n");
        }
        else if(encontrou_tesouro <7 && encontrou_tesouro >= 3){
            p->dinheiro+=200;
            printf("Otimo\n");
        }
        else{
            p->dinheiro+=400;
            printf("Exelente\n");
        }
    }

    int encontrou_livro = rand() % 140 + 1;
    if(encontrou_livro == 140){
        p->conhecimento += 30;
        printf("%s %s encontrou um livro\n", p->nome, p->sobrenome);
    }

    int iluminado = rand() % 3000 + 1;
    if(iluminado==3000){
        p->iluminado = 1;
        p->poder_fisico += 50;
        p->carisma += 50;
        p->administracao +=50;
        p->tatica_militar +=50;
        p->conhecimento +=50;
        p->destreza+=30;
        printf("%s %s recebeu a iluminacao\n", p->nome, p->sobrenome);
    }

    int imortalidade;
    if(p->imortal == 1){
        p->poder_fisico = p->poder_fisico_maximo;
    }
    else{
        imortalidade = rand() % 20000 + 1;
        if(imortalidade==20000){
        p->imortal = 1;
        printf("%s %s se tornou imortal\n", p->nome, p->sobrenome);
    }
    }

    int lepra;
    if(p->lepra == 1)
    {
        p->poder_fisico-=5;
        lepra = rand() % 90 + 1;
        if(lepra == 90) {
            p->lepra = 0;
            printf("%s %s se curou da Lepra\n", p->nome, p->sobrenome);
        }
    }
    else{
        lepra = rand() % 600 + 1;
        if(lepra == 1){
            p->lepra = 1;
            printf("%s %s adquiriu Lepra\n", p->nome, p->sobrenome);
        }
    }

    int cancer;
    if(p->cancer == 1)
    {
        p->poder_fisico -= rand() % 8 + 3;
        cancer = rand() % 100 + 1;
        if(cancer == 100) {
            p->cancer = 0;
            printf("%s %s se curou do Cancer\n", p->nome, p->sobrenome);
        }
    }
    else{
        cancer = rand() % 1000 + 1;
        if(p->idade<=8 && cancer<=4){
            p->cancer = 1;
            printf("%s %s adquiriu leucemia\n", p->nome, p->sobrenome);
        }
        if(p->idade>8 && p->idade<=30 && cancer==1){
            p->cancer = 1;
            printf("%s %s adquiriu Cancer\n", p->nome, p->sobrenome);
        }
        if(p->idade>30 && p->idade<=40 && cancer<=2){
            p->cancer = 1;
            printf("%s %s adquiriu Cancer\n", p->nome, p->sobrenome);
        }
        if(p->idade>40 && p->idade<=50 && cancer<=4){
            p->cancer = 1;
            printf("%s %s adquiriu Cancer\n", p->nome, p->sobrenome);
        }
        if(p->idade>50 && p->idade<=60 && cancer<=8){
            p->cancer = 1;
            printf("%s %s adquiriu Cancer\n", p->nome, p->sobrenome);
        }
        if(p->idade>60 && p->idade<=70 && cancer<=17){
            p->cancer = 1;
            printf("%s %s adquiriu Cancer\n", p->nome, p->sobrenome);
        }
        if(p->idade>70 && cancer<=30){
            p->cancer = 1;
            printf("%s %s adquiriu Cancer\n", p->nome, p->sobrenome);
        }
    }
    
    return;
}

//Batalhas
//Batalha corpo a corpo
void batalha_corpo_a_corpo(personagem *lista){
    int luta;
    printf("Que tipo de luta vai ser?\n1.Luta amistosa\n2.Luta seria\n");
    scanf("%d", &luta);

    int hp_a;
    int hp_b;

    if(luta==1)
    {
        hp_a = 10;
        hp_b = 10;
    }
    else if(luta==2)
    {
        hp_a = 20;
        hp_b = 20;
    }
    else
    {
        return;
    }
    int round = 1;
    int id_a, id_b, dado_a, dado_b, resultado, dano;

    printf("Digite o ID do primeiro lutador: ");
    scanf("%d", &id_a);
    printf("Digite o ID do segundo lutador: ");
    scanf("%d", &id_b);
    personagem *a = buscar_por_id(lista, id_a);
    personagem *b = buscar_por_id(lista, id_b);

    if(a->eh_vivo==0 || b->eh_vivo==0 || a==b){
        printf("Batalha invalida");
        return;
    }

    while(hp_a > 0 && hp_b > 0){
        printf("---------------------------------------\n");
        printf("Round : %d\n", round);
        printf("%s %s-> Poder Fisico: %d HP: %d\n", a->nome, a->sobrenome, a->poder_fisico, hp_a);
        printf("%s %s-> Poder Fisico: %d HP: %d\n", b->nome, b->sobrenome, b->poder_fisico, hp_b);

        printf("Digite a rolagem de dados de %s %s: ", a->nome, a->sobrenome);
        scanf("%d", &dado_a);
        printf("Digite a rolagem de dados de %s %s: ", b->nome, b->sobrenome);
        scanf("%d", &dado_b);

        if(dado_a<0 || dado_b<0) break;

        resultado = (a->poder_fisico*dado_a)-(b->poder_fisico*dado_b);

        if(resultado>0)
        {
            if(resultado<=50)
            {
                dano=1;
                hp_b-=1;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>50 && resultado<=100)
            {
                dano=2;
                hp_b-=2;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>100 && resultado<=150)
            {
                dano=3;
                hp_b-=3;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>150 && resultado<=200)
            {
                dano=4;
                hp_b-=4;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>200 && resultado<=300)
            {
                dano=5;
                hp_b-=5;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>300 && resultado<=500)
            {
                dano=6;
                hp_b-=6;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>500)
            {
                dano=7;
                hp_b-=7;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
        }
        else if (resultado<0)
        {
            if(resultado>=-50)
            {
                dano=1;
                hp_a-=1;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-50 && resultado>=-100)
            {
                dano=2;
                hp_a-=2;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-100 && resultado>=-150)
            {
                dano=3;
                hp_a-=3;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-150 && resultado>=-200)
            {
                dano=4;
                hp_a-=4;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-200 && resultado<=-300)
            {
                dano=5;
                hp_a-=5;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-300 && resultado>=-500)
            {
                dano=6;
                hp_a-=6;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-500)
            {
                dano=7;
                hp_a-=7;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
        }
        else if(resultado==0) printf("Empate no clash\n");
        
        round++;
    }

    if(hp_a>hp_b) printf("%s %s ganhou de %s %s (%d a %d)", a->nome, a->sobrenome, b->nome, b->sobrenome, hp_a, hp_b);
    else if(hp_b>hp_a) printf("%s %s ganhou de %s %s (%d a %d)", b->nome, b->sobrenome, a->nome, a->sobrenome, hp_b, hp_a);


}

void desafio_de_destreza(personagem *lista){

    int pontos_a = 0;
    int pontos_b = 0;

    int round = 1;
    int id_a, id_b, dado_a, dado_b, resultado;

    printf("Digite o ID do primeiro desafiante: ");
    scanf("%d", &id_a);
    printf("Digite o ID do segundo desafiante: ");
    scanf("%d", &id_b);
    personagem *a = buscar_por_id(lista, id_a);
    personagem *b = buscar_por_id(lista, id_b);

    if(a->eh_vivo==0 || b->eh_vivo==0 || a==b){
        printf("Desafio invalido\n");
        return;
    }

    while(pontos_a < 10 && pontos_b < 10){
        printf("---------------------------------------\n");
        printf("Round : %d\n", round);
        printf("%s %s-> Destreza: %s(%d) Pontos: %d\n", a->nome, a->sobrenome, nome_estilo(a->estilo_de_luta), a->destreza, pontos_a);
        printf("%s %s-> Destreza: %s(%d) Pontos: %d\n", b->nome, b->sobrenome, nome_estilo(b->estilo_de_luta), b->destreza, pontos_b);

        printf("Digite a rolagem de dados de %s %s: ", a->nome, a->sobrenome);
        scanf("%d", &dado_a);
        printf("Digite a rolagem de dados de %s %s: ", b->nome, b->sobrenome);
        scanf("%d", &dado_b);

        if(dado_a<0 || dado_b<0) break;

        resultado = (a->destreza*dado_a)-(b->destreza*dado_b);

        if(resultado>0)
        {
            if(resultado<=50)
            {
                pontos_a+=1;
                printf("%s %s faz 1 ponto\n", a->nome, a->sobrenome);
            }
            else if(resultado>50 && resultado<=100)
            {
                pontos_a+=2;
                printf("%s %s faz 2 ponto\n", a->nome, a->sobrenome);
            }
            else if(resultado>100 && resultado<=150)
            {
                pontos_a+=3;
                printf("%s %s faz 3 ponto\n", a->nome, a->sobrenome);
            }
            else if(resultado>150 && resultado<=200)
            {
                pontos_a+=4;
                printf("%s %s faz 4 ponto\n", a->nome, a->sobrenome);
            }
            else if(resultado>200 && resultado<=300)
            {
                pontos_a+=5;
                printf("%s %s faz 5 ponto\n", a->nome, a->sobrenome);
            }
            else if(resultado>300 && resultado<=500)
            {
                pontos_a+=6;
                printf("%s %s faz 6 ponto\n", a->nome, a->sobrenome);
            }
            else if(resultado>500)
            {
                pontos_a+=7;
                printf("%s %s faz 7 ponto\n", a->nome, a->sobrenome);
            }
        }
        else if (resultado<0)
        {
            if(resultado>=-50)
            {
                pontos_b+=1;
                printf("%s %s faz 1 ponto\n", b->nome, b->sobrenome);
            }
            else if(resultado<-50 && resultado>=-100)
            {
                pontos_b+=2;
                printf("%s %s faz 2 ponto\n", b->nome, b->sobrenome);
            }
            else if(resultado<-100 && resultado>=-150)
            {
                pontos_b+=3;
                printf("%s %s faz 3 ponto\n", b->nome, b->sobrenome);
            }
            else if(resultado<-150 && resultado>=-200)
            {
                pontos_b+=4;
                printf("%s %s faz 4 ponto\n", b->nome, b->sobrenome);
            }
            else if(resultado<-200 && resultado<=-300)
            {
                pontos_b+=5;
                printf("%s %s faz 5 ponto\n", b->nome, b->sobrenome);
            }
            else if(resultado<-300 && resultado>=-500)
            {
                pontos_b+=6;
                printf("%s %s faz 6 ponto\n", b->nome, b->sobrenome);
            }
            else if(resultado<-500)
            {
                pontos_b+=7;
                printf("%s %s faz 7 ponto\n", b->nome, b->sobrenome);
            }
        }
        else if(resultado==0) printf("Empate ninguém faz ponto\n");
        
        round++;
    }

    if(pontos_a>pontos_b) printf("%s %s ganhou de %s %s (%d a %d)", a->nome, a->sobrenome, b->nome, b->sobrenome, pontos_a, pontos_b);
    else if(pontos_a<pontos_b) printf("%s %s ganhou de %s %s (%d a %d)", b->nome, b->sobrenome, a->nome, a->sobrenome, pontos_b, pontos_a);


}

void batalha_armada(personagem *lista){
    int luta;
    printf("Que tipo de luta vai ser?\n1.Luta amistosa\n2.Luta seria\n");
    scanf("%d", &luta);

    int hp_a;
    int hp_b;

    if(luta==1)
    {
        hp_a = 10;
        hp_b = 10;
    }
    else if(luta==2)
    {
        hp_a = 20;
        hp_b = 20;
    }
    else
    {
        return;
    }
    int round = 1;
    int id_a, id_b, dado_a, dado_b, resultado, dano, poder_a, poder_b;

    printf("Digite o ID do primeiro lutador: ");
    scanf("%d", &id_a);
    printf("Digite o ID do segundo lutador: ");
    scanf("%d", &id_b);
    personagem *a = buscar_por_id(lista, id_a);
    personagem *b = buscar_por_id(lista, id_b);

    if(a->eh_vivo==0 || b->eh_vivo==0 || a==b){
        printf("Batalha invalida");
        return;
    }

    poder_a = ((a->poder_fisico*4)+(a->destreza*6))/10;
    poder_b = ((b->poder_fisico*4)+(b->destreza*6))/10;

    while(hp_a > 0 && hp_b > 0){
        printf("---------------------------------------\n");
        printf("Round : %d\n", round);
        printf("%s %s-> P_F: %d Destreza: %d Poder Total: %d HP: %d\n", a->nome, a->sobrenome, a->poder_fisico, a->destreza, poder_a, hp_a);
        printf("%s %s-> P_F: %d Destreza: %d Poder Total: %d HP: %d\n", b->nome, b->sobrenome, b->poder_fisico, b->destreza, poder_b, hp_b);

        printf("Digite a rolagem de dados de %s %s: ", a->nome, a->sobrenome);
        scanf("%d", &dado_a);
        printf("Digite a rolagem de dados de %s %s: ", b->nome, b->sobrenome);
        scanf("%d", &dado_b);

        if(dado_a<0 || dado_b<0) break;

        resultado = (poder_a*dado_a)-(poder_b*dado_b);

        if(resultado>0)
        {
            if(resultado<=50)
            {
                dano=1;
                hp_b-=1;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>50 && resultado<=100)
            {
                dano=2;
                hp_b-=2;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>100 && resultado<=150)
            {
                dano=3;
                hp_b-=3;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>150 && resultado<=200)
            {
                dano=4;
                hp_b-=4;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>200 && resultado<=300)
            {
                dano=5;
                hp_b-=5;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>300 && resultado<=500)
            {
                dano=6;
                hp_b-=6;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
            else if(resultado>500)
            {
                dano=7;
                hp_b-=7;
                printf("%s %s atinge %s %s causando %d de dano\n", a->nome, a->sobrenome, b->nome, b->sobrenome, dano);
            }
        }
        else if (resultado<0)
        {
            if(resultado>=-50)
            {
                dano=1;
                hp_a-=1;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-50 && resultado>=-100)
            {
                dano=2;
                hp_a-=2;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-100 && resultado>=-150)
            {
                dano=3;
                hp_a-=3;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-150 && resultado>=-200)
            {
                dano=4;
                hp_a-=4;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-200 && resultado<=-300)
            {
                dano=5;
                hp_a-=5;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-300 && resultado>=-500)
            {
                dano=6;
                hp_a-=6;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
            else if(resultado<-500)
            {
                dano=7;
                hp_a-=7;
                printf("%s %s atinge %s %s causando %d de dano\n", b->nome, b->sobrenome, a->nome, a->sobrenome, dano);
            }
        }
        else if(resultado==0) printf("Empate no clash\n");
        
        round++;
    }

    if(hp_a>hp_b) printf("%s %s ganhou de %s %s (%d a %d)", a->nome, a->sobrenome, b->nome, b->sobrenome, hp_a, hp_b);
    else if(hp_b>hp_a) printf("%s %s ganhou de %s %s (%d a %d)", b->nome, b->sobrenome, a->nome, a->sobrenome, hp_b, hp_a);


}

void front_de_guerra(personagem *lista){
    int dado_a, dado_b, id_a, id_b, resultado;
    int round=1;
    int v_a=0;
    int v_b=0;
    int baixas_b=0;
    int baixas_a=0;
    printf("Digite o ID do primeiro comandante: ");
    scanf("%d", &id_a);
    printf("Digite o ID do segundo comandante: ");
    scanf("%d", &id_b);
    personagem *a = buscar_por_id(lista, id_a);
    personagem *b = buscar_por_id(lista, id_b);

    if(a->eh_vivo==0 || b->eh_vivo==0 || a==b){
        printf("Batalha invalida");
        return;
    }

    while(a->seguidores>0 && b->seguidores>0 && round<=6){
        printf("---------------------------------------\n");
        printf("Round : %d\n", round);
        printf("%s %s-> Tat.Militar: %d Exercito: %d\n", a->nome, a->sobrenome, a->tatica_militar, a->seguidores);
        printf("%s %s-> Tat.Militar: %d Exercito: %d\n", b->nome, b->sobrenome, b->tatica_militar, b->seguidores);

        printf("Digite a rolagem de dados de %s %s: ", a->nome, a->sobrenome);
        scanf("%d", &dado_a);
        printf("Digite a rolagem de dados de %s %s: ", b->nome, b->sobrenome);
        scanf("%d", &dado_b);

        if(dado_a<0 || dado_b<0) break;

        resultado = (dado_a*a->tatica_militar*a->seguidores)-(dado_b*b->tatica_militar*b->seguidores);
        resultado = resultado/250;
        if(resultado>0)
        {
            if(resultado>b->seguidores) resultado = b->seguidores;
            b->seguidores-=resultado;
            v_a++;
            baixas_b+=resultado;
            printf("%s %s ganhou o round, %s %s perdeu %d soldados\n", a->nome, a->sobrenome, b->nome, b->sobrenome, resultado);
        }
        else if(resultado<0)
        {
            if(resultado>a->seguidores) resultado = a->seguidores;
            a->seguidores+=resultado;
            v_b++;
            baixas_a+=resultado;
            printf("%s %s ganhou o round, %s %s perdeu %d soldados\n", b->nome, b->sobrenome, a->nome, a->sobrenome, resultado);
        }
        else if(resultado==0) printf("Empate no confrontro, ninguem perdeu exercito\n");

        round++;
    }

    if(a->seguidores<0) a->seguidores=0;
    if(b->seguidores<0) b->seguidores=0;
    printf("---------------------------------------\n");
    printf("-----RESULTADO FINAL-----\n");
    printf("%s %s -> Baixas: %d Vitorias: %d\n", a->nome, a->sobrenome, baixas_a, v_a);
    printf("%s %s -> Baixas: %d Vitorias: %d\n", b->nome, b->sobrenome, baixas_b, v_b);
    printf("---------------------------------------\n");
}

void territorio(personagem *lista){

    int op, id;
    printf("Escolha uma opcao:\n");
    printf("1. Atribuir territorio:\n");
    printf("2. Retirar territorio:\n");
    scanf("%d", &op);

    if(op == 1){
        printf("Digite o ID de quem vai receber o territorio: ");
        scanf("%d", &id);
    }
    else if(op == 2){
        printf("Digite o ID de quem vai perder o territorio: ");
        scanf("%d", &id);
    }
    else{
        printf("Opcao Invalida\n");
        return;
    }

    personagem *p = buscar_por_id(lista, id);

    if(op==1){
        p->territorio+=1;
        printf("%s %s adquiriu um territorio", p->nome, p->sobrenome);
    }
    else if(op==2){
        p->territorio-=1;
        printf("%s %s perdeu um territorio", p->nome, p->sobrenome);
    }

}

void salvar_estado_jogo(personagem *lista, familia *lista_f, int ano) {

    FILE *f_config = fopen("config.bin", "wb");
    if (!f_config) return;

    fwrite(&PROX_ID, sizeof(int), 1, f_config);
    fwrite(&ID_LEGADO, sizeof(int), 1, f_config);
    fwrite(&ano, sizeof(int), 1, f_config);
    fclose(f_config);

    FILE *f_personagens = fopen("personagens.bin", "wb");
    if (f_personagens) {

        personagem *p = lista;

        while (p) {
            personagem temp = *p;
            temp.prox = NULL;
            fwrite(&temp, sizeof(personagem), 1, f_personagens);
            p = p->prox;
        }

        fclose(f_personagens);
    }

    FILE *f_fam = fopen("familias.bin", "wb");
    if (f_fam) {

        familia *f = lista_f;

        while (f) {
            familia temp = *f;
            temp.prox = NULL;
            fwrite(&temp, sizeof(familia), 1, f_fam);
            f = f->prox;
        }

        fclose(f_fam);
    }

    printf("\n[SISTEMA] Jogo salvo com sucesso!\n");
}

//carregar estado passado do jogo
personagem* carregar_personagens(int *prox_id, int *id_legado, int *ano) {

    FILE *f_config = fopen("config.bin", "rb");
    if (f_config) {
        fread(prox_id, sizeof(int), 1, f_config);
        fread(id_legado, sizeof(int), 1, f_config);
        fread(ano, sizeof(int), 1, f_config);
        fclose(f_config);
    }

    FILE *f = fopen("personagens.bin", "rb");
    if (!f) return NULL;

    personagem *lista = NULL;
    personagem *ultimo = NULL;
    personagem temp;

    while (fread(&temp, sizeof(personagem), 1, f)) {

        personagem *novo = malloc(sizeof(personagem));
        *novo = temp;
        novo->prox = NULL;

        if (!lista)
            lista = novo;
        else
            ultimo->prox = novo;

        ultimo = novo;
    }

    fclose(f);
    return lista;
}


familia* carregar_familias() {
    FILE *f = fopen("familias.bin", "rb");
    if (!f) return NULL;

    familia *lista = NULL, *ultimo = NULL;
    familia temp;

    while (fread(&temp, sizeof(familia), 1, f)) {
        familia *novo = malloc(sizeof(familia));
        *novo = temp;
        novo->prox = NULL;

        if (!lista) lista = novo;
        else ultimo->prox = novo;

        ultimo = novo;
    }

    fclose(f);
    return lista;
}

//calcula o ganho de dinheiro anual
int ganho_dinheiro_anual(personagem *p) {

    int bonus_territorio = 0;

    if(p->classe[0]=='R')
    {
        if(p->territorio<5) bonus_territorio = 0;
        else if(p->territorio>=5 && p->territorio<10) bonus_territorio = 50;
        else if(p->territorio>=10 && p->territorio<15) bonus_territorio = 100;
        else if(p->territorio>=15 && p->territorio<20) bonus_territorio = 150;
        else if(p->territorio>=25 && p->territorio<30) bonus_territorio = 200;
        else if(p->territorio>=35 && p->territorio<40) bonus_territorio = 250;
        else if(p->territorio>=40) bonus_territorio = 300;
    }
    else if(p->classe[0]=='D')
    {
        if(p->territorio<5) bonus_territorio = 0;
        else if(p->territorio>=5 && p->territorio<10) bonus_territorio = 25;
        else if(p->territorio>=10 && p->territorio<15) bonus_territorio = 50;
        else if(p->territorio>=15 && p->territorio<20) bonus_territorio = 75;
        else if(p->territorio>=25 && p->territorio<30) bonus_territorio = 100;
        else if(p->territorio>=35 && p->territorio<40) bonus_territorio = 125;
        else if(p->territorio>=40) bonus_territorio = 150;
    }

    int d6 = rand()%6 + 1;

    int base = d6 * mult_classe(p->classe);

    float mult = mult_adm(p->administracao);

    int ganho = (int)((base * mult)+bonus_territorio);

    return ganho;
}
//calcula o ganho de seguidores anual
int ganho_seguidores_anual(personagem *p) {

        int bonus_territorio = 0;

    if(p->classe[0]=='R')
    {
        if(p->territorio<5) bonus_territorio = 0;
        else if(p->territorio>=5 && p->territorio<10) bonus_territorio = 50;
        else if(p->territorio>=10 && p->territorio<15) bonus_territorio = 100;
        else if(p->territorio>=15 && p->territorio<20) bonus_territorio = 150;
        else if(p->territorio>=25 && p->territorio<30) bonus_territorio = 200;
        else if(p->territorio>=35 && p->territorio<40) bonus_territorio = 250;
        else if(p->territorio>=40) bonus_territorio = 300;
    }
    else if(p->classe[0]=='D')
    {
        if(p->territorio<5) bonus_territorio = 0;
        else if(p->territorio>=5 && p->territorio<10) bonus_territorio = 25;
        else if(p->territorio>=10 && p->territorio<15) bonus_territorio = 50;
        else if(p->territorio>=15 && p->territorio<20) bonus_territorio = 75;
        else if(p->territorio>=25 && p->territorio<30) bonus_territorio = 100;
        else if(p->territorio>=35 && p->territorio<40) bonus_territorio = 125;
        else if(p->territorio>=40) bonus_territorio = 150;
    }

    int d6 = rand()%6 + 1;

    int total = d6;

    if (p->carisma >= 40)
        total *= 2;
    else
        total += bonus_carisma(p->carisma);

    total *= mult_classe(p->classe);

    total+=bonus_territorio;

    return total;
}

void aplicar_traco(personagem *p, Traco t) {

    switch(t) {

        case AMBICIOSO:
            if(rand()%5==0) p->dinheiro += ganho_dinheiro_anual(p);
            if(rand()%7==0) p->destreza++;
        break;

        case VALENTE:
            if(rand()%5==0) p->poder_fisico += 1;
        break;

        case CRUEL:
            if(rand()%5==0) p->dinheiro += 3;
            if(rand()%10==0) p->seguidores -= 10;
        break;

        case TEIMOSO:
            if(rand()%6==0) p->administracao -=1;
            if(rand()%7==0) p->poder_fisico += 1;
        break;

        case PATRIOTA:
            if(rand()%5==0) p->tatica_militar += 1;
        break;

        case ESTUDIOSO:
            if(rand()%6==0){
                p->tatica_militar++;
                p->administracao++;
            }
            if(rand()%2==0) p->conhecimento++;
            if(rand()%8==0) p->destreza++;
        break;

        case IMPULSIVO:
            if(rand()%7==0) p->dinheiro-=ganho_dinheiro_anual(p);
            if(rand()%15==0) p->poder_fisico++;
        break;

        case PSICOPATA:
            if(rand()%7==0) p->tatica_militar++;
            if(rand()%10==0) p->poder_fisico++;
        break;

        case DEDICADO:
            if(rand()%4==0) p->poder_fisico++;
            if(rand()%5==0) p->destreza++;
        break;

        case LEAL:
            if(rand()%6==0) p->carisma++;
            if(rand()%9==0) p->administracao++;
        break;

        case DESLEAL:
            if(rand()%4==0) ganho_dinheiro_anual(p);
            if(rand()%9==0) p->tatica_militar += 1;
        break;

        case BRINCALHAO:
            if(rand()%5==0) p->carisma++;
        break;

        case COVARDE:
            if(rand()%10==0){
                p->poder_fisico--;
                p->tatica_militar--;
            }
        break;

        case JUSTO:
            if(rand()%9==0) p->carisma++;
            if(rand()%8==0) p->administracao++;
        break;

        case BONDOSO:
            if(rand()%6==0) p->carisma+=1;
        break;

        case MALIGNO:
            if(rand()%6==0) p->tatica_militar+=1;
        break;

        case CALMO:
            if(rand()%5==0) p->tatica_militar+=1;
            if(rand()%5==0) p->administracao+=1;
            if(rand()%8==0) p->destreza++;
        break;

        case DILIGENTE:
            if(rand()%5==0) p->administracao+=1;
            if(rand()%5==0) p->conhecimento+=1;
            if(rand()%6==0) p->destreza++;
        break;

        case PREGUICOSO:
            if(rand()%6==0) p->conhecimento-=1;
            if(rand()%7==0) p->poder_fisico-=1;
        break;

        case VINGATIVO:
            if(rand()%6==0) p->poder_fisico+=1;
            if(rand()%9==0) p->destreza++;
        break;

        case ARROGANTE:
            if(rand()%8==0) p->seguidores-=10;
        break;

        case INSENCIVEL:
            if(rand()%8==0) p->carisma-=1;
            if(rand()%6==0) p->poder_fisico+=1;
            if(rand()%10==0) p->destreza++;
        break;

        // principais

        case FLEUMATICO:
            if(rand()%6==0) p->tatica_militar++;
            if(rand()%6==0) p->administracao++;
        break;

        case MELANCOLICO:
            if(rand()%3==0) p->administracao++;
        break;

        case SANGUINEO:
            if(rand()%3==0) p->carisma++;
        break;

        case COLERICO:
            if(rand()%6==0) p->poder_fisico++;
            if(rand()%6==0) p->tatica_militar++;
        break;

        default:
        break;
    }
}
//bonus e penalidade de gigantes
void aplicar_herdaveis(personagem *p) {
    // Sorteio aleatório para Gigante/Anão (1 de 150)
    if (rand() % 150 == 0) p->eh_gigante = 1;
    else if (rand() % 150 == 0) p->eh_anao = 1;

    // Bônus e Penalidades de Nascimento
    if (p->eh_gigante) {
        p->carisma -= 20;
        p->poder_fisico += 40;
        p->conhecimento -= 30;
    }
    if (p->eh_anao) {
        p->carisma -= 30;
    }
}

void aplicar_status_nascimento(personagem *p){
    if (p->eh_gigante) {
        p->carisma -= 20;
        p->poder_fisico += 40;
        p->conhecimento -= 30;
    }
    if (p->eh_anao) {
        p->carisma -= 30;
    }
}

// Lógica: Se houver dois, sorteia entre eles. Se houver um, usa ele.
int calcular_heranca_solo_ou_dupla(personagem *pai, personagem *mae, char tipo) {
    int nivel_base = 0;

    // 1️⃣ Tentativa de herança normal
    if (pai != NULL && mae != NULL) {
        // 50% de chance de cada
        if (rand() % 2 == 0){
            nivel_base = (tipo == 'I') ? pai->nivel_intelecto : pai->nivel_beleza;
            if(tipo=='I') nivel_base = calcular_heranca_intelecto(nivel_base);
            else nivel_base = calcular_heranca_beleza(nivel_base);
        }
        else{
            nivel_base = (tipo == 'I') ? mae->nivel_intelecto : mae->nivel_beleza;
            if(tipo==1) nivel_base = calcular_heranca_intelecto(nivel_base);
            else nivel_base = calcular_heranca_beleza(nivel_base);
        }
    }
    else if (pai != NULL) {
        nivel_base = (tipo == 'I') ? pai->nivel_intelecto : pai->nivel_beleza;
        if(tipo==1) nivel_base = calcular_heranca_intelecto(nivel_base);
        else nivel_base = calcular_heranca_beleza(nivel_base);
    }
    else if (mae != NULL) {
        nivel_base = (tipo == 'I') ? mae->nivel_intelecto : mae->nivel_beleza;
        if(tipo==1) nivel_base = calcular_heranca_intelecto(nivel_base);
        else nivel_base = calcular_heranca_beleza(nivel_base);
    }

    // 2️⃣ Se ninguém tem → mutação espontânea rara
    if (nivel_base == 0) {
        int chance = (tipo == 'I') ? 100 : 300; 
        // Intelecto mais comum que beleza (ajustável)

        if (rand() % chance == 0) {
            return (tipo == 'I')
                ? sortear_intelecto_inicial()
                : sortear_beleza_inicial();
        }
        return 0;
    }

    // 3️⃣ Mutação genética normal (leve)
    int d10 = rand() % 10 + 1;

    if (d10 <= 4) return nivel_base - 1;
    if (d10 <= 9) return nivel_base;
    return nivel_base + 1;
}

int herdar_binario_solo(int p_traco, int m_traco, int chance_aleatoria, int tem_pai, int tem_mae) {
    // Se algum dos presentes tem o traço, 50% de chance de passar
    if ((tem_pai && p_traco) || (tem_mae && m_traco)) {
        if (rand() % 2 == 0) return 1;
    }
    // Caso contrário, chance aleatória rara de mutação nova (1 de 150)
    return (rand() % chance_aleatoria == 0) ? 1 : 0;
}

void ganho_hereditario_anual(personagem *p) {
    int chance_alvo = 0;
    int divisor = 0;

    switch(p->nivel_intelecto) {
        case 1: chance_alvo = 1; divisor = 6; break; // Hábil
        case 2: chance_alvo = 1; divisor = 4; break; // Esperto
        case 3: chance_alvo = 1; divisor = 2; break; // Inteligente
        case 4: chance_alvo = 4; divisor = 6; break; // Gênio
        case -1: // Deslechado (Pode perder 1 ponto aleatório as vezes?)
            if((rand() % 10) == 0) p->administracao--; 
            return;
        case -2: // Burro
            if((rand() % 5) == 0) p->conhecimento--;
            return;
        default: return;
    }

    // Aplica o bônus em todos os atributos conforme a chance definida
    if ((rand() % divisor) < chance_alvo) p->poder_fisico++;
    if ((rand() % divisor) < chance_alvo) p->carisma++;
    if ((rand() % divisor) < chance_alvo) p->administracao++;
    if ((rand() % divisor) < chance_alvo) p->tatica_militar++;
    if ((rand() % divisor) < chance_alvo) p->conhecimento++;
    if ((rand() % divisor) < chance_alvo) p->destreza++;

    // --- Lógica de Beleza ---
    switch(p->nivel_beleza) {
        case 4: // Lendária
            if ((rand() % 6) < 2) p->carisma += 2; // 2 de 6 para +2
            if ((rand() % 6) < 2) p->carisma += 1; // 2 de 6 para +1
            break;
        case 3: // Muito Bonito
            if ((rand() % 2) == 0) p->carisma += 1; // 1 de 2
            break;
        case 2: // Bonito
            if ((rand() % 6) < 2) p->carisma += 1; // 2 de 6
            break;
        case 1: // Atraente
            if ((rand() % 6) == 0) p->carisma += 1; // 1 de 6
            break;
        case -1: // Pouco Atraente
            if ((rand() % 8) == 0) p->carisma -= 1; // 1 de 8
            break;
        case -2: // Muito Feio
            if ((rand() % 3) == 0) p->carisma -= 1; // 1 de 3
            break;
    }
}
//
void aplicar_tracos_anuais(personagem *p) {

    aplicar_traco(p, p->principal);

    if(p->traco2 != TRACO_NENHUM)
        aplicar_traco(p, p->traco2);

    if(p->traco3 != TRACO_NENHUM)
        aplicar_traco(p, p->traco3);
}
//ajusta recursos de forma manual
void ajustar_recursos_manual(personagem *lista) {

    int id;
    printf("Digite o ID do personagem: ");
    scanf("%d", &id);

    personagem *p = buscar_por_id(lista, id);

    if (!p) {
        printf("Personagem nao encontrado.\n");
        return;
    }

    int op;
    printf("\n1 - Ajustar dinheiro\n");
    printf("2 - Ajustar seguidores\n");
    printf("Escolha: ");
    scanf("%d", &op);

    int valor;
    printf("Digite o valor (use negativo para remover): ");
    scanf("%d", &valor);

    if (op == 1) {
        p->dinheiro += valor;
        if (p->dinheiro < 0) p->dinheiro = 0;
        printf("Dinheiro atualizado: %d\n", p->dinheiro);
    }
    else if (op == 2) {
        p->seguidores += valor;
        if (p->seguidores < 0) p->seguidores = 0;
        printf("Seguidores atualizados: %d\n", p->seguidores);
    }
    else {
        printf("Opcao invalida.\n");
    }
}
//gera um txt do ranking anualmente
void gerar_ranking_anual(personagem *lista) {

    FILE *f = fopen("ranking_geral.txt", "w");
    if (!f) return;

    const char *labels[] = {
        "LONGEVIDADE",
        "PODER FISICO",
        "DESTREZA",
        "CARISMA",
        "ADMINISTRACAO",
        "CONHECIMENTO",
        "TATICA MILITAR"
    };

    fprintf(f, "==========================================================\n");
    fprintf(f, "             RANKING MUNDIAL - TOP 10                     \n");
    fprintf(f, "==========================================================\n\n");

    for (int cat = 0; cat < 7; cat++) {

        ItemRanking vivos[500];
        ItemRanking historia[1000];

        int n_vivos = 0;
        int n_hist = 0;

        personagem *p = lista;

        while (p != NULL && n_hist < 1000) {

            int valor_atual = 0;
            int valor_hist = 0;

            if (cat == 0) { // longevidade
                valor_hist = p->idade;
                if (p->eh_vivo)
                    valor_atual = p->idade;
            }
            else if (cat == 1) {
                valor_hist = p->poder_fisico_maximo;
                if (p->eh_vivo)
                    valor_atual = p->poder_fisico;
            }
            else if (cat == 2) {
                valor_hist = p->destreza;
                if (p->eh_vivo)
                    valor_atual = p->destreza;
            }
            else if (cat == 3) {
                valor_hist = p->carisma;
                if (p->eh_vivo)
                    valor_atual = p->carisma;
            }
            else if (cat == 4) {
                valor_hist = p->administracao;
                if (p->eh_vivo)
                    valor_atual = p->administracao;
            }
            else if (cat == 5) {
                valor_hist = p->conhecimento;
                if (p->eh_vivo)
                    valor_atual = p->conhecimento;
            }
            else if (cat == 6) {
                valor_hist = p->tatica_militar;
                if (p->eh_vivo)
                    valor_atual = p->tatica_militar;
            }

            sprintf(historia[n_hist].nome_completo, "%s %s", p->nome, p->sobrenome);
            historia[n_hist].valor = valor_hist;

            if (cat == 2) // DESTREZA
                historia[n_hist].estilo = p->estilo_de_luta;

            n_hist++;

            if (p->eh_vivo && n_vivos < 500) {
                sprintf(vivos[n_vivos].nome_completo, "%s %s", p->nome, p->sobrenome);
                vivos[n_vivos].valor = valor_atual;

                if (cat == 2) // DESTREZA
                    vivos[n_vivos].estilo = p->estilo_de_luta;

                n_vivos++;
            }

            p = p->prox;
        }

        if (n_vivos > 0) qsort(vivos, n_vivos, sizeof(ItemRanking), comp_ranking);
        if (n_hist > 0) qsort(historia, n_hist, sizeof(ItemRanking), comp_ranking);

        fprintf(f, ">>> %s <<<\n", labels[cat]);
        fprintf(f, "%-30s | %-30s\n", "TOP 10 ATUALIDADE", "TOP 10 HISTORIA");
        fprintf(f, "----------------------------------------------------------\n");

        for (int i = 0; i < 10; i++) {

            char txt_v[35] = "---";
            char txt_h[35] = "---";

            if (i < n_vivos) {

                if (cat == 2) // DESTREZA
                    sprintf(txt_v, "%d. %s (%d) [%s]",
                            i+1,
                            vivos[i].nome_completo,
                            vivos[i].valor,
                            nome_estilo(vivos[i].estilo));
                else
                    sprintf(txt_v, "%d. %s (%d)",
                            i+1,
                            vivos[i].nome_completo,
                            vivos[i].valor);
            }


            if (i < n_hist) {

                if (cat == 2)
                    sprintf(txt_h, "%d. %s (%d) [%s]",
                            i+1,
                            historia[i].nome_completo,
                            historia[i].valor,
                            nome_estilo(historia[i].estilo));
                else
                    sprintf(txt_h, "%d. %s (%d)",
                            i+1,
                            historia[i].nome_completo,
                            historia[i].valor);
            }


            fprintf(f, "%-30s | %-30s\n", txt_v, txt_h);
        }

        fprintf(f, "\n");
    }

    fclose(f);
}

//Herança
void aplicar_heranca_manual(personagem *lista, personagem *morto) {

    int qtd;

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

        if (herdeiros[i] == NULL || herdeiros[i]->eh_vivo == 0) {
            printf("ID invalido! Tente novamente.\n");
            i--;
        }
    }

    /* ============================ */
    /* SUCESSAO DE PLAYER (1 HERDEIRO) */
    /* ============================ */

    if (qtd == 1) {

        strcpy(herdeiros[0]->classe, morto->classe);
        herdeiros[0]->territorio = morto->territorio;
        herdeiros[0]->eh_player = 1;

        morto->eh_player = 0;

        printf("\n%s agora e o novo personagem controlado!\n",
            herdeiros[0]->nome);
    }


    /* ============================ */
    /* DIVISAO DE RECURSOS         */
    /* ============================ */

    int dinheiro_parte = morto->dinheiro / qtd;
    int seguidores_parte = morto->seguidores / qtd;

    for (int i = 0; i < qtd; i++) {
        herdeiros[i]->dinheiro += dinheiro_parte;
        herdeiros[i]->seguidores += seguidores_parte;
    }

    morto->dinheiro = 0;
    morto->seguidores = 0;

    printf("Heranca dividida com sucesso!\n");
}


void aplicar_heranca(personagem *lista, personagem *morto) {

    printf("\nPersonagem %s morreu!\n", morto->nome);

    /* ===================================== */
    /* SE FOR PLAYER -> HERANCA MANUAL      */
    /* ===================================== */

    if (morto->eh_player == 1) {
        aplicar_heranca_manual(lista, morto);
        return;
    }

    /* ===================================== */
    /* NAO PLAYER -> HERANCA AUTOMATICA     */
    /* ===================================== */

    personagem *candidato = NULL;
    personagem *p = lista;

    /* 1 - FILHO HOMEM (mais velho) */
    while (p != NULL) {
        if ((p->id_pai == morto->id || p->id_mae == morto->id) &&
            p->sexo == 1 &&
            p->eh_vivo == 1) {

            if (candidato == NULL || p->idade > candidato->idade) {
                candidato = p;
            }
        }
        p = p->prox;
    }

    /* 2 - FILHA MULHER */
    if (candidato == NULL) {
        p = lista;
        while (p != NULL) {
            if ((p->id_pai == morto->id || p->id_mae == morto->id) &&
                p->sexo == 2 &&
                p->eh_vivo == 1) {

                if (candidato == NULL || p->idade > candidato->idade) {
                    candidato = p;
                }
            }
            p = p->prox;
        }
    }

    /* 3 e 4 - IRMAOS */
    if (candidato == NULL && morto->id_pai != -1) {

        p = lista;

        /* irmão homem */
        while (p != NULL) {
            if (p->id != morto->id &&
                p->id_pai == morto->id_pai &&
                p->id_mae == morto->id_mae &&
                p->sexo == 1 &&
                p->eh_vivo == 1) {

                if (candidato == NULL || p->idade > candidato->idade) {
                    candidato = p;
                }
            }
            p = p->prox;
        }

        /* irmã mulher */
        if (candidato == NULL) {
            p = lista;
            while (p != NULL) {
                if (p->id != morto->id &&
                    p->id_pai == morto->id_pai &&
                    p->id_mae == morto->id_mae &&
                    p->sexo == 2 &&
                    p->eh_vivo == 1) {

                    if (candidato == NULL || p->idade > candidato->idade) {
                        candidato = p;
                    }
                }
                p = p->prox;
            }
        }
    }

    /* 5 - PAI */
    if (candidato == NULL && morto->id_pai != -1) {
        personagem *pai = buscar_por_id(lista, morto->id_pai);
        if (pai != NULL && pai->eh_vivo == 1)
            candidato = pai;
    }

    /* 6 - MAE */
    if (candidato == NULL && morto->id_mae != -1) {
        personagem *mae = buscar_por_id(lista, morto->id_mae);
        if (mae != NULL && mae->eh_vivo == 1)
            candidato = mae;
    }

    /* RESULTADO */
    if (candidato != NULL) {

        candidato->dinheiro += morto->dinheiro;
        candidato->seguidores += morto->seguidores;

        printf("Heranca automatica transferida para %s (ID:%d)\n",
               candidato->nome,
               candidato->id);

        morto->dinheiro = 0;
        morto->seguidores = 0;

    } else {

        printf("Nenhum herdeiro automatico encontrado.\n");
        printf("Aplicando heranca manual...\n");

        aplicar_heranca_manual(lista, morto);
    }
}

//Casamento
void realizar_casamento(personagem *lista) {
    int id_noivo;
    int id_noiva;
    printf("Id do noivo: ");
    scanf("%d", &id_noivo);
    printf("Id do noiva:");
    scanf("%d", &id_noiva);
    if (id_noivo == id_noiva) {
        printf("Erro: um personagem não pode casar consigo mesmo.\n");
        return;
    }

    personagem *p1 = buscar_por_id(lista, id_noivo);
    personagem *p2 = buscar_por_id(lista, id_noiva);

    if (!p1 || !p2 || p1->eh_vivo==0 || p2->eh_vivo==0) {
        printf("Erro: um ou ambos os IDs não existem.\n");
        return;
    }

    if (p1->sexo!=1 || p2->sexo!=2){
        printf("Comunhao invalida"); //personagens de mesmo sexo nao podem gerar herdeiros
        return;
    }

    if (p1->conjuge_id != -1 || p2->conjuge_id != -1) {
        printf("Erro: um dos personagens já é casado.\n");
        return;
    }

    // realiza o casamento
    p1->conjuge_id = p2->id;
    p2->conjuge_id = p1->id;

    // alinhar família
    if (p1->familia_id != -1 && p2->familia_id == -1)
        p2->familia_id = p1->familia_id;
    else if (p2->familia_id != -1 && p1->familia_id == -1)
        p1->familia_id = p2->familia_id;

    printf("Casamento realizado entre %s (ID %d) e %s (ID %d).\n",
           p1->nome, p1->id, p2->nome, p2->id);
}

void matar_personagem_manual(personagem *lista) {

    int id;
    printf("Digite o ID do personagem que morreu: ");
    scanf("%d", &id);

    personagem *p = buscar_por_id(lista, id);

    if (!p) {
        printf("Personagem nao encontrado.\n");
        return;
    }

    if (p->eh_vivo == 0) {
        printf("Esse personagem ja esta morto.\n");
        return;
    }

    printf("\nPersonagem %s morreu por causas externas.\n", p->nome);

    // aplicar herança
    aplicar_heranca(lista, p);

    // cortar laços
    if (p->id_pupilo != 0) {
        personagem *pup = buscar_por_id(lista, p->id_pupilo);
        if (pup) pup->id_mestre = 0;
    }

    if (p->id_mestre != 0) {
        personagem *m = buscar_por_id(lista, p->id_mestre);
        if (m) m->id_pupilo = 0;
    }

    if (p->conjuge_id != -1) {
        personagem *c = buscar_por_id(lista, p->conjuge_id);
        if (c) c->conjuge_id = -1;

        p->conjuge_id = -1;
    }

    // 🔥 apenas marca como morto
    p->eh_vivo = 0;

    printf("Personagem marcado como morto (historico preservado).\n");
}

//salva as informações dos personagens em um .txt
void salvar_personagens_txt(personagem *lista) {

    if (lista == NULL) {
        printf("Nenhum personagem para salvar.\n");
        return;
    }

    FILE *arq = fopen("personagens.txt", "w");
    if (!arq) {
        printf("Erro ao criar arquivo.\n");
        return;
    }

    fprintf(arq, "===== LISTA DE PERSONAGENS VIVOS =====\n\n");

    personagem *p = lista;

    while (p != NULL) {

        if (p->eh_vivo == 0) {  // 🔥 IGNORA MORTOS
            p = p->prox;
            continue;
        }

        fprintf(arq, "ID: %d | Nome: %s %s | Idade: %d | Talento: %d | Classe: %s | Est.luta: %s(%d)\n",
                p->id, p->nome, p->sobrenome, p->idade, p->talento, p->classe, nome_estilo(p->estilo_de_luta), p->destreza);

        fprintf(arq, "Atributos -> Poder Fisico: %d | Carisma: %d | Tatica: %d | Adm: %d | Conhecimento: %d\n",
                p->poder_fisico, p->carisma, p->tatica_militar,
                p->administracao, p->conhecimento);

        fprintf(arq, "Recursos -> Dinheiro: %d | Seguidores: %d\n",
                p->dinheiro, p->seguidores);

        fprintf(arq, "Relacoes -> Pai: %s %s| Mae: %s %s| Mestre: %s | Pupilo: %s\n",
                buscar_nome_por_id(lista, p->id_pai),
                buscar_sobrenome_por_id(lista, p->id_pai),
                buscar_nome_por_id(lista, p->id_mae),
                buscar_sobrenome_por_id(lista, p->id_mae),
                buscar_nome_por_id(lista, p->id_mestre),
                buscar_nome_por_id(lista, p->id_pupilo));

        fprintf(arq, "Tracos -> ");

        int primeiro = 1;

        if (p->principal != TRACO_NENHUM) {
            fprintf(arq, "%s", nome_traco(p->principal));
            primeiro = 0;
        }

        if (p->traco2 != TRACO_NENHUM) {
            if (!primeiro) fprintf(arq, "; ");
            fprintf(arq, "%s", nome_traco(p->traco2));
            primeiro = 0;
        }

        if (p->traco3 != TRACO_NENHUM) {
            if (!primeiro) fprintf(arq, "; ");
            fprintf(arq, "%s", nome_traco(p->traco3));
        }

        if(p->nivel_intelecto != 0) fprintf(arq, "%s", txt_intelecto(p->nivel_intelecto));
        if(p->nivel_beleza != 0) fprintf(arq, "%s", txt_beleza(p->nivel_beleza));
        if(p->eh_gigante) fprintf(arq, " > Gigante");
        if(p->eh_anao) fprintf(arq, " > Anao");
        if(p->lepra) fprintf(arq, " > Leproso");
        if(p->cancer) fprintf(arq," > Cancer" );
        if(p->imortal) fprintf(arq," > Imortal");
        if(p->iluminado) fprintf(arq," > Iluminado");

        fprintf(arq, "\n");
        fprintf(arq, "-----------------------------\n");

        p = p->prox;
    }

    fclose(arq);
}

void salvar_governantes_txt(personagem *lista) {

    FILE *f = fopen("governantes.txt", "w");
    if (!f) {
        printf("Erro ao criar arquivo.\n");
        return;
    }

    personagem *p = lista;

    while (p != NULL) {

        if (p->eh_vivo == 1 &&
    (strcmp(p->classe, "Rei") == 0 ||
     strcmp(p->classe, "Duque") == 0)) {

            fprintf(f, "ID: %d | Nome: %s | Idade: %d | Talento: %d | ",
                    p->id, p->nome, p->idade, p->talento);

            fprintf(f, "Classe: %s(%d) | ",
                    p->classe,
                    p->territorio);

            fprintf(f, "Est.luta: %s(%d)\n",
                    nome_estilo(p->estilo_de_luta),
                    p->destreza);

            fprintf(f, "Atributos -> Poder Fisico: %d | Carisma: %d | Tatica: %d | Adm: %d | Conhecimento: %d\n",
                    p->poder_fisico,
                    p->carisma,
                    p->tatica_militar,
                    p->administracao,
                    p->conhecimento);

            fprintf(f, "Recursos -> Dinheiro: %d | Seguidores: %d\n",
                    p->dinheiro,
                    p->seguidores);

            fprintf(f, "Relacoes -> Pai: %s | Mae: %s | Mestre: %s | Pupilo: %s\n",
                    (p->id_pai != -1) ? "Conhecido" : "Desconhecido",
                    (p->id_mae != -1) ? "Conhecido" : "Desconhecido",
                    (p->id_mestre != -1) ? "Conhecido" : "Inexistente",
                    (p->id_pupilo != -1) ? "Conhecido" : "Inexistente");

            fprintf(f, "Tracos -> %s, %s, %s\n",
                    nome_traco(p->principal),
                    nome_traco(p->traco2),
                    nome_traco(p->traco3));

            fprintf(f, "--------------------------------------------------\n");
        }

        p = p->prox;
    }

    fclose(f);
}


void salvar_mortos_txt(personagem *lista) {

    FILE *arq = fopen("mortos.txt", "w");
    if (!arq) return;

    fprintf(arq, "===== LISTA DE PERSONAGENS MORTOS =====\n\n");

    personagem *p = lista;

    while (p != NULL) {

        if (p->eh_vivo == 1) {  // 🔥 IGNORA VIVOS
            p = p->prox;
            continue;
        }

        fprintf(arq, "ID: %d | Nome: %s %s | Idade da Morte: %d | Classe: %s\n",
                p->id, p->nome, p->sobrenome, p->idade, p->classe);

        fprintf(arq, "Atributos Finais -> Poder Fisico: %d | Carisma: %d | Tatica: %d | Adm: %d | Conhecimento: %d\n",
                p->poder_fisico_maximo,
                p->carisma,
                p->tatica_militar,
                p->administracao,
                p->conhecimento);

        fprintf(arq, "Recursos Finais -> Dinheiro: %d | Seguidores: %d\n",
                p->dinheiro, p->seguidores);

        fprintf(arq, "-----------------------------\n");

        p = p->prox;
    }

    fclose(arq);
}
//
void imprimir_descendentes(FILE *arq, personagem *lista, int id_pai, int nivel, int familia_id) {

    personagem *p = lista;

    while (p != NULL) {

        if ((p->id_pai == id_pai || p->id_mae == id_pai) &&
            p->familia_id == familia_id) {

            /* Indentação */
            for (int i = 0; i < nivel; i++) {
                fprintf(arq, "    ");
            }

            fprintf(arq,
                    "└── %s %s (ID:%d) [%s]\n",
                    p->nome,
                    p->sobrenome,
                    p->id,
                    p->eh_vivo ? "VIVO" : "X");

            /* Recursão */
            imprimir_descendentes(arq,
                                  lista,
                                  p->id,
                                  nivel + 1,
                                  familia_id);
        }

        p = p->prox;
    }
}

//Gera a arvore genealogica
void gerar_arvore_genealogica(FILE *arq, personagem *lista, int familia_id) {
    personagem *p = lista;
    personagem *fundador = NULL;

    fprintf(arq, "\n===== ARVORE GENEALOGICA =====\n\n");

    /* ========================= */
    /*        FUNDADOR           */
    /* ========================= */

    while (p != NULL) {
        if (p->familia_id == familia_id &&
            p->fundador_familia == 1) {

            fundador = p;
            break;
        }
        p = p->prox;
    }

    if (fundador != NULL) {

        fprintf(arq,
                "%s %s (ID:%d) [%s]\n",
                fundador->nome,
                fundador->sobrenome,
                fundador->id,
                fundador->eh_vivo ? "VIVO" : "FALECIDO");

        imprimir_descendentes(arq,
                              lista,
                              fundador->id,
                              1,
                              familia_id);
    }

    /* ========================= */
    /*     RAMOS SECUNDARIOS     */
    /* ========================= */

    p = lista;
    int tem_secundario = 0;

    while (p != NULL) {

        if (p->familia_id == familia_id &&
            p->fundador_familia == 0 &&
            p->id_pai == -1 &&
            p->id_mae == -1) {

            fprintf(arq, "\n");

            fprintf(arq,
                    "%s %s (ID:%d) [%s]  [RAMO SECUNDARIO]\n",
                    p->nome,
                    p->sobrenome,
                    p->id,
                    p->eh_vivo ? "VIVO" : "FALECIDO");

            imprimir_descendentes(arq,
                                  lista,
                                  p->id,
                                  1,
                                  familia_id);

            tem_secundario = 1;
        }

        p = p->prox;
    }

    if (!tem_secundario) {
        fprintf(arq, "\nNenhum ramo secundario.\n");
    }

    fprintf(arq, "\n");
}
//salva as familias em um .txt
void gerar_relatorios_familias(familia *lista_f, personagem *lista_p) {

    if (lista_f == NULL) {
        return;
    }

    familia *f_atual = lista_f;

    while (f_atual != NULL) {

        char nome_arquivo[60];
        sprintf(nome_arquivo, "familia_%s.txt", f_atual->nome);

        FILE *arq = fopen(nome_arquivo, "w");
        if (arq == NULL) {
            printf("Erro ao criar arquivo da familia %s.\n", f_atual->nome);
            f_atual = f_atual->prox;
            continue;
        }

        fprintf(arq, "===== FAMILIA %s (ID: %d) =====\n\n", 
                f_atual->nome, f_atual->id);

        personagem *p_atual = lista_p;

        int vivos = 0;
        int mortos = 0;

        /* ========================= */
        /*         VIVOS             */
        /* ========================= */

        fprintf(arq, "---- MEMBROS VIVOS ----\n\n");

        while (p_atual != NULL) {

            if (p_atual->familia_id == f_atual->id &&
                p_atual->eh_vivo == 1) {

                fprintf(arq, "ID: %d | Nome: %s %s | Idade: %d | Talento: %d | Classe: %s\n",
                        p_atual->id, p_atual->nome, p_atual->sobrenome,
                        p_atual->idade, p_atual->talento, p_atual->classe);

                fprintf(arq, "Atributos -> Poder Fisico: %d | Carisma: %d | Tatica: %d | Adm: %d | Conhecimento: %d\n",
                        p_atual->poder_fisico, p_atual->carisma,
                        p_atual->tatica_militar, p_atual->administracao,
                        p_atual->conhecimento);

                fprintf(arq, "Recursos -> Dinheiro: %d | Seguidores: %d\n",
                        p_atual->dinheiro, p_atual->seguidores);

                fprintf(arq, "Relacoes -> Pai: %s %s | Mae: %s %s | Mestre: %s | Pupilo: %s\n",
                        buscar_nome_por_id(lista_p, p_atual->id_pai),
                        buscar_sobrenome_por_id(lista_p, p_atual->id_pai),
                        buscar_nome_por_id(lista_p, p_atual->id_mae),
                        buscar_sobrenome_por_id(lista_p, p_atual->id_mae),
                        buscar_nome_por_id(lista_p, p_atual->id_mestre),
                        buscar_nome_por_id(lista_p, p_atual->id_pupilo));

                fprintf(arq, "Tracos -> ");

                int primeiro = 1;

                if (p_atual->principal != TRACO_NENHUM) {
                    fprintf(arq, "%s", nome_traco(p_atual->principal));
                    primeiro = 0;
                }

                if (p_atual->traco2 != TRACO_NENHUM) {
                    if (!primeiro) fprintf(arq, "; ");
                    fprintf(arq, "%s", nome_traco(p_atual->traco2));
                    primeiro = 0;
                }

                if (p_atual->traco3 != TRACO_NENHUM) {
                    if (!primeiro) fprintf(arq, "; ");
                    fprintf(arq, "%s", nome_traco(p_atual->traco3));
                }

                if (p_atual->nivel_intelecto != 0)
                    fprintf(arq, "%s", txt_intelecto(p_atual->nivel_intelecto));

                if (p_atual->nivel_beleza != 0)
                    fprintf(arq, "%s", txt_beleza(p_atual->nivel_beleza));

                if (p_atual->eh_gigante)
                    fprintf(arq, " > Gigante");

                if (p_atual->eh_anao)
                    fprintf(arq, " > Anao");

                if (p_atual->lepra)
                    fprintf(arq, " > Leproso");

                if (p_atual->cancer)
                    fprintf(arq, " > Cancer");

                if (p_atual->fundador_familia == 1)
                    fprintf(arq, " [FUNDADOR DA LINHAGEM]");

                fprintf(arq, "\n");
                fprintf(arq, "------------------------------------------\n");

                vivos++;
            }

            p_atual = p_atual->prox;
        }

        if (vivos == 0) {
            fprintf(arq, "Nenhum membro vivo encontrado.\n");
        }


        /* ========================= */
        /*     ARVORE GENEALOGICA    */
        /* ========================= */

        gerar_arvore_genealogica(arq, lista_p, f_atual->id);

        /* ========================= */
        /*         MORTOS            */
        /* ========================= */

        p_atual = lista_p;

        fprintf(arq, "\n---- MEMBROS FALECIDOS ----\n\n");

        while (p_atual != NULL) {

            if (p_atual->familia_id == f_atual->id &&
                p_atual->eh_vivo == 0) {

                fprintf(arq,
                        "ID: %d | Nome: %s %s | Idade da Morte: %d\n",
                        p_atual->id,
                        p_atual->nome,
                        p_atual->sobrenome,
                        p_atual->idade);

                if (p_atual->fundador_familia == 1) {
                    fprintf(arq, " [FUNDADOR DA LINHAGEM]\n");
                }

                fprintf(arq, "------------------------------------------\n");
                mortos++;
            }

            p_atual = p_atual->prox;
        }

        if (mortos == 0) {
            fprintf(arq, "Nenhum membro falecido registrado.\n");
        }

        /* ========================= */
        /*       RESUMO FINAL        */
        /* ========================= */

        fprintf(arq,
                "\nResumo da Familia %s:\nVivos: %d\nMortos: %d\nTotal: %d\n",
                f_atual->nome,
                vivos,
                mortos,
                vivos + mortos);

        fclose(arq);

        f_atual = f_atual->prox;
    }
}

//Carrega os nomes para serem dados aleatoriamente
void carregar_nomes(const char *arquivo, char nomes[][TAM_NOME], int *total) {
    FILE *f = fopen(arquivo, "r");
    if (!f) {
        printf("Erro ao abrir %s\n", arquivo);
        return;
    }

    while (fgets(nomes[*total], TAM_NOME, f)) {
        nomes[*total][strcspn(nomes[*total], "\n")] = '\0'; // remove \n
        (*total)++;
    }

    fclose(f);
}

void gerar_nome_aleatorio(int sexo, char *destino) {
    if (sexo == 1) { // masculino
        int i = rand() % total_masculinos;
        strcpy(destino, nomes_masculinos[i]);
    } else { // feminino
        int i = rand() % total_femininos;
        strcpy(destino, nomes_femininos[i]);
    }
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

    printf("\n 1-Masculino\n 2-Feminino\nSexo: ");
    scanf(" %d", &novo->sexo);

    novo->eh_player = 1;
    novo->eh_vivo = 1;

    // valores automáticos
    novo->sobrenome[0] = '\0';
    novo->idade = 0;
    novo->talento = rand()%5 + 1;        // 1–5
    novo->poder_fisico = rand()%5 + 1;   // 1–5
    novo->poder_fisico_maximo = novo->poder_fisico;
    novo->destreza = 0;
    novo->estilo_de_luta = ESTILO_NENHUM;

    // iniciar demais atributos
    novo->potencial_evolucao = 0;
    novo->carisma = 0;
    novo->tatica_militar = 0;
    novo->administracao = 0;
    novo->conhecimento = 0;
    novo->fertilidade = 0;
    novo->dinheiro = 0;
    novo->seguidores = 0;
    novo->id_mestre = 0;
    novo->id_pupilo = 0;
    novo->territorio = 0;
    strcpy(novo->classe, "Comum");
    novo->conjuge_id = -1;
    novo->id_pai = -1;
    novo->id_mae = -1;
    novo->principal = TRACO_NENHUM;
    novo->traco2 = TRACO_NENHUM;
    novo->traco3 = TRACO_NENHUM;
    novo->nivel_intelecto = sortear_intelecto_inicial();
    novo->nivel_beleza = sortear_beleza_inicial();
    novo->eh_gigante = (rand() % 150 == 0);
    novo->eh_anao = novo->eh_gigante ? 0 : (rand() % 150 == 0);
    novo->iluminado = 0;
    novo->imortal = 0;
    novo->lepra = 0;
    novo->cancer = 0;
    aplicar_status_nascimento(novo);

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
personagem* cadastrar_filho_auto(personagem *lista, familia *lista_f, personagem *primario, int sexo) {

    personagem *novo = malloc(sizeof(personagem));
    if (!novo) return lista;

    novo->id = PROX_ID++;

    //atribuir familia auto,aticamente 1
    personagem *secundario = NULL;

    if(primario->conjuge_id != -1) secundario = buscar_por_id(lista, primario->conjuge_id);

    //atribuir familia automaticamente 2
    if (primario->conjuge_id == -1 || primario->sexo == 1) novo->familia_id = primario->familia_id;
    else novo->familia_id = secundario->familia_id;

    familia *f_origem = buscar_familia_id(lista_f, novo->familia_id);
    if (f_origem != NULL) {
        strcpy(novo->sobrenome, f_origem->nome);
    } else {
        strcpy(novo->sobrenome, "");
    }

    // ---------------- NOME DO FILHO ----------------

    if (primario->eh_player == 1) {

        if (sexo == 1) {
            if (primario->conjuge_id == -1)
                printf("Digite o nome do filho de %s %s: ", primario->nome, primario->sobrenome);
            else
                printf("Digite o nome do filho de %s %s junto com %s %s: ",
                    primario->nome, primario->sobrenome, secundario->nome, secundario->sobrenome);
        } else {
            if (primario->conjuge_id == -1)
                printf("Digite o nome da filha de %s %s: ", primario->nome, primario->sobrenome);
            else
                printf("Digite o nome da filha de %s %s junto com %s %s: ",
                    primario->nome, primario->sobrenome, secundario->nome, secundario->sobrenome);
        }

        scanf("%49s", novo->nome);

    } else {

        // GERA NOME AUTOMÁTICO
        gerar_nome_auto(sexo, novo->nome);

    }

    // VERIFICA REPETIÇÃO NA FAMÍLIA
    int repeticoes = contar_nome_familia(lista, novo->familia_id, novo->nome);

    if (repeticoes > 0) {
        char romano[10];
        numero_para_romano(repeticoes + 1, romano);

        strcat(novo->nome, "");
        strcat(novo->nome, romano);
    }


    // atribuir pais
    novo->id_pai = ANONIMO;
    novo->id_mae = ANONIMO;

    if (secundario != NULL) {
        // existe casal
        if (primario->sexo == 1) { // primario é pai
            novo->id_pai = primario->id;
            novo->id_mae = secundario->id;
        } else { // primario é mãe
            novo->id_mae = primario->id;
            novo->id_pai = secundario->id;
        }
    } else {
        // pai ou mãe solo
        if (primario->sexo == 1)
            novo->id_pai = primario->id;
        else
            novo->id_mae = primario->id;
    }


    novo->eh_player = 0;
    novo->eh_vivo = 1;
    novo->idade = 0;
    novo->sexo = sexo;
    novo->talento = rand()%5 + 1;
    novo->poder_fisico = rand()%5 + 1;
    novo->poder_fisico_maximo = novo->poder_fisico;
    novo->destreza = 0;
    novo->estilo_de_luta = ESTILO_NENHUM;

    novo->potencial_evolucao = 0;
    novo->carisma = 0;
    novo->tatica_militar = 0;
    novo->administracao = 0;
    novo->conhecimento = 0;
    novo->fertilidade = 0;
    novo->dinheiro = 0;
    novo->seguidores = 0;
    novo->id_mestre = 0;
    novo->id_pupilo = 0;
    novo->conjuge_id = -1;
    novo->territorio = 0;
    strcpy(novo->classe, "Comum");
    novo->principal = TRACO_NENHUM;
    novo->traco2 = TRACO_NENHUM;
    novo->traco3 = TRACO_NENHUM;
    novo->iluminado = 0;
    novo->imortal = 0;
    novo->lepra = 0;
    novo->cancer = 0;

    // Dentro de cadastrar_filho_auto(personagem *lista, int id_pai, int id_mae)
    personagem *pai = buscar_por_id(lista, novo->id_pai);
    personagem *mae = buscar_por_id(lista, novo->id_mae);

    // ... (alocação do novo personagem) ...

    // GENÉTICA HERDÁVEL
    novo->nivel_intelecto = calcular_heranca_solo_ou_dupla(pai, mae, 'I');
    novo->nivel_beleza    = calcular_heranca_solo_ou_dupla(pai, mae, 'B');

    // FÍSICO
    int p_gig = pai ? pai->eh_gigante : 0;
    int m_gig = mae ? mae->eh_gigante : 0;
    novo->eh_gigante = herdar_binario_solo(p_gig, m_gig, 150, (pai!=NULL), (mae!=NULL));

    if (!novo->eh_gigante) {
        int p_an = pai ? pai->eh_anao : 0;
        int m_an = mae ? mae->eh_anao : 0;
        novo->eh_anao = herdar_binario_solo(p_an, m_an, 150, (pai!=NULL), (mae!=NULL));
    } else {
        novo->eh_anao = 0;
    }

    // APLICAR MUDANÇAS DE STATUS (Obrigatório chamar aqui)
    aplicar_status_nascimento(novo);
    //-----------------------------------------

    novo->prox = NULL;

    printf("%s %s teve um filho(a): %s %s\n", primario->nome, primario->sobrenome, novo->nome, novo->sobrenome);

    salvar_personagens_txt(lista);

    novo->prox = NULL;
    return novo;
    
}
//atribui uma nova classe ao personagem
void atribuir_player(personagem *lista){
    int id;

    printf("Digite o ID do personagem: ");
    scanf("%d", &id);

    personagem *p = buscar_por_id(lista, id);

    if (!p || p->eh_vivo==0) {
        printf("Personagem não encontrado.\n");
        return;
    }

    p->eh_player=1;
    printf("%s %s se torna um Player\n", p->nome, p->sobrenome);

}

void atribuir_classe(personagem *lista) {

    int id;
    int op;

    printf("Digite o ID do personagem: ");
    scanf("%d", &id);

    personagem *p = buscar_por_id(lista, id);

    if (!p || p->eh_vivo==0) {
        printf("Personagem não encontrado.\n");
        return;
    }

    printf("\nClasse atual: %s\n", p->classe);
    printf("1 - Rei\n");
    printf("2 - Duque\n");
    printf("3 - Comum\n");
    printf("Escolha: ");
    scanf("%d", &op);

    p->territorio = 1;

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

familia* atribuir_familia(personagem *lista_p, familia *lista_f) {
    int id, op;
    printf("\n1 - Fundar nova Familia\n2 - Adicionar a Familia existente\nEscolha: ");
    scanf("%d", &op);

    printf("Digite o ID do personagem: ");
    scanf("%d", &id);
    personagem *p = buscar_por_id(lista_p, id);

    if (!p || p->eh_vivo==0) {
        printf("Personagem nao encontrado.\n");
        return lista_f;
    }

    if (op == 1) { // Fundar
        familia *nova = calloc(1, sizeof(familia));
        nova->id = ID_LEGADO++;
        nova->fundador_id = p->id;
        
        printf("Digite o Sobrenome da Familia: ");
        scanf(" %49s", nova->nome);
        
        p->familia_id = nova->id;
        p->fundador_familia = 1;
        strcpy(p->sobrenome, nova->nome); // O personagem ganha o sobrenome

        nova->prox = lista_f;
        printf("Familia %s fundada por %s!\n", nova->nome, p->nome);
        return nova;
    } 
    else if (op == 2) { // Adicionar
        int fam_id;
        printf("Digite o ID da Familia: ");
        scanf("%d", &fam_id);
        familia *f = buscar_familia_id(lista_f, fam_id);
        
        if (f) {
            p->familia_id = f->id;
            strcpy(p->sobrenome, f->nome);
            printf("%s agora pertence a familia %s\n", p->nome, f->nome);
        } else {
            printf("Familia nao encontrada.\n");
        }
    }
    return lista_f;
}

void atribuir_mestre(personagem *lista){
    int mestre;
    int aluno;

    printf("Digite o ID do pupilo: ");
    scanf("%d", &aluno);

    printf("Digite o ID do mestre: ");
    scanf("%d", &mestre);

    if (aluno == mestre) {
        printf("Erro: um personagem não pode ensinar a si mesmo.\n");
        return;
    }

    personagem *p = buscar_por_id(lista, aluno);
    personagem *m = buscar_por_id(lista, mestre);

    if (!p || p->eh_vivo==0 || m->eh_vivo==0 || !m) {
        printf("Personagem não encontrado.\n");
        return;
    }

    if (p->id_mestre != 0 || m->id_pupilo != 0) {
        printf("Erro: um dos personagens já tem mestre/pupilo.\n");
        return;
    }

    p->id_mestre=m->id;
    m->id_pupilo=p->id;

    printf("%s se torna mestre de %s", m->nome, p->nome);
}

void atribuir_estilo_de_luta(personagem *lista, personagem *p) {

    if (p->idade != 7)
        return;

    if (p->destreza != 0)
        return; // já foi atribuída

    personagem *mestre = NULL;

    if (p->id_mestre != -1)
        mestre = buscar_por_id(lista, p->id_mestre);

    /* ============================== */
    /* SE TEM MESTRE -> HERDA */
    /* ============================== */

    if (mestre != NULL && mestre->eh_vivo == 1) {

        p->estilo_de_luta = mestre->estilo_de_luta;

        printf("%s herdou o estilo de luta do mestre %s!\n",
               p->nome, mestre->nome);

        return;
    }

    /* ============================== */
    /* SEM MESTRE -> GERA ALEATORIO */
    /* ============================== */

    p->destreza = (rand() % 5) + p->talento;  
    // talento influencia

    if (p->destreza > 10)
        p->destreza = 10;

    p->estilo_de_luta = sortear_estilo_de_luta();

}

//atualizar o personagem quando o ano passa
personagem* atualizar_personagens(personagem *lista, familia *lista_f){

    personagem *p = lista;
    personagem *novos = NULL;

    while(p != NULL){

        // 🔥 IGNORA MORTOS
        if(p->eh_vivo == 0){
            p = p->prox;
            continue;
        }

        p->idade += 1;

        // aplicar personalidade
        if(p->idade == 3)
            p->principal = sortear_traco_principal();
        if(p->idade == 5)
            p->traco2 = sortear_traco_secundario();
        if(p->idade == 7){
            atribuir_estilo_de_luta(lista, p);
            p->traco3 = sortear_traco_secundario();
        }

        aplicar_tracos_anuais(p);

        int i_i = indice_idade(p->idade);
        p->potencial_evolucao = p->talento + i_i;

        // bonus de beleza
        if(p->nivel_beleza != 0 && p->nivel_beleza != 1){
            if (p->nivel_beleza == 4) p->fertilidade += 7;
            if (p->nivel_beleza == 3) p->fertilidade += 4;
            if (p->nivel_beleza == 2) p->fertilidade += 2;
            if (p->nivel_beleza == -1) p->fertilidade -= 2;
            if (p->nivel_beleza == -2) p->fertilidade -= 5;
        }

        // filhos
        if(p->idade > 16){
            p->fertilidade = rand() % 20 + 1;
            p->fertilidade += i_i;

            int sexo = rand() % 2 + 1;

            if(p->fertilidade > 22){

                if(sexo == 1 && p->eh_player==1)
                    printf("%s %s teve um filho\n", p->nome, p->sobrenome);
                else if(sexo == 2 && p->eh_player==1)
                    printf("%s %s teve uma filha\n", p->nome, p->sobrenome);

                personagem *filho = cadastrar_filho_auto(lista, lista_f, p, sexo);

                if(filho){
                    filho->prox = novos;
                    novos = filho;
                }
            }
        }

        // buff de mestre (apenas se mestre estiver vivo)
        if(p->id_mestre != 0){

            personagem *m = buscar_por_id(lista, p->id_mestre);

            if(m && m->eh_vivo == 1){

                int mod = 10;

                if(m->conhecimento > 150) mod = 1;
                else if(m->conhecimento > 100) mod = 2;
                else if(m->conhecimento > 80) mod = 3;
                else if(m->conhecimento > 60) mod = 5;
                else if(m->conhecimento > 40) mod = 7;

                if(rand()%mod==0) p->poder_fisico += 1;
                if(rand()%mod==0) p->carisma += 1;
                if(rand()%mod==0) p->tatica_militar += 1;
                if(rand()%mod==0) p->administracao += 1;
                if(rand()%mod==0) p->conhecimento += 1;
                if(rand()%mod==0) p->destreza += 1;

                if(p->estilo_de_luta==m->estilo_de_luta) p->destreza++;
            }
        }

        // evolução poder físico
        int p_f = rand() % 40 + 20;
        p_f += p->potencial_evolucao;

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

        //destreza
        int des = rand() % 22 + 1 + p->potencial_evolucao;
        if(des<7 && p->idade>7) p->destreza-=1;
        if(des>18 && p->idade>7) p->destreza+=1;
        if(des>24 && p->idade>7) p->destreza+=2;
        if(des>28 && p->idade>7) p->destreza+=3;

        // experiência
        int car = rand() % 20 + 1 + p->potencial_evolucao;
        if(car>18) p->carisma+=1;
        if(car>24) p->carisma+=2;
        if(car>28) p->carisma+=3;

        int t_m = rand() % 20 + 1 + p->potencial_evolucao;
        if(t_m>18) p->tatica_militar+=1;
        if(t_m>24) p->tatica_militar+=2;
        if(t_m>28) p->tatica_militar+=3;

        int adm = rand() % 20 + 1 + p->potencial_evolucao;
        if(adm>18) p->administracao+=1;
        if(adm>24) p->administracao+=2;
        if(adm>28) p->administracao+=3;

        int con = rand() % 20 + 1 + p->potencial_evolucao;
        if(con>18) p->conhecimento+=1;
        if(con>24) p->conhecimento+=2;
        if(con>28) p->conhecimento+=3;

        // recursos
        p->dinheiro += ganho_dinheiro_anual(p);
        p->seguidores += ganho_seguidores_anual(p);

        eventos_anuais(p);

        if(p->poder_fisico > p->poder_fisico_maximo)
            p->poder_fisico_maximo = p->poder_fisico;

        if(p->poder_fisico<=0 && p->idade<=5) p->poder_fisico = 1;
        // 🔥 MORTE
        if(p->poder_fisico <= 0){

            printf(";-; %s %s morreu aos %d anos!\n", p->nome, p->sobrenome, p->idade);

            aplicar_heranca(lista, p);
            p->eh_vivo = 0;

            // limpar relações
            if(p->id_pupilo != 0){
                personagem *pup = buscar_por_id(lista, p->id_pupilo);
                if(pup) pup->id_mestre = 0;
            }

            if(p->id_mestre != 0){
                personagem *m = buscar_por_id(lista, p->id_mestre);
                if(m) m->id_pupilo = 0;
            }

            if(p->conjuge_id != -1){
                personagem *c = buscar_por_id(lista, p->conjuge_id);
                if(c) c->conjuge_id = -1;
                p->conjuge_id = -1;
            }
        }

        p = p->prox;
    }

    // adiciona filhos ao final
    if(novos){
        personagem *fim = lista;
        while(fim && fim->prox)
            fim = fim->prox;

        if(fim)
            fim->prox = novos;
        else
            lista = novos;
    }

    return lista;
}
