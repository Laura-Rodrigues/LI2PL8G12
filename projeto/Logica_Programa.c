//
// Created by laura on 12/03/20.
//

#include "Camada_dados.h"
#include <stdio.h>
#include <stdlib.h>

// Testa se a Coordenada é vizinha da Coordenada anterior e se encontra-se dentro do tabuleiro
int e_vizinha( ESTADO *estado, COORDENADA coord){
    COORDENADA ultjogada = obter_ultima_jogada(estado);
    int resultado=0;
    if (abs(coord.linha - ultjogada.linha) <= 1) {
        if (abs(coord.coluna - ultjogada.coluna) <= 1)
                resultado = 1;
        }
    return resultado;
}

int possivel ( ESTADO *estado, COORDENADA coord ){
    int result = 0;
    COORDENADA nova = troca_ordem( coord );
    if ( obter_estado_casa( estado,nova ) != PRETA && obter_estado_casa( estado,nova ) != BRANCA ) result = 1;
    return result;
}

//Testa se a Jogada é válida
int jogada_valida ( ESTADO *estado, COORDENADA coord ){
    if ( possivel( estado,coord ) && e_vizinha( estado, coord ) )
        return 1;
    else return 0;
}

// Função que determina se a coordenada se encontra fora do tabuleiro
int cond_canto ( COORDENADA coord ) {
    if ( coord.coluna > 7 || coord.linha > 7 || coord.coluna < 0 || coord.linha < 0 )
        return 1;
    else return 0;
}

void coordvizinho(COORDENADA arr[], COORDENADA coord) {
    COORDENADA coord_aux;
    int i, j, ind = 0;
    for ( i = -1; i <= 1; i++ )
        for ( j = -1; j <= 1; j++ ) {
            if ( i == 0 && j == 0 );
            else {
                coord_aux.coluna = coord.coluna + i;
                coord_aux.linha = coord.linha + j;
                arr[ind] = coord_aux;
                ind++;
            }
        }
}

//Testar se tem vizinhos validos
int vizivalide( ESTADO *estado, COORDENADA coord ){
    int result = 0, ind;
    COORDENADA arr[8];
    coordvizinho( arr, coord );
    for (ind = 0; ind < 8; ind++){
        if ( obter_estado_casa( estado, troca_ordem( arr[ind] ) ) == PRETA || cond_canto ( arr[ind] ) )
            result++;
    }
    return result;
}

//Testa se a Coordenada é igual á final
int fim( ESTADO *estado, COORDENADA coord ){
    int result = 0, jogador = obter_jogador_atual( estado );
    if ( ( coord.coluna ) == 0 && ( coord.linha ) == 0 )
        result = 1;
    else if ( ( coord.coluna ) == 7 && ( coord.linha ) == 7 )
        result = 2;
    else if ( vizivalide( estado, coord ) == 8 ){
        if ( jogador == 1 ) result = 2;
        else result = 1;
    }
    return result;
}

int jogar( ESTADO *estado, COORDENADA coord ){
    int resultado = 0 , aux = 0;
    if (jogada_valida( estado,coord )){
        aux = 1;
        altera_estado( estado,coord );
        resultado = fim( estado,coord );
    }
    if (aux == 0) resultado = 3;
    return resultado;
}
