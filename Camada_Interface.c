//
// Created by laura on 12/03/20.
//

#include <stdio.h>
#include "Camada_Interface.h"
#include "Logica_Programa.h"
#include "Definiçoes.h"
#include <string.h>

// Função que permite mostrar o tabuleiro;
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


int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col -'a', *lin -'1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}