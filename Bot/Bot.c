//
// Created by laura on 23/04/20.
//


#include "Bot.h"

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

COORDENADA jog ( ESTADO *e ){
    COORDENADA ls[8], *c, t;
    coordvizinho(e, ls);
    LISTA L = criar_lista();
    int i, j = obter_jogador_atual(e), max = 32, dist;
    for ( i = 0; i < 8 ; i++) {
        if (jogada_valida(e, ls[i]) && !(cond_canto(ls[i]))) {
            dist = det_dist(ls[i], j);
            if (dist < max) {
                max = dist;
                t = ls[i];
            } else
                L = insere_cabeca(L, ls + i);
        }
    }
    L = insere_cabeca(L, &t);
    c = (COORDENADA *) devolve_cabeca(L);
    printf("A jogada recomendada é: %c%d. \n", c->coluna+'a', c->linha+1);
    return *c;
}

COORDENADA bot