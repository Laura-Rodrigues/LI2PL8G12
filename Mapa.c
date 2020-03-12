//
// Created by laura on 06/03/20.
//

#include "Mapa.h"
#include <stdio.h>

int mapa() {
    int coluna, linha;
    for (linha = 0; linha < 9; linha++) {
        if (linha == 8) {
            for(coluna = 0; coluna < 8; coluna++){
                if (coluna == 0) printf(" ");
                printf("%c ", 'A' + coluna);
            }
        }
        else {
            for (coluna = 0; coluna < 9; coluna++) {
                if (coluna == 0){
                    printf("%c ", '8' - linha);
                }
                else if (linha == 0 && coluna == 8) printf("2 ");
                else if (linha == 7 && coluna == 1) printf("1 ");
                else if (linha == 3 && coluna == 5) printf("* ");
                else printf(". ");
            }
        }
        printf("\n");
    }
}

