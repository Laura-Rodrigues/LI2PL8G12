//
// Created by laura on 23/04/20.
//

#include "Bot.h"
#include "Camada_dados.h"
#include "Logica_Programa.h"
#include "Funcoes_Ficheiro.h"

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

//receber o estado do tabuleiro, analisar as jogadas possíveis,
// aplicar uma heurística para escolher a melhor jogada e
// jogar nessa jogada, devolvendo o tabuleiro atualizado.
int bot (ESTADO *e){
    COORDENADA c;
    c = jog (e);
    jogar(e, c);
    return 0;
}
