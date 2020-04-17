//
// Created by laura on 12/03/20.
//

#include <stdio.h>
#include <string.h>
#include "Logica_Programa.h"
#include "Camada_dados.h"
#include "Funcoes_Ficheiro.h"

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


int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char nome_ficheiro[BUF_SIZE];
    int joga, i = obter_pos(e);    
    if (obter_numero_de_jogadas(e) == 0 && obter_num_mov(e) == 0) {
        printf("#00 PLAYER2 (0) -> e5 \n");
        faz_primeira_jogada(e);
        mostrar_tabuleiro(e);
    }
    else
        if (obter_numero_de_jogadas(e) == 0)
            faz_primeira_jogada(e);
    prompt(e);
    if (fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if (strcmp(linha, "Q\n") == 0) return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        int resultado = jogar(e, coord);
        if (resultado == 3) {
            printf("Jogada inválida! \n");
        }
        else if (resultado != 0) {
            mostrar_tabuleiro(e);
            Resposta(resultado);
            return 0;
        }
        mostrar_tabuleiro(e);
        interpretador(e);
    }
    else if (sscanf(linha, "pos %d", &joga)) {
        if ( i != 0 ){
            strcpy(nome_ficheiro, "v_ant_estado");
            e = ler (nome_ficheiro, e);
            aumenta_pos(e, i-1);
        }
        if (joga < 0 || joga >= obter_numero_de_jogadas(e)) {
            printf("Número de jogada inválido.\n");
            interpretador(e);
        }
        else {
            if (obter_pos(e) == 0){
                strcpy(nome_ficheiro, "v_ant_estado");
                gr (nome_ficheiro, e);
                e = pos(e, joga);
                interpretador(e);
            }
            else {
                e = pos(e, joga);
                interpretador(e);
            }
        }
    }
    else if (strcmp(linha, "movs\n") == 0) {
        movs(e);
        interpretador(e);
    }
    else if (strcmp(linha, "jog\n") == 0) {
        c = jog(e);
        jogar(e, c);
        mostrar_tabuleiro(e);
    }
    else if (sscanf(linha, "gr %s", nome_ficheiro)) {
        if ( strcmp(nome_ficheiro, "v_ant_estado") == 0){
            printf("Nome inválido. \n");
        }
        else {
            gr(nome_ficheiro, e);
            printf("Guardado! \n");
        }
        interpretador(e);
    }
    else if (sscanf(linha, "ler %s", nome_ficheiro)) {
        printf("O ficheiro: \n");
        e = ler(nome_ficheiro, e);
        mostrar_tabuleiro(e);
        movs(e);
        interpretador(e);
    }
    else{
        printf("Comando inválido! Tente outra vez!\n");
        interpretador(e);
    }
    return 1;
}
