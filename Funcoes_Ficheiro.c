//
// Created by laura on 26/03/20.
//

#include "Funcoes_Ficheiro.h"
#include "Camada_Interface.h"
#include "Camada_dados.h"
#include <stdio.h>

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


ESTADO *ler(char nomeficheiro[], ESTADO *e){
    FILE *fp = fopen(nomeficheiro, "r+");
    char s[BUF_SIZE];
    int jog = 0;
    int j ,l;
    char i,k;
    e = inicializar_estado();
    faz_primeira_jogada(e);
    while ((fgets(s, BUF_SIZE, fp)) != NULL){
        if (sscanf( s, "0%d: %c%d %c%d", &jog, &i,&j, &k, &l)){
            COORDENADA c0 = {i- 'a', j-1};
            COORDENADA c1 = {k -'a' , l -1};
            if ( jog != 0 && jogada_valida(e, c0))
                altera_estado(e, c0);
            if (jog != 0 && jogada_valida(e, c1))
                altera_estado(e, c1);
        }
    }
    fclose ( fp );
    return e;
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
    int m = obter_num_mov(e), i = obter_pos(e);
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
    aumenta_pos(e, i);
    mostrar_tabuleiro(e);
    movs(e);
    e -> num_movimentos = m+obter_pos(e);
    return e;
}

LISTA listvizinho(ESTADO *e, COORDENADA c){
    LISTA l = criar_lista();
    COORDENADA c0 = {c.coluna +1,c.linha +1};
    COORDENADA c1 = {c.coluna +1,c.linha };
    COORDENADA c2 = {c.coluna +1,c.linha -1};
    COORDENADA c3 = {c.coluna ,c.linha +1};
    COORDENADA c4 = {c.coluna +1,c.linha -1};
    COORDENADA c5 = {c.coluna -1,c.linha +1};
    COORDENADA c6 = {c.coluna -1,c.linha};
    COORDENADA c7 = {c.coluna -1,c.linha -1};
    COORDENADA ls[8] = {c0,c1,c2,c3,c4,c5,c6,c7};
    for(int i = 0; i < 8; i++){
        if(obter_estado_casa(e,ls[i]) == VAZIO)
            insere_cabeca(l,ls[i]);
    }
    return l;
}

int *distcasa(int nj, COORDENADA c){
    int cc = c.coluna, cl = c.linha;
    int cd = 0, ld = 0;
    if( nj == 1){
        while(cl != 0){
            cd++;
            cl--;
        }
        while(cc != 0){
            ld++;
            cc--;
        }
    } else {
        while(cl != 7){
            cd++;
            cl++;
        }
        while(cc != 7){
            ld++;
            cc++;
        }
    }
    int arr[2] = {cc,cl};
    return arr;
}


