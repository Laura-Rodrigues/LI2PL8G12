//
// Created by laura on 12/03/20.
//

#ifndef PROJETORASTROS_CAMADA_INTERFACE_H
#define PROJETORASTROS_CAMADA_INTERFACE_H

typedef enum {VAZIO, BRANCA, PRETA} CASA;

typedef struct {
    int coluna;
    int linha;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tab[8][8]; //tab- armazena informação sobre o tabuleiro
    COORDENADA ultima_jogada; //ultima_jogada- a coordenada da ultima jogada
    JOGADAS jogadas; //jogadas - armazena informação sobre as jogadas
    int num_jogadas; //num_jogadas - indica quantas jogadas foram efetuadas
    int jogador_atual; //jogador_atual - indica qual é o jogador a jogar
} ESTADO;


void mostrar_tabuleiro(ESTADO estado){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 0 && j == 7) printf("2 ");
            else if (i == 7 && j == 0) printf("1 ");
            else if (((&estado) -> tab [i][j]) == VAZIO) printf(". ");
            else if (((&estado) -> tab [i][j]) == PRETA) printf("# ");
            else if (((&estado) -> tab [i][j]) == BRANCA) printf("* ");
        }
        printf("\n");
    }
}

#endif //PROJETORASTROS_CAMADA_INTERFACE_H
