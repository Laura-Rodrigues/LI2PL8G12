//
// Created by laura on 01/05/20.
//

#include "Camada_dados.h"
#include <stdlib.h>

//Esta função deverá criar um estado vazio (com o tabuleiro inicializado)
ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int j, i;
    for ( i = 0; i < 8; i++){
        for ( j = 0; j < 8; j++){
            if      ( i == 3 && j == 4 ) e -> tab[i][j] =  BRANCA;
            else if ( i == 7 && j == 0 ) e -> tab[i][j] = UM;
            else if ( i == 0 && j == 7 ) e -> tab[i][j] = DOIS;
            else e -> tab[i][j] = VAZIO;
        }
    }
    COORDENADA coord_inicial = {4,4};
    e -> ultima_jogada = coord_inicial;
    COORDENADA jog1 = {4,4};
    e -> jogadas[0].jogador2 = jog1;
    e -> num_jogadas = 0;
    e -> jogador_atual = 2;
    e -> num_movimentos = 0;
    return e;
}

//Esta função permite obter o número do jogador atual
int obter_jogador_atual( ESTADO *estado ){
    return ( estado -> jogador_atual );
}

//Esta função permite obter quantas jogadas foram efetuadas (cada jogada tem o movimento de dois jogadores).
int obter_numero_de_jogadas( ESTADO *estado ){
    return ( estado -> num_jogadas );
}

//Função que troca a coluna pela linha e vice-versa
COORDENADA troca_ordem ( COORDENADA coord ){
    COORDENADA final = {7-coord.linha, coord.coluna};
    return final;
}

//Esta função permite obter o estado atual da casa. Nota: esta função recebe as coordenadas no format "linha,coluna"
CASA obter_estado_casa( ESTADO *estado, COORDENADA coord ){
    int col = coord.coluna, lin = coord.linha;
    CASA final = ( estado -> tab[col][lin] );
    return final;
}

//Esta função deve aceder ao estado e returnar a ultima jogada;
COORDENADA obter_ultima_jogada ( ESTADO *estado ){
    COORDENADA ultima;
    ultima = estado -> ultima_jogada;
    return ultima;
}

int obter_num_mov ( ESTADO *estado ){
    return estado -> num_movimentos;
}

COORDENADA obter_jogada ( ESTADO *estado, int njogada, int jogador ){
    COORDENADA result;
    JOGADA jogada = estado -> jogadas [njogada];
    if ( jogador == 1 ) result = jogada.jogador1;
    else result = jogada.jogador2;
    return result;
}


void altera_tabuleiro ( ESTADO *estado, COORDENADA coord ){
    estado -> tab[ 7 - (coord.linha) ][ coord.coluna ] = BRANCA;
    estado -> tab[ 7 - (estado->ultima_jogada).linha ][ (estado->ultima_jogada).coluna ] = PRETA;
}

void altera_ultimajogada ( ESTADO *estado, COORDENADA coord ){
    estado -> ultima_jogada = coord;
}

void altera_jogadas ( ESTADO *estado, COORDENADA coord ){
    int ind = ( estado -> num_jogadas);
    if ( estado -> jogador_atual == 1 )
        estado -> jogadas[ind].jogador1 = coord;
    else
        estado -> jogadas[ind].jogador2 = coord;
}

void altera_numjogadas ( ESTADO *estado ){
    if ( estado -> jogador_atual == 2 ) estado -> num_jogadas ++;
}

void altera_jogadoratual( ESTADO *estado ){
    if ( estado -> jogador_atual == 1 ) estado -> jogador_atual = 2;
    else estado -> jogador_atual = 1;
}

void altera_num_mov ( ESTADO *estado, int n_mov ){
    estado -> num_movimentos = n_mov;
}

void faz_primeira_jogada ( ESTADO *estado ){
    altera_numjogadas( estado );
    altera_jogadoratual( estado );
    altera_num_mov( estado, 1 );
}

void altera_estado (ESTADO *estado, COORDENADA coord){
    int n_mov_atual = obter_num_mov( estado ) +1;
    altera_tabuleiro( estado, coord );
    altera_ultimajogada( estado, coord );
    altera_jogadas( estado, coord );
    altera_numjogadas( estado );
    altera_jogadoratual( estado );
    altera_num_mov( estado, n_mov_atual );
}
