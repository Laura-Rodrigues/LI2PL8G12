//
// Created by laura on 26/03/20.
//

#include "Funcoes_Ficheiro.h"
#include "Camada_Interface.h"
#include "Camada_dados.h"
#include <bits/types/FILE.h>

void fptabuleiro(FILE *Projeto_Rastros, ESTADO *e){
    for (int i = 0; i < 8; i++) {
        fprintf(Projeto_Rastros, "%c ", '8' - i );
        for (int j = 0; j < 8; j++) {
            COORDENADA c = {i,j};
            if (obter_estado_casa(e,c) == DOIS) fprintf(Projeto_Rastros, "2 ");
            else if (obter_estado_casa(e ,c) == UM) fprintf(Projeto_Rastros, "1 ");
            else if (obter_estado_casa(e ,c) == VAZIO) fprintf(Projeto_Rastros, ". ");
            else if (obter_estado_casa(e ,c) == PRETA) fprintf(Projeto_Rastros, "# ");
            else if (obter_estado_casa(e ,c) == BRANCA) fprintf(Projeto_Rastros, "* ");
        }
        fprintf(Projeto_Rastros, "\n");
    }
    fprintf(Projeto_Rastros, "  ");
    for(int i = 0; i < 8; i++) {
        fprintf(Projeto_Rastros, "%c ", 'a' + i);
    };
    fprintf(Projeto_Rastros, "\n");
}

int movsficheiro (ESTADO *e, FILE *nome) {
    char c1, c2;
    int i, l1, l2;
    int jogada = obter_numero_de_jogadas(e);
    int mov = obter_num_mov(e);
    for ( i = 0; i <= jogada && mov > 0; i++) {
        if ( i == 0) {
            fprintf(nome,"00: e5 \n");
            mov--;
        }
        else {
            COORDENADA jog1 = obter_jogada(e, i, 1);
            c1 = jog1.coluna + 'a';
            l1 = jog1.linha + 1;
            COORDENADA jog2 = obter_jogada(e, i, 2);
            c2 = jog2.coluna + 'a';
            l2 = jog2.linha + 1;
            if (mov < 2 && mov %2 != 0){
                fprintf(nome,"%02d: %c%d \n", i, c1, l1);
            }
            else{
                fprintf(nome,"%02d: %c%d %c%d \n", i, c1, l1, c2, l2);
                mov -= 2;
            }
        }

    }
    return 0;
}

int gr( char nomeficheiro[], ESTADO *e){
    FILE *fp = fopen(nomeficheiro, "w");
    if(fp==NULL){
        fclose(fp);
        return 0;
    } else {
        fptabuleiro(fp,e);
        movsficheiro (e, fp);
        fclose(fp);
    }
    return 1;
}

int ler(char nomeficheiro[], ESTADO *e){
    FILE *fp = fopen(nomeficheiro, "r");
    int c;
    while((c = fgetc(fp)) != EOF){
        printf("%c", c);
        for(int i = 0; i < 8; i++){
            for(int j = 1; j < 9; j++){
                COORDENADA co = {j,i};
                if(c == '.') (e-> tab[7-i][j]) = VAZIO;
                else if(c == '#') (e-> tab[7-i][j]) = PRETA;
                else if(c == '*') {
                    (e-> tab[7-i][j]) = BRANCA;
                    (e-> ultima_jogada) = co;
                }
                else if(c == '1') (e-> tab[7-i][j]) = UM;
                else if(c == '2') (e-> tab[7-i][j]) = DOIS;
            }
        }
    }
    return 1;
}

int movs (ESTADO *e) {
    char c1, c2;
    int i, l1, l2;
    int jogada = obter_numero_de_jogadas(e);
    int mov = obter_num_mov(e);
    for ( i = 0; i <= jogada && mov > 0; i++) {
        if ( i == 0) {
            printf("00: e5 \n");
            mov--;
        }
        else {
            COORDENADA jog1 = obter_jogada(e, i, 1);
            c1 = jog1.coluna + 'a';
            l1 = jog1.linha + 1;
            COORDENADA jog2 = obter_jogada(e, i, 2);
            c2 = jog2.coluna + 'a';
            l2 = jog2.linha + 1;
            if ( mov < 2 && mov % 2 != 0)
                printf("%02d: %c%d \n", i , c1, l1);
            else
                {
                printf("%02d: %c%d %c%d \n", i, c1, l1, c2, l2);
                mov -= 2;
            }
        }
    }
    return 0;
}

ESTADO* pos (ESTADO *e, int dado){
    int m = obter_num_mov(e);
    JOGADAS t;
    for (int i = 1;i <= dado; i++) {
        t[i].jogador1 = obter_jogada(e, i, 1);
        t[i].jogador2 = obter_jogada(e, i, 2);
    }
    e = inicializar_estado();
    faz_primeira_jogada(e);
    for (int i = 1;i <= dado; i++){
        COORDENADA c1 = t[i].jogador1;
        altera_estado(e,c1);
        COORDENADA c2 = t[i].jogador2;
        altera_estado(e,c2);
    }
    mostrar_tabuleiro(e);
    movs(e);
    e -> num_movimentos = m+1;
    e -> alt_pos = 1;
    return e;
}


