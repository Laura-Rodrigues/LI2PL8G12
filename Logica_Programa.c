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

//Função que troca a coluna pela linha e vice-versa
COORDENADA troca_ordem (COORDENADA c){
    COORDENADA final = {7-c.linha, c.coluna};
    return final;
}

//Testa se a Jogada é válida
int jogada_valida (ESTADO *estado, COORDENADA c){
    COORDENADA final = troca_ordem (c);
    if((obter_estado_casa(estado,final) == VAZIO) && vizinha(estado, c))
        return 1;
    else return 0;
}
//Testar se tem vizinhos validos
int vizivalide(ESTADO *e, COORDENADA c){
    COORDENADA c0 = {c.coluna +1,c.linha +1};
    COORDENADA c1 = {c.coluna +1,c.linha };
    COORDENADA c2 = {c.coluna +1,c.linha -1};
    COORDENADA c3 = {c.coluna ,c.linha +1};
    COORDENADA c4 = {c.coluna +1,c.linha -1};
    COORDENADA c5 = {c.coluna -1,c.linha +1};
    COORDENADA c6 = {c.coluna -1,c.linha};
    COORDENADA c7 = {c.coluna -1,c.linha -1};
    COORDENADA arr[8] = {c0,c1,c2,c3,c4,c5,c6,c7};
    int r = 0, resultado = 0;
    for (int i = 0; i < 8; i++){
        if (obter_estado_casa(e, troca_ordem(arr[i])) == PRETA ) r++;
    }
    printf("%d \n", r);
    if ( r == 8 ) resultado = 1;
    return resultado;
}

//Testa se a Coordenada é igual á final
int fim(ESTADO *e, COORDENADA c){
    if ((c.coluna) == 0 && (c.linha)== 0){
        return 1;
    } else if((c.coluna) == 7 && (c.linha) == 7){
        return 2;
    }if (vizivalide(e)){
        return 3;
    } else return 0;
}

int jogar(ESTADO *estado, COORDENADA c){
    int resultado;
    if (jogada_valida(estado,c)){
        altera_estado(estado,c);
    }
    resultado = fim(estado,c);
    return resultado;
}
