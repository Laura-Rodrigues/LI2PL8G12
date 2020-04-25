//
// Created by laura on 23/04/20.
//


#include <stdio.h>
#include <bits/types/FILE.h>
#include "Bot.h"
#include "funcoes_aux.h"
#define BUF_SIZE 1024

void fptabuleiro(FILE *Projeto_Rastros, ESTADO *e){
    for (int i = 0; i < 8; i++) {
        fprintf(Projeto_Rastros, "%c ", '8' - i );
        for (int j = 0; j < 8; j++) {
            COORDENADA c = {i,j};
            if (obter_estado_casa(e,c) == DOIS) fprintf(Projeto_Rastros, "2 ");
            else if (obter_estado_casa(e ,c) == UM) fprintf(Projeto_Rastros, "1 ");
            else if (obter_estado_casa(e ,c) == VAZIO) fprintf(Projeto_Rastros, ". ");
            else if (obter_estado_casa(e ,c) == PRETA) fprintf(Projeto_Rastros, "# ");
            else if (obter_estado_casa(e ,c) == BRANCA) fprintf(Projeto_Rastros, "* ");
        }
        fprintf(Projeto_Rastros, "\n");
    }
    fprintf(Projeto_Rastros, "  ");
    for(int i = 0; i < 8; i++) {
        fprintf(Projeto_Rastros, "%c ", 'a' + i);
    };
    fprintf(Projeto_Rastros, "\n");
}

int movsficheiro (ESTADO *e, FILE *nome) {
    char c1, c2;
    int i, l1, l2;
    int jogada = obter_numero_de_jogadas(e), jogador = obter_jogador_atual(e);
    if ( jogador == 1) jogada--;
    for ( i = 1; i <= jogada ; i++) {
        COORDENADA jog1 = obter_jogada(e, i, 1);
        c1 = jog1.coluna + 'a';
        l1 = jog1.linha + 1;
        COORDENADA jog2 = obter_jogada(e, i, 2);
        c2 = jog2.coluna + 'a';
        l2 = jog2.linha + 1;
        if (i < jogada) {
            fprintf(nome,"%02d: %c%d %c%d \n", i, c1, l1, c2, l2);
        } else {
            if ( jogador == 2)
                fprintf(nome,"%02d: %c%d \n", i, c1, l1);
            else
                fprintf(nome,"%02d: %c%d %c%d \n", i, c1, l1, c2, l2);
        }
    }
    return 0;
}

int gr( char nomeficheiro[], ESTADO *e){
    FILE *fp = fopen(nomeficheiro, "w");
    if(fp==NULL){
        fclose(fp);
        return 0;
    } else {
        fptabuleiro(fp,e);
        movsficheiro (e, fp);
        fclose(fp);
    }
    return 1;
}


ESTADO *ler(char nomeficheiro[], ESTADO *e){
    FILE *fp = fopen(nomeficheiro, "r+");
    char s[BUF_SIZE];
    int jog = 0;
    int j ,l;
    char i,k;
    e = inicializar_estado();
    faz_primeira_jogada(e);
    while ((fgets(s, BUF_SIZE, fp)) != NULL){
        if (sscanf( s, "0%d: %c%d %c%d", &jog, &i,&j, &k, &l)){
            COORDENADA c0 = {i- 'a', j-1};
            COORDENADA c1 = {k -'a' , l -1};
            if ( jog != 0 && jogada_valida(e, c0))
                altera_estado(e, c0);
            if (jog != 0 && jogada_valida(e, c1))
                altera_estado(e, c1);
        }
    }
    fclose ( fp );
    return e;
}

int jogar(ESTADO *estado, COORDENADA c){
    int resultado = 0 , r = 0;
    if (jogada_valida(estado,c)){
        r = 1;
        altera_estado(estado,c);
        resultado = fim(estado,c);
    }
    if (r == 0)
        resultado = 3;
    return resultado;
}

COORDENADA jog ( ESTADO *e ){
    COORDENADA ls[8], *c, t;
    coordvizinho(e, ls);
    LISTA L = criar_lista();
    int i, j = obter_jogador_atual(e), max = 32, dist;
    for ( i = 0; i < 8 ; i++) {
        if (jogada_valida(e, ls[i]) && !(cond_canto(ls[i]))) {
            dist = det_dist(ls[i], j);
            if (dist < max) {
                max = dist;
                t = ls[i];
            } else
                L = insere_cabeca(L, ls + i);
        }
    }
    L = insere_cabeca(L, &t);
    c = (COORDENADA *) devolve_cabeca(L);
    printf("A jogada recomendada é: %c%d. \n", c->coluna+'a', c->linha+1);
    return *c;
}

//receber o estado do tabuleiro, analisar as jogadas possíveis,
// aplicar uma heurística para escolher a melhor jogada e
// jogar nessa jogada, devolvendo o tabuleiro atualizado.
COORDENADA bot (ESTADO *e){
    jog (e);
}