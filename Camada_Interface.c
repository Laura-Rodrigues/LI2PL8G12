//
// Created by laura on 12/03/20.
//

#include <stdio.h>
#include <string.h>
#include "Logica_Programa.h"
#include "Camada_dados.h"
#include "Funcoes_Ficheiro.h"

#define BUF_SIZE 1024

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

void prompt ( ESTADO *estado ){
    int numerojogadas = obter_numero_de_jogadas ( estado );
    int njogador = obter_jogador_atual ( estado );
    int n_mov = obter_num_mov( estado );
    printf ("#%02d PLAYER%d (%d) -> ", n_mov, njogador, numerojogadas );
}

int Resposta ( int resultado ){
    switch ( resultado ){
        case 1:
            {
            printf("O Jogador 1 venceu!" );
            break;
            }
        case 2: 
            {
            printf( "O Jogador 2 venceu!" );
            break;
            }
    }
    return 0;
}

int jogar_coord ( ESTADO *estado, COORDENADA coord ){
    int resultado = jogar( estado, coord ), v_final = 0;
    if ( resultado == 3 ) {
        printf( "Jogada inválida! \n" );
    }
    else
        if ( resultado != 0 ) {
            mostrar_tabuleiro( estado );
            Resposta( resultado );
            v_final = 1;
    }
    return v_final;
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

int interpretador( ESTADO *estado ) {
    char linha[BUF_SIZE], nome_ficheiro[BUF_SIZE], col[2], lin[2];
    int joga, n_pos = obter_pos( estado );
    COORDENADA coord;
    if ( obter_numero_de_jogadas( estado ) == 0 ){
        if ( obter_num_mov( estado ) == 0 ){
            printf( "#00 PLAYER2 (0) -> e5 \n" );
            faz_primeira_jogada( estado );
            mostrar_tabuleiro( estado );
        }
        else faz_primeira_jogada( estado );
    }
    prompt( estado );
    if ( fgets( linha, BUF_SIZE, stdin ) == NULL )
        return 0;
    if ( strlen( linha ) == 3 && sscanf( linha, "%[a-h]%[1-8]", col, lin ) == 2 ) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        joga = jogar_coord ( estado, coord );
        if ( joga == 1 ) return 0;
        mostrar_tabuleiro( estado );
    }
    else if ( strcmp( linha, "Q\n" ) == 0 ) return 0;
    else if ( sscanf( linha, "pos %d", &joga ) ) {
        if ( n_pos != 0 ){
            strcpy(nome_ficheiro, "v_ant_estado");
            estado = ler (nome_ficheiro, estado);
            aumenta_pos(estado, n_pos-1);
        }
        if (joga < 0 || joga >= obter_numero_de_jogadas(estado)) {
            printf("Número de jogada inválido.\n");
        }
        else {
            if (obter_pos( estado ) == 0){
                strcpy(nome_ficheiro, "v_ant_estado");
                gr ( nome_ficheiro, estado );
            }
            estado = pos( estado, joga );
        }
        mostrar_tabuleiro( estado );
        movs( estado );
    }
    else if ( strcmp( linha, "movs\n" ) == 0 )
        movs( estado );
    else if ( strcmp( linha, "jog\n" ) == 0 ){
        coord = jog( estado );
        joga = jogar_coord ( estado, coord );
        if ( joga == 1 ) return 0;
        mostrar_tabuleiro( estado );
    }
    else if ( sscanf( linha, "gr %s", nome_ficheiro ) ) {
        if ( strcmp(nome_ficheiro, "v_ant_estado" ) == 0 )
            printf("Nome inválido. \n");
        else {
            gr( nome_ficheiro, estado );
            printf( "Guardado! \n" );
        }
    }
    else if ( sscanf( linha, "ler %s", nome_ficheiro ) ) {
        estado = ler( nome_ficheiro, estado );
        mostrar_tabuleiro( estado );
        movs( estado );
    }
    else printf("Comando inválido! Tente outra vez!\n");
    interpretador( estado );
    return 1;
}
