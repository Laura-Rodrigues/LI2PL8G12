//
// Created by laura on 12/03/20.
//

#include <stdio.h>
#include <string.h>
#include "Logica_Programa.h"
#include "Camada_dados.h"

#define BUF_SIZE 1024

// Função que permite mostrar o tabuleiro;
void mostrar_tabuleiro(ESTADO *estado){
    for (int i = 0; i < 8; i++) {
        printf("%c ", '8' - i );
        for (int j = 0; j < 8; j++) {
            COORDENADA c = {i,j};
            if (obter_estado_casa(estado ,c) == DOIS) printf("2 ");
            else if (obter_estado_casa(estado ,c) == UM) printf("1 ");
            else if (obter_estado_casa(estado ,c) == VAZIO) printf(". ");
            else if (obter_estado_casa(estado ,c) == PRETA) printf("# ");
            else if (obter_estado_casa(estado ,c) == BRANCA) printf("* ");
        }
        printf("\n");
    }
    printf("  ");
    for(int i = 0; i < 8; i++) {
        printf("%c ", 'a' + i);
    };
    printf("\n");

}
void prompt (ESTADO*e){
    int numerojogadas = obter_numero_de_jogadas (e);
    int njogador = obter_jogador_atual (e);
    int n_mov = obter_num_mov(e);
    printf ("#%02d PLAYER%d (%d) -> ", n_mov , njogador,numerojogadas);
}

int gr(FILE *ficheiro){
    FILE *fp = fopen("ficheiro", "w");
    if(fp==NULL){
        fclose(fp);
        return 0;
    } else {
        fprintf(fp,"Ola\n");
        fclose(fp);
    }
    return 1;
}

int ler(FILE *ficheiro){
    FILE *fp = fopen("ficheiro", "r");
    int c;
    while((c = fgetc(fp)) != EOF){
        printf("%c", c);
    }
    return 1;
}

int Resposta (int resultado){
    switch (resultado){
        case 1: {
            printf("O Jogador 1 venceu!");
            break;
        }
        case 2: {
            printf("O Jogador 2 venceu!");
            break;
        }
    }
    return 0;
}

// Interpretador
int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if ( obter_numero_de_jogadas(e) == 0 ){
        printf( "#00 PLAYER1 (0) -> e5 \n" );
        faz_primeira_jogada(e);
        mostrar_tabuleiro(e);
    }
    prompt(e);
    if (strcmp (linha, "Q\n") == 0) return 0;
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col -'a', *lin -'1'};
        int resultado = jogar(e, coord);
        if ( resultado  != 0 ){
            mostrar_tabuleiro(e);
            Resposta (resultado);
            return 0;
        }
        mostrar_tabuleiro(e);
        interpretador(e);
    }
    return 1;
}
