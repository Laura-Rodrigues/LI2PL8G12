//
// Created by laura on 23/04/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "Bot.h"
#include "funcoes_aux.h"

/*
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
*/

int det_dist(COORDENADA c, int nj){
    int cc = c.coluna, cl = c.linha, total;
    if( nj == 1){
        total = cc+cl;
    } else {
        total = abs(cc-7) + abs(cl-7);
    }
    return total;
}

COORDENADA dist_euclidiana ( ESTADO *e, LISTA L){
    COORDENADA melhor, c;
    int menor = 32, dist, jogador = obter_jogador_atual(e);
    LISTA Temp;
    for ( Temp = L; !lista_esta_vazia(proximo(Temp)); Temp = remove_cabeca(Temp)){
        c = *(COORDENADA *) devolve_cabeca(Temp);
        dist = det_dist(c, jogador);
        if ( dist < menor ){
            menor = dist;
            melhor = c;
        }
    }
    return melhor;
}

int vitoria (ESTADO *e, COORDENADA C){
    int r = 0, j = obter_jogador_atual(e);
    if (j == 1 && C.coluna == 0 && C.linha == 0) r = 1;
    else if ( j == 2 && C.coluna == 7 && C.linha == 7) r = 1;
    else if ( vizivalide(e, C) >= 7){
        r = 1;
    }
    return r;
}

int derrota (ESTADO *e, COORDENADA c){
    int r = 0, j = obter_jogador_atual(e);
    if (j == 2 && c.coluna == 0 && c.linha == 0) r = 1;
    else if ( j == 1 && c.coluna == 7 && c.linha == 7) r = 1;
    return r;
}


LISTA remove_opcoes (ESTADO *e, LISTA l){
    LISTA T  = l, FINAL = criar_lista();
    int i, falha = 0;
    COORDENADA *c, f, ls[8] ;
    while (!lista_esta_vazia(proximo(T))){
        c = (COORDENADA *) devolve_cabeca(T);
        f = *c;
        coordvizinho(ls, f);
        for ( i = 0; i < 8; i++) {
            if (possivel(e, ls[i]) && !(cond_canto(ls[i]))) {
                if (vitoria ( e, ls[i]))
                    falha = 1;
            }
        }
        if ( falha == 1){
            printf("Removendo: %c%d \n", (c->coluna)+'a', c->linha+1);
            falha = 0;
        }
        else{
            FINAL = insere_cabeca(FINAL, c);
        }
        T = remove_cabeca(T);
    }
    return FINAL;
}


COORDENADA heuristica (ESTADO *e) {
    int i;
    COORDENADA c, ls[8], coord = obter_ultima_jogada(e);
    coordvizinho(ls, coord);
    LISTA L = criar_lista();
    for ( i = 0; i < 8; i++){
        if (possivel(e, ls[i]) && !(cond_canto(ls[i])) ) {
            if ( vitoria ( e, ls[i] ))
                return ls[i];
            if ( !(derrota (e , ls[i])) ){
                L = insere_cabeca(L, ls+i);
            }
        }
    }
    if ( len_Lista(L) == 1 ) c = *(COORDENADA *)devolve_cabeca(L);
    else {
        L = remove_opcoes(e,L);
        if ( len_Lista(L) > 1 ) c = dist_euclidiana ( e, L );
        else  c = * (COORDENADA *)devolve_cabeca(L);
    }
    return c;
}

COORDENADA jog2 ( ESTADO *e ) {
    COORDENADA c = heuristica(e);
    printf("A jogada recomendada é: %c%d. \n", c.coluna + 'a', c.linha + 1);
    return c;
}

//receber o estado do tabuleiro, analisar as jogadas possíveis,
// aplicar uma heurística para escolher a melhor jogada e
// jogar nessa jogada, devolvendo o tabuleiro atualizado.
COORDENADA bot (ESTADO *e){
    COORDENADA c;
    c = jog2 (e);
    jogar(e, c);
    return c;
}