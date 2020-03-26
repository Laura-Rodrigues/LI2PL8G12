//
// Created by laura on 26/03/20.
//

#include "Funcoes_Ficheiro.h"
#include "Camada_Interface.h"
#include "Camada_dados.h"
#include <bits/types/FILE.h>

void fptabuleiro(FILE *Projeto_Rastos, ESTADO *e){
    for (int i = 0; i < 8; i++) {
        fprintf(Projeto_Rastos, "%c ", '8' - i );
        for (int j = 0; j < 8; j++) {
            COORDENADA c = {i,j};
            if (obter_estado_casa(e,c) == DOIS) fprintf(Projeto_Rastos, "2 ");
            else if (obter_estado_casa(e ,c) == UM) fprintf(Projeto_Rastos, "1 ");
            else if (obter_estado_casa(e ,c) == VAZIO) fprintf(Projeto_Rastos, ". ");
            else if (obter_estado_casa(e ,c) == PRETA) fprintf(Projeto_Rastos, "# ");
            else if (obter_estado_casa(e ,c) == BRANCA) fprintf(Projeto_Rastos, "* ");
        }
        fprintf(Projeto_Rastos, "\n");
    }
    fprintf(Projeto_Rastos, "  ");
    for(int i = 0; i < 8; i++) {
        fprintf(Projeto_Rastos, "%c ", 'a' + i);
    };
    fprintf(Projeto_Rastos, "\n");
}


int gr(FILE *Projeto_Rastos, ESTADO *e){
    FILE *fp = fopen("Projeto_Rastos", "w");
    if(fp==NULL){
        fclose(fp);
        return 0;
    } else {
        fptabuleiro(fp,e);
        fclose(fp);
    }
    return 1;
}

int ler(FILE *Projeto_Rastos){
    FILE *fp = fopen("Projeto_Rastos", "r");
    int c;
    while((c = fgetc(fp)) != EOF){
        printf("%c", c);
    }
    return 1;
}


