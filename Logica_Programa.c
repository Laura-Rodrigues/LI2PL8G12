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
    int r;
    if (abs(c.linha - ultjogada.linha) <= 1) {
        if (abs(c.coluna - ultjogada.coluna) <= 1)
                r = 1;
        }
        else r = 0;
    return r;
}


//Testa se a Jogada é válida
int jogada_valida (ESTADO *estado, COORDENADA c){
    if((obter_estado_casa(estado,c) == VAZIO) && vizinha(estado, c))
        return 1;
    else return 0;
}

//Testa se a Coordenada é igual á final
int fim(COORDENADA c){
    if ((c.coluna) == 7 && (c.linha)== 0){
        printf("Jogador número 1, Ganhou!!!!");
        return 1;
    } else if((c.coluna) == 0 && (c.linha) == 7){
        printf("Jogador número 2, Ganhou!!!");
        return 1;
    }
    else return 0;
}


int jogar(ESTADO *estado, COORDENADA c){
    if (jogada_valida(estado,c)){
        altera_tabuleiro(estado, c, BRANCA);
        altera_tabuleiro(estado, obter_ultima_jogada(estado), PRETA);
    }
    if(fim (c)){
        return 1;
    }
    return 0;
}

