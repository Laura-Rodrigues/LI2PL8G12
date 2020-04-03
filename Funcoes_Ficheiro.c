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
    for ( i = 0; i < jogada; i++, mov -= 2) {
        COORDENADA jog1 = obter_jogada(e, i, 1);
        c1 = jog1.coluna + 'a';
        l1 = jog1.linha + 1;
        COORDENADA jog2 = obter_jogada(e, i, 2);
        c2 = jog2.coluna + 'a';
        l2 = jog2.linha + 1;
        if (mov < 2 && mov %2 != 0){
            fprintf(nome,"%02d: %c%d \n", i+1, c1, l1);
        }
        else
            fprintf(nome,"%02d: %c%d %c%d \n", i+1, c1, l1, c2, l2);

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
    }
    return 1;
}
int movs (ESTADO *e) {
    char c1, c2;
    int i, l1, l2;
    int jogada = obter_numero_de_jogadas(e);
    int mov = obter_num_mov(e);
    for ( i = 0; i < jogada; i++, mov -= 2) {
        COORDENADA jog1 = obter_jogada(e, i, 1);
        c1 = jog1.coluna + 'a';
        l1 = jog1.linha + 1;
        COORDENADA jog2 = obter_jogada(e, i, 2);
        c2 = jog2.coluna + 'a';
        l2 = jog2.linha + 1;
        if (mov < 2 && mov %2 != 0){
            printf("%02d: %c%d \n", i+1, c1, l1);
        }
        else
            printf("%02d: %c%d %c%d \n", i+1, c1, l1, c2, l2);

    }
    return 0;
}

int pos (ESTADO *e, int dado){
    JOGADAS tmp;
    int i, jogador;
    for (i = 0; i < dado; i++){
        tmp[i].jogador1 = obter_jogada(e,i,1);
        tmp[i].jogador2 = obter_jogada(e,i,2);
    }
    altera_jogadoratual(e);
    jogador = obter_jogador_atual(e);
    e = inicializar_estado();
    for ( i = 0; i < dado; i++) {
        e->jogadas[i] = tmp[i];
    }
    e->num_jogadas = dado;
    e->num_movimentos = 2*dado;
    e->jogador_atual = jogador;
    e->ultima_jogada = tmp[i].jogador2;
    mostrar_tabuleiro(e);
    printf("FEITO");
    return 0;
}
