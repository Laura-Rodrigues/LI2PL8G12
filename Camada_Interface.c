//
// Created by laura on 12/03/20.
//

#include <stdio.h>
#include "Camada_Interface.h"
#include "Definiçoes.h"

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
