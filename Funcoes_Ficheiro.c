//
// Created by laura on 26/03/20.
//

#include "Funcoes_Ficheiro.h"
#include "Camada_Interface.h"
#include "Camada_dados.h"
#include "Logica_Programa.h"
#include "Listas/listas.h"
#include <stdio.h>
#include <stdlib.h>

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
    int jogada = obter_numero_de_jogadas(e), jogador = obter_jogador_atual(e);
    if ( jogador == 1) jogada--;
    for ( i = 1; i <= jogada ; i++) {
        COORDENADA jog1 = obter_jogada(e, i, 1);
        c1 = jog1.coluna + 'a';
        l1 = jog1.linha + 1;
        COORDENADA jog2 = obter_jogada(e, i, 2);
        c2 = jog2.coluna + 'a';
        l2 = jog2.linha + 1;
        if (i < jogada) {
            fprintf(nome,"%02d: %c%d %c%d \n", i, c1, l1, c2, l2);
        } else {
            if ( jogador == 2)
                fprintf(nome,"%02d: %c%d \n", i, c1, l1);
            else
                fprintf(nome,"%02d: %c%d %c%d \n", i, c1, l1, c2, l2);
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
    int jogada = obter_numero_de_jogadas(e), jogador = obter_jogador_atual(e);
    if ( jogador == 1) jogada--;
    for ( i = 1; i <= jogada ; i++) {
        COORDENADA jog1 = obter_jogada(e, i, 1);
        c1 = jog1.coluna + 'a';
        l1 = jog1.linha + 1;
        COORDENADA jog2 = obter_jogada(e, i, 2);
        c2 = jog2.coluna + 'a';
        l2 = jog2.linha + 1;
        if (i < jogada) {
            printf("%02d: %c%d %c%d \n", i, c1, l1, c2, l2);
        } else {
            if ( jogador == 2)
                printf("%02d: %c%d \n", i , c1, l1);
            else
                printf("%02d: %c%d %c%d \n", i, c1, l1, c2, l2);
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
    e -> num_movimentos = m+obter_pos(e);
    return e;
}

void coordvizinho(ESTADO *e, COORDENADA ls[]) {
    COORDENADA c = obter_ultima_jogada(e), c0;
    int i, j, ind = 0;
    for (i = -1; i <= 1; i++)
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0);
            else {
                c0.coluna = c.coluna + i;
                c0.linha = c.linha + j;
                ls[ind] = c0;
                ind++;
            }
        }
}

int det_dist(COORDENADA c, int nj){
    int cc = c.coluna, cl = c.linha, total;
    if( nj == 1){
        total = cc+cl;
    } else {
        total = abs(cc-7) + abs(cl-7);
    }
    return total;
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

LISTA listvizinho(ESTADO *e, COORDENADA c){
    LISTA l = criar_lista();
    COORDENADA c0 = {c.coluna +1,c.linha +1};
    COORDENADA c1 = {c.coluna +1,c.linha };
    COORDENADA c2 = {c.coluna +1,c.linha -1};
    COORDENADA c3 = {c.coluna ,c.linha +1};
    COORDENADA c4 = {c.coluna ,c.linha -1};
    COORDENADA c5 = {c.coluna -1,c.linha +1};
    COORDENADA c6 = {c.coluna -1,c.linha};
    COORDENADA c7 = {c.coluna -1,c.linha -1};
    COORDENADA ls[8] = {c0,c1,c2,c3,c4,c5,c6,c7};
    for(int i = 0; i < 8; i++){
        if(obter_estado_casa(e,ls[i]) == VAZIO)
            insere_cabeca(l,&ls[i]);
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
    int arr[2] = {cd,ld};
    return arr;
}

int max(int *l){
    int i = 0;
    int ans = 0;
    while(*l != '\0'){
        if(l[i] < l[i+1]){
            ans = i+1;
            i++;
        } else {
            ans = i;
            i++;
        }
    }
    return ans;
}

COORDENADA len_Viz(COORDENADA c, ESTADO *e){
    int *d;
    COORDENADA c0 = {c.coluna +1,c.linha +1};
    COORDENADA c1 = {c.coluna +1,c.linha };
    COORDENADA c2 = {c.coluna +1,c.linha -1};
    COORDENADA c3 = {c.coluna ,c.linha +1};
    COORDENADA c4 = {c.coluna ,c.linha -1};
    COORDENADA c5 = {c.coluna -1,c.linha +1};
    COORDENADA c6 = {c.coluna -1,c.linha};
    COORDENADA c7 = {c.coluna -1,c.linha -1};
    COORDENADA ls[8] = {c0,c1,c2,c3,c4,c5,c6,c7};
    for(int i = 0; i<8 ; i++){
        COORDENADA cf = ls[i];
        d[i]=len_Lista(listvizinho(e,cf));
    }
    return ls[max(d)];
}

ESTADO floodfill (ESTADO *e, LISTA li) {
    COORDENADA c = obter_ultima_jogada(e);
    int nj = obter_jogador_atual(e);
    int *d = distcasa(nj, c);
    int cd = d[0], ld = d[1];
    if (nj == 1) {
        COORDENADA c1 = {c.coluna, c.linha - 1};
        COORDENADA c2 = {c.coluna - 1, c.linha};
        COORDENADA c3 = {c.coluna - 1, c.linha - 1};
        if ((cd == ld) && dent_Lista(li, &c3)) {
            altera_estado(e, c3);
        } else if (cd < ld && dent_Lista(li, &c1)) {
            altera_estado(e, c1);
        } else if (cd > ld && dent_Lista(li, &c2)) {
            altera_estado(e, c1);
        } else {
            altera_estado(e, len_Viz(c, e));
        }
    } else {
        COORDENADA c4 = {c.coluna, c.linha + 1};
        COORDENADA c5 = {c.coluna + 1, c.linha};
        COORDENADA c6 = {c.coluna + 1, c.linha + 1};
        if ((cd == ld) && dent_Lista(li, &c6)) {
            altera_estado(e, c6);
        } else if (cd < ld && dent_Lista(li, &c4)) {
            altera_estado(e, c4);
        } else if (cd > ld && dent_Lista(li, &c5)) {
            altera_estado(e, c5);
        } else {
            altera_estado(e, len_Viz(c, e));
        }
    }
    return *e;
}

ESTADO jog2 (ESTADO *e) {
    COORDENADA c = obter_ultima_jogada(e);
    LISTA li = listvizinho(e, c);
    floodfill(e,li);
    return *e;
}


