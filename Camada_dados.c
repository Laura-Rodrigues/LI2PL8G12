//
// Created by laura on 12/03/20.
//

#include "Camada_dados.h"

// AS ÚNICAS FUNÇÕES QUE ALTERAM O ESTADO SÃO AQUI;


//Esta função deverá criar um estado vazio (com o tabuleiro inicializado)
ESTADO *inicializar_estado(){
    ESTADO e;
    int j, i;
    for ( i = 0; i < 8; i++){
        for ( j = 0; j < 8; j++){
            if ( i == 4 && j == 4) e.tab[i][j] =  BRANCA;
            else e.tab[i][j] = VAZIO;
        }
    } //tabuleiro
    COORDENADA coordenada_inicial = {4,4};
    e.ultima_jogada = coordenada_inicial;
    COORDENADA jog1 = {3,4};
    COORDENADA jog2 = {3,4};
    JOGADA jogada1 = {jog1,jog2};
    e.jogadas[0] = jogada1;
    e.num_jogadas = 1;
    e.jogador_atual = 2;
    return &e;
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
    CASA final = (e-> tab[j][i]);
    return final;
}