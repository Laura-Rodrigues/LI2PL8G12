//
// Created by laura on 01/05/20.
//

#include "Funcoes_Ficheiro.h"
#include "Camada_dados.h"
#include "Logica_Programa.h"
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

void fptabuleiro(FILE *Projeto_Rastros, ESTADO *e){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            COORDENADA c = {i,j};
            if (obter_estado_casa(e,c) == DOIS) fprintf(Projeto_Rastros, "2");
            else if (obter_estado_casa(e ,c) == UM) fprintf(Projeto_Rastros, "1");
            else if (obter_estado_casa(e ,c) == VAZIO) fprintf(Projeto_Rastros, ".");
            else if (obter_estado_casa(e ,c) == PRETA) fprintf(Projeto_Rastros, "#");
            else if (obter_estado_casa(e ,c) == BRANCA) fprintf(Projeto_Rastros, "*");
        }
        fprintf(Projeto_Rastros, "\n");
    }
    fprintf(Projeto_Rastros, "\n");
}

int movsficheiro (ESTADO *estado, FILE *nome_fich) {
    char col1, col2;
    int ind, lin1, lin2, jogada = obter_numero_de_jogadas( estado ), jogador = obter_jogador_atual( estado );
    COORDENADA jog1, jog2;
    if ( jogador == 1 ) jogada--;
    for ( ind = 1; ind <= jogada ; ind++ ) {
        jog1 = obter_jogada( estado, ind, 1 );
        jog2 = obter_jogada( estado, ind, 2 );
        col1 = jog1.coluna + 'a';
        lin1 = jog1.linha + 1;
        col2 = jog2.coluna + 'a';
        lin2 = jog2.linha + 1;
        if ( ind < jogada )
            fprintf( nome_fich, "%02d: %c%d %c%d\n", ind, col1, lin1, col2, lin2 );
        else {
            if ( jogador == 2)
                fprintf(nome_fich, "%02d: %c%d\n", ind , col1, lin1 );
            else
                fprintf( nome_fich,"%02d: %c%d %c%d\n", ind, col1, lin1, col2, lin2 );
        }
    }
    return 0;
}

int gr ( char nomeficheiro[], ESTADO *estado ){
    FILE *fp = fopen( nomeficheiro, "w" );
    if( fp == NULL ){
        fclose( fp );
        return 0;
    } else {
        fptabuleiro( fp, estado );
        movsficheiro ( estado, fp );
        fclose(fp);
    }
    return 1;
}

int coordeval( COORDENADA c ){
    if (c.coluna < 0 || c.coluna > 7 || c.linha < 0 || c.linha > 7) return 0;
    else return 1;
}

ESTADO *ler ( char nomeficheiro[], ESTADO *estado ){
    FILE *fp = fopen( nomeficheiro, "r+" );
    if ( fp == NULL )
        printf("Nome inválido. \n");
    else{
        char str[BUF_SIZE];
        int jog, lin1 ,lin2;
        char col1, col2;
        estado = inicializar_estado();
        faz_primeira_jogada( estado );
        while ( ( fgets( str, BUF_SIZE, fp ) ) != NULL ){
            if (sscanf( str, "%2d: %c%d", &jog, &col1, &lin1 )){
                COORDENADA c0 = {col1 - 'a', lin1 - 1 };
                if ( coordeval(c0) && jog != 0 && jogada_valida( estado, c0 ) )
                    altera_estado(estado, c0);
            }
            if ( sscanf( str, "%2d: %c%d %c%d", &jog, &col1, &lin1, &col2, &lin2 ) ){
                COORDENADA c0 = {col1 - 'a', lin1 - 1 };
                COORDENADA c1 = {col2 -'a' , lin2 - 1 };
                if ( coordeval(c0) && jog != 0 && jogada_valida( estado, c0 ) )
                    altera_estado(estado, c0);
                if ( coordeval (c1) && jog != 0 && jogada_valida( estado, c1 ) )
                    altera_estado( estado, c1 );
            }
        }
        fclose ( fp );
    }
    return estado;
}

LISTA from_Array ( COORDENADA arr[], LISTA L, ESTADO *e){
    int i;
    for ( i = 0 ; i < 8; i++){
        if ( possivel (e, arr[i]) && !cond_canto(arr[i]) ){
            L = insere_cabeca(L, arr+i);
        }
    }
    return L;
}

int det_dist( COORDENADA coord, int njogador ){
    int cc = coord.coluna, cl = coord.linha, total;
    if( njogador == 1)
        total = cc+cl;
    else total = abs(cc-7) + abs(cl-7);
    return total;
}

COORDENADA dist_euclidiana ( ESTADO *e, LISTA inicial ){
    COORDENADA melhor, aux;
    int menor = 32, dist, jogador = obter_jogador_atual(e);
    LISTA Temp;
    for ( Temp = inicial; !lista_esta_vazia(proximo(Temp)); Temp = remove_cabeca(Temp)){
        aux = *( (COORDENADA *) devolve_cabeca(Temp) );
        dist = det_dist(aux, jogador);
        if ( dist < menor ){
            menor = dist;
            melhor = aux;
        }
    }
    return melhor;
}

int vitoria (ESTADO *estado, COORDENADA Coord){
    int r = 0, jogador = obter_jogador_atual(estado);
    if (jogador == 1 && Coord.coluna == 0 && Coord.linha == 0) r = 1;
    else if ( jogador == 2 && Coord.coluna == 7 && Coord.linha == 7) r = 1;
    else if ( vizivalide(estado, Coord) >= 7) r = 1;
    return r;
}

int derrota (ESTADO *estado, COORDENADA coord){
    int r = 0, jogador = obter_jogador_atual(estado);
    if (jogador == 2 && coord.coluna == 0 && coord.linha == 0) r = 1;
    else if ( jogador == 1 && coord.coluna == 7 && coord.linha == 7) r = 1;
    return r;
}

LISTA remove_elementos ( LISTA inicial, COORDENADA c){
    LISTA final = criar_lista();
    COORDENADA c1;
    while ( !lista_esta_vazia(proximo(inicial)) ){
        c1 = *((COORDENADA *)devolve_cabeca(inicial));
        if (c1.coluna == c.coluna && c1.linha == c.linha);
        else final = insere_cabeca(final, &c1);
        inicial = proximo(inicial);
    }
    return final;
}

LISTA remove_opcoes (ESTADO *e, LISTA l){
    LISTA T  = l, FINAL = criar_lista();
    int i, falha = 0;
    COORDENADA *c, f, ls[8] ;
    while (!lista_esta_vazia(proximo(T))){
        c = (COORDENADA *) devolve_cabeca(T);
        f = *c;
        coordvizinho(ls, f);
        for ( i = 0; i < 8; i++) {
            if (possivel(e, ls[i]) && !(cond_canto(ls[i]))) {
                if (vitoria ( e, ls[i]))
                    falha = 1;
            }
        }
        if ( falha == 1)
            falha = 0;
        else FINAL = insere_cabeca(FINAL, c);
        T = remove_cabeca(T);
    }
    return FINAL;
}

COORDENADA heuristica (ESTADO *e) {
    COORDENADA melhor, arr[8], coord = obter_ultima_jogada(e), c_aux;
    LISTA principal = criar_lista(), aux;
    coordvizinho( arr, coord );
    principal = from_Array(arr, principal, e);
    for ( aux = principal; !lista_esta_vazia(proximo(aux)); aux= proximo(aux)){
        c_aux = *((COORDENADA *)devolve_cabeca(aux));
        if ( vitoria ( e,c_aux ))
            return c_aux;
        if ( !(derrota (e , c_aux )) )
            remove_elementos(principal, c_aux);
    }
    if ( len_Lista(principal) == 1 )
        melhor = *(COORDENADA *)devolve_cabeca(principal);
    else {
        principal = remove_opcoes(e, principal);
        if ( len_Lista(principal) > 1 )
            melhor = dist_euclidiana ( e, principal);
        else
            melhor = * (COORDENADA *)devolve_cabeca(principal);
    }
    return melhor;
}

COORDENADA jog2 ( ESTADO *estado ) {
    COORDENADA c = heuristica(estado);
    printf("A jogada recomendada é: %c%d. \n", c.coluna + 'a', c.linha + 1);
    return c;
}
