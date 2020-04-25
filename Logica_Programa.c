//
// Created by laura on 12/03/20.
//

#include "Camada_dados.h"
#include <stdio.h>
#include <stdlib.h>

/* Esta função deverá receber o estado atual e uma coordenada e modificar o estado ao jogar na casa correta se a jogada for válida.
 * A função devolve verdadeiro (valor diferente de zero) se for possível jogar e falso (zero) caso não seja possível.*/


// Testa se a Coordenada é vizinha da Coordenada anterior e se encontra-se dentro do tabuleiro
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

int possivel ( ESTADO *e, COORDENADA c){
    int r = 0;
    COORDENADA f = troca_ordem(c);
    if ( obter_estado_casa(e,f) != PRETA && obter_estado_casa(e,f) != BRANCA ) r = 1;
    return r;
}

//Testa se a Jogada é válida
int jogada_valida (ESTADO *estado, COORDENADA c){
    if ( possivel(estado,c) && vizinha(estado, c) )
        return 1;
    else return 0;
}

// Função que determina se a coordenada se encontra fora do tabuleiro
int cond_canto (COORDENADA c) {
    if (c.coluna > 7 || c.linha > 7 || c.coluna < 0 || c.linha < 0) return 1;
    else return 0;
}

void coordvizinho(ESTADO *e, COORDENADA ls[], COORDENADA c) {
    COORDENADA c0;
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

//Testar se tem vizinhos validos
int vizivalide(ESTADO *e, COORDENADA c){
    int r = 0;
    COORDENADA arr[8];
    coordvizinho(e, arr, c);
    for (int i = 0; i < 8; i++){
        if (obter_estado_casa(e, troca_ordem(arr[i])) == PRETA || cond_canto (arr[i])) r++;
    }
    return r;
}

int fim(ESTADO *e, COORDENADA c){
    int r = 0;
    if ((c.coluna) == 0 && (c.linha)== 0)
        r = 1;
    else if ( (c.coluna) == 7 && (c.linha) == 7 )
        r = 2;
    else if ( vizivalide(e,c) == 8 ){
        int i = obter_jogador_atual(e);
        if ( i == 1) r = 2;
        else r = 1;
    }
    return r;
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
