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
    par *p;
    for ( i = 0 ; i < 8; i++){
        if ( possivel (e, arr[i]) && !cond_canto(arr[i]) ){
            p = cria_par(arr[i], 0);
            L = insere_cabeca(L, p);
        }
    }
    return L;
}

LISTA remove_elementos ( LISTA L, COORDENADA c){
    LISTA final = criar_lista();
    COORDENADA c1;
    while ( !lista_esta_vazia(proximo(L)) ){
        c1 = obter_coordenada((par *)devolve_cabeca(L));
        if (c1.coluna == c.coluna && c1.linha == c.linha);
        else final = insere_cabeca(final, cria_par(c1, 0));
        L = proximo(L);
    }
    return final;
}

int valor_coord (ESTADO *e, COORDENADA c, int ronda){
    int n = 0, j = obter_jogador_atual(e);
    if (j == 1 && c.coluna == 0 && c.linha == 0) n = 1;
    else if ( j == 2 && c.coluna == 7 && c.linha == 7 ) n = 1;
    else if ( j == 2 && c.coluna == 0 && c.linha == 0 ) n = -1;
    else if ( j == 1 && c.coluna == 7 && c.linha == 7 ) n = -1;
    else if ( ronda % 2 == 0 && vizivalide(e, c) >= 7 ) n = 1;
    else if ( ronda % 2 != 0 && vizivalide(e, c) >= 7 ) n = -1;
    return n;
}

//esta função tem em consideração o valor das coordenadas vizinhas e juntas e colocas na coordenada origem
int atualiza_qualidade (COORDENADA c, int qualid, ESTADO *e, int repete, int ronda){
    if ( repete-ronda > 0 ){
        COORDENADA arr[8], d;
        LISTA L = criar_lista();
        par *p;
        ronda++;
        coordvizinho(arr, c);
        L = from_Array(arr, L, e);
        while ( !lista_esta_vazia(proximo(L)) ){
            p = (par *)devolve_cabeca(L);
            d = obter_coordenada(p);
            qualid += valor_coord(e, d, ronda);
            if ( ronda == 1 && qualid == -1){
                return qualid = -64;
            }
            else
                qualid = atualiza_qualidade(d, qualid, e, repete, ronda);
            L = proximo(L);
        }
    }
    return qualid;
}

COORDENADA heuristica ( ESTADO *e ) {
    COORDENADA arr[8], atual = obter_ultima_jogada(e), melhor, c;
    LISTA principal = criar_lista();
    int q;
    coordvizinho(arr, atual);
    principal = from_Array(arr, principal, e);
    if (len_Lista(principal) == 1);
    else {
        for (LISTA aux = principal; !lista_esta_vazia(proximo(aux)); aux = proximo(aux)) {
            par *p = (par *) devolve_cabeca(aux);
            c = obter_coordenada(p);
            if (valor_coord(e, c, 0) == 1) return c;
            else if (valor_coord(e, c, 0) == -1) principal = remove_elementos(principal, c);
            else{
                q = atualiza_qualidade(c, obter_qualid(p), e, 5, 0);
                principal = alterar_qualid(principal, (cria_par(c, q)));
            }
        }
    }
    principal = organizar_qualidade(principal);
    melhor = obter_coordenada((par *)devolve_cabeca(principal));
    return melhor;
}

COORDENADA jog ( ESTADO *e ) {
    COORDENADA c = heuristica(e);
    return c;
}
