//
// Created by laura on 12/03/20.
//


#include "Camada_dados.h"
#include <stdlib.h>

// AS ÚNICAS FUNÇÕES QUE ALTERAM O ESTADO SÃO AQUI;


//Esta função deverá criar um estado vazio (com o tabuleiro inicializado)
ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int j, i;
    for ( i = 0; i < 8; i++){
        for ( j = 0; j < 8; j++){
            if ( i == 3 && j == 4) e->tab[i][j] =  BRANCA;
            else if ( i == 7 && j == 0) e->tab[i][j] = UM;
            else if (i == 0 && j == 7) e->tab[i][j] = DOIS;
            else e->tab[i][j] = VAZIO;
        }
    }
    COORDENADA coordenada_inicial = {4,4};
    e->ultima_jogada = coordenada_inicial;
    COORDENADA jog1 = {4,4};
    JOGADA jogada1 = {jog1};
    e->jogadas[0] = jogada1;
    e->num_jogadas = 0;
    e->jogador_atual = 1;
    e->num_movimentos = 0;
    return e;
};

//Esta função permite obter o número do jogador atual
int obter_jogador_atual(ESTADO *estado){
    return (estado->jogador_atual);
}


//Esta função permite obter quantas jogadas foram efetuadas (cada jogada tem o movimento de dois jogadores).
int obter_numero_de_jogadas(ESTADO *estado){
    return (estado->num_jogadas);
}

//Esta função permite obter o estado atual da casa. Nota: esta função recebe as coordenadas no format "linha,coluna"
CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int i = c.coluna;
    int j = c.linha;
    CASA final = (e-> tab[i][j]);
    return final;
}

//Esta função deve aceder ao estado e returnar a ultima jogada;
COORDENADA obter_ultima_jogada (ESTADO *estado){
    COORDENADA ultima;
    ultima = estado->ultima_jogada;
    return ultima;
}

int obter_num_mov (ESTADO *e){
    return e->num_movimentos;
}

void faz_primeira_jogada (ESTADO *e){
    altera_numjogadas(e);
    altera_jogadoratual(e);
    altera_num_mov(e);
}

void altera_tabuleiro (ESTADO *estado, COORDENADA c){
    estado->tab[7-(c.linha)][c.coluna] = BRANCA;
    estado->tab[7-(estado->ultima_jogada).linha][(estado->ultima_jogada).coluna]=PRETA;
}

void altera_ultimajogada (ESTADO *e, COORDENADA c){
    e->ultima_jogada = c;
}

void altera_jogadas (ESTADO *e, COORDENADA c){
    int i = (e->num_jogadas);
    JOGADA jog1;
    if (e->jogador_atual == 1){
        jog1.jogador1 = c;
    }
    else jog1.jogador2 = c;
    e->jogadas[i] = jog1;
}

void altera_numjogadas (ESTADO *e){
    if ( e -> jogador_atual == 1) e->num_jogadas += 1;
}

void altera_jogadoratual(ESTADO *e){
    if (e->jogador_atual == 1) e->jogador_atual = 2;
    else e->jogador_atual = 1;
}

void altera_num_mov (ESTADO *e){
    e->num_movimentos++;
}

void altera_estado (ESTADO *e, COORDENADA c){
    altera_tabuleiro(e, c);
    altera_ultimajogada(e,c);
    altera_jogadas(e, c);
    altera_numjogadas(e);
    altera_jogadoratual(e);
    altera_num_mov(e);
}
