//
// Created by laura on 12/03/20.
//

#include "Camada_Interface.h"
#include "Camada_dados.h"
#include <stdlib.h>

// AS ÚNICAS FUNÇÕES QUE ALTERAM O ESTADO SÃO AQUI;


//Esta função deverá criar um estado vazio (com o tabuleiro inicializado)
ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int j, i;
    for ( i = 0; i < 8; i++){
        for ( j = 0; j < 8; j++){
            if ( i == 4 && j == 4) e->tab[i][j] =  BRANCA;
            else if ( i == 7 && j == 0) e->tab[i][j] = UM;
            else if (i == 0 && i == 7) e->tab[i][j] = DOIS;
            else e->tab[i][j] = VAZIO;
        }
    }
    COORDENADA coordenada_inicial = {4,4};
    e->ultima_jogada = coordenada_inicial;
    COORDENADA jog1 = {4,4};
    JOGADA jogada1 = {jog1};
    e->jogadas[0] = jogada1;
    e->num_jogadas = 0;
    e->jogador_atual = 1;
    mostrar_tabuleiro(e);
    return e;
};

//Esta função permite obter o número do jogador atual
int obter_jogador_atual(ESTADO *estado){
    return (estado->jogador_atual);
}


//Esta função permite obter quantas jogadas foram efetuadas (cada jogada tem o movimento de dois jogadores).
int obter_numero_de_jogadas(ESTADO *estado){
    return (estado->num_jogadas);
}

//Esta função permite obter o estado atual da casa.
CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int i = c.coluna;
    int j = c.linha;
    CASA final = (e-> tab[i][j]);
    return final;
}

//Esta função deve aceder ao estado e returnar a ultima jogada;
COORDENADA obter_ultima_jogada (ESTADO *estado){
    COORDENADA ultima;
    ultima = estado->ultima_jogada;
    return ultima;
}