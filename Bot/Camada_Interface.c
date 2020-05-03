//
// Created by laura on 01/05/20.
//

#include <stdio.h>
#include "Camada_dados.h"



// Função que permite mostrar o tabuleiro;
void mostrar_tabuleiro ( ESTADO *estado ){
    for ( int i = 0; i < 8; i++ ) {
        printf( "%c ", '8' - i );
        for ( int j = 0; j < 8; j++ ) {
            COORDENADA coord = {i,j};
            if ( obter_estado_casa(estado, coord ) == DOIS) printf("2 " );
            else if ( obter_estado_casa(estado, coord ) == UM) printf("1 " );
            else if ( obter_estado_casa(estado, coord ) == VAZIO) printf(". " );
            else if ( obter_estado_casa(estado, coord ) == PRETA) printf("# " );
            else if ( obter_estado_casa(estado, coord ) == BRANCA) printf("* " );
        }
        printf( "\n" );
    }
    printf( "  " );
    for ( int i = 0; i < 8; i++ ) {
        printf( "%c ", 'a' + i );
    }
    printf( "\n" );
}

int movs ( ESTADO *estado ) {
    char col1, col2;
    int ind, lin1, lin2, jogada = obter_numero_de_jogadas( estado ), jogador = obter_jogador_atual( estado );
    COORDENADA jog1, jog2;
    if ( jogador == 1 ) jogada--;
    for ( ind = 1; ind <= jogada ; ind++ ) {
        jog1 = obter_jogada( estado, ind, 1 );
        jog2 = obter_jogada( estado, ind, 2 );
        col1 = jog1.coluna + 'a';
        lin1 = jog1.linha + 1;
        col2 = jog2.coluna + 'a';
        lin2 = jog2.linha + 1;
        if ( ind < jogada )
            printf( "%02d: %c%d %c%d \n", ind, col1, lin1, col2, lin2 );
        else {
            if ( jogador == 2)
                printf( "%02d: %c%d \n", ind , col1, lin1 );
            else
                printf( "%02d: %c%d %c%d \n", ind, col1, lin1, col2, lin2 );
        }
    }
    return 0;
}
