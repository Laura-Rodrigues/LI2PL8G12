//
// Created by laura on 12/03/20.
//

#include "Logica_Programa.h"
#include "Definiçoes.h"
#include <stdio.h>

/* Esta função deverá receber o estado atual e uma coordenada e modificar o estado ao jogar na casa correta se a jogada for válida.
 * A função devolve verdadeiro (valor diferente de zero) se for possível jogar e falso (zero) caso não seja possível.*/

int jogada_valida (ESTADO *estado, COORDENADA c){
    //função que retorna 1 ou 0 dependendo se for ou não válida
}

int jogar(ESTADO *estado, COORDENADA c){
    if (jogada_valida(estado,c)){
        estado -> tab[c.linha][c.coluna] = BRANCA;
        printf("jogar %d %d\n", c.coluna, c.linha);
    }
    return 1;
}