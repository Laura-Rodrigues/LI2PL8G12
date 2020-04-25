//
// Created by laura on 25/04/20.
//

#include "funcoes_aux.h"

#include <stdlib.h>
#include "Bot.h"
#include "funcoes_aux.h"

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
    e->jogadas[0].jogador2 = jog1;
    e->num_jogadas = 0;
    e->jogador_atual = 2;
    e->num_movimentos = 0;
    e->alt_pos = 0;
    return e;
}

//Esta função permite obter o número do jogador atual
int obter_jogador_atual(ESTADO *estado){
    return (estado->jogador_atual);
}


//Esta função permite obter quantas jogadas foram efetuadas (cada jogada tem o movimento de dois jogadores).
int obter_numero_de_jogadas(ESTADO *estado){
    return (estado->num_jogadas);
}

//Função que troca a coluna pela linha e vice-versa
COORDENADA troca_ordem (COORDENADA c){
    COORDENADA final = {7-c.linha, c.coluna};
    return final;
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

COORDENADA obter_jogada (ESTADO *e, int njogada, int jogador){
    COORDENADA r;
    JOGADA jogada = e-> jogadas [njogada];
    if ( jogador == 1) r = jogada.jogador1;
    else r = jogada.jogador2;
    return r;
}

int obter_pos (ESTADO *e){
    return e->alt_pos;
}

void aumenta_pos (ESTADO* e, int i){
    e->alt_pos = i + 1;
}

void faz_primeira_jogada (ESTADO *e){
    altera_numjogadas(e);
    altera_jogadoratual(e);
    altera_num_mov(e);
}

void altera_pos (ESTADO* e){
    e->alt_pos = 0;
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
    if (e->jogador_atual == 1){
        e->jogadas[i].jogador1 = c;
    }
    else {
        e->jogadas[i].jogador2 = c;
    }
}


void altera_numjogadas (ESTADO *e){
    if ( e -> jogador_atual == 2) e->num_jogadas += 1;
}

void altera_jogadoratual(ESTADO *e){
    if (e->jogador_atual == 1) e->jogador_atual = 2;
    else e->jogador_atual = 1;
}

void altera_num_mov (ESTADO *e){
    e->num_movimentos++;
}

void altera_estado (ESTADO *e, COORDENADA c){
    altera_pos(e);
    altera_tabuleiro(e, c);
    altera_ultimajogada(e,c);
    altera_jogadas(e, c);
    altera_numjogadas(e);
    altera_jogadoratual(e);
    altera_num_mov(e);
}

int vizinha(ESTADO *e, COORDENADA c){
    COORDENADA ultjogada = obter_ultima_jogada(e);
    int r=0;
    if (ultjogada.coluna == c.coluna && ultjogada.linha == c.linha) return r;
    if (abs(c.linha - ultjogada.linha) <= 1) {
        if (abs(c.coluna - ultjogada.coluna) <= 1)
            r = 1;
    }
    return r;
}

int jogada_valida (ESTADO *estado, COORDENADA c){
    COORDENADA final = troca_ordem (c);
    CASA j = (obter_estado_casa(estado,final));
    if((j == VAZIO || j == UM ||j == DOIS) && vizinha(estado, c))
        return 1;
    else return 0;
}


void coordvizinho(ESTADO *e, COORDENADA ls[]) {
    COORDENADA c = obter_ultima_jogada(e), c0;
    int i, j, ind = 0;
    for (i = -1; i <= 1; i++)
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0);
            else {
                c0.coluna = c.coluna + i;
                c0.linha = c.linha + j;
                ls[ind] = c0;
                ind++;
            }
        }
}

LISTA criar_lista(){
    LISTA lista;
    lista = malloc (sizeof(Nodo));
    lista->prox = NULL;
    return lista;
}

LISTA insere_cabeca(LISTA L, COORDENADA *valor){
    LISTA lista = criar_lista();
    lista->valor = valor;
    lista->prox = L;
    return lista;
}

void *devolve_cabeca(LISTA L){
    COORDENADA *c;
    if(L == NULL) c = NULL;
    else c = L->valor;
    return c;
}

int det_dist(COORDENADA c, int nj){
    int cc = c.coluna, cl = c.linha, total;
    if( nj == 1){
        total = cc+cl;
    } else {
        total = abs(cc-7) + abs(cl-7);
    }
    return total;
}

int cond_canto (COORDENADA c) {
    if (c.coluna > 7 || c.linha > 7 || c.coluna < 0 || c.linha < 0) return 1;
    else return 0;
}