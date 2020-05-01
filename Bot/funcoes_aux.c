//
// Created by laura on 25/04/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "Bot.h"
#include "funcoes_aux.h"
#define BUF_SIZE 1024

ESTADO *inicializar_estado(){
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int j, i;
    for ( i = 0; i < 8; i++){
        for ( j = 0; j < 8; j++){
            if ( i == 3 && j == 4) e->tab[i][j] =  BRANCA;
            else if ( i == 7 && j == 0) e->tab[i][j] = UM;
            else if (i == 0 && j == 7) e->tab[i][j] = DOIS;
            else e->tab[i][j] = VAZIO;
        }
    }
    COORDENADA coordenada_inicial = {4,4};
    e->ultima_jogada = coordenada_inicial;
    COORDENADA jog1 = {4,4};
    e->jogadas[0].jogador2 = jog1;
    e->num_jogadas = 0;
    e->jogador_atual = 2;
    e->num_movimentos = 0;
    e->alt_pos = 0;
    return e;
}

//Esta função permite obter o número do jogador atual
int obter_jogador_atual(ESTADO *estado){
    return (estado->jogador_atual);
}


//Esta função permite obter quantas jogadas foram efetuadas (cada jogada tem o movimento de dois jogadores).
int obter_numero_de_jogadas(ESTADO *estado){
    return (estado->num_jogadas);
}

//Função que troca a coluna pela linha e vice-versa
COORDENADA troca_ordem (COORDENADA c){
    COORDENADA final = {7-c.linha, c.coluna};
    return final;
}

//Esta função permite obter o estado atual da casa. Nota: esta função recebe as coordenadas no format "linha,coluna"
CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int i = c.coluna;
    int j = c.linha;
    CASA final = (e-> tab[i][j]);
    return final;
}

//Esta função deve aceder ao estado e returnar a ultima jogada;
COORDENADA obter_ultima_jogada (ESTADO *estado){
    COORDENADA ultima;
    ultima = estado->ultima_jogada;
    return ultima;
}

COORDENADA obter_jogada (ESTADO *e, int njogada, int jogador){
    COORDENADA r;
    JOGADA jogada = e-> jogadas [njogada];
    if ( jogador == 1) r = jogada.jogador1;
    else r = jogada.jogador2;
    return r;
}

void faz_primeira_jogada (ESTADO *e){
    altera_numjogadas(e);
    altera_jogadoratual(e);
    altera_num_mov(e);
}

void altera_pos (ESTADO* e){
    e->alt_pos = 0;
}

void altera_tabuleiro (ESTADO *estado, COORDENADA c){
    estado->tab[7-(c.linha)][c.coluna] = BRANCA;
    estado->tab[7-(estado->ultima_jogada).linha][(estado->ultima_jogada).coluna]=PRETA;
}

void altera_ultimajogada (ESTADO *e, COORDENADA c){
    e->ultima_jogada = c;
}

void altera_jogadas (ESTADO *e, COORDENADA c){
    int i = (e->num_jogadas);
    if (e->jogador_atual == 1){
        e->jogadas[i].jogador1 = c;
    }
    else {
        e->jogadas[i].jogador2 = c;
    }
}


void altera_numjogadas (ESTADO *e){
    if ( e -> jogador_atual == 2) e->num_jogadas += 1;
}

void altera_jogadoratual(ESTADO *e){
    if (e->jogador_atual == 1) e->jogador_atual = 2;
    else e->jogador_atual = 1;
}

void altera_num_mov (ESTADO *e){
    e->num_movimentos++;
}

void altera_estado (ESTADO *e, COORDENADA c){
    altera_pos(e);
    altera_tabuleiro(e, c);
    altera_ultimajogada(e,c);
    altera_jogadas(e, c);
    altera_numjogadas(e);
    altera_jogadoratual(e);
    altera_num_mov(e);
}

int vizinha(ESTADO *e, COORDENADA c){
    COORDENADA ultjogada = obter_ultima_jogada(e);
    int r=0;
    if (ultjogada.coluna == c.coluna && ultjogada.linha == c.linha) return r;
    if (abs(c.linha - ultjogada.linha) <= 1) {
        if (abs(c.coluna - ultjogada.coluna) <= 1)
            r = 1;
    }
    return r;
}

int possivel ( ESTADO *estado, COORDENADA coord ){
    int result = 0;
    COORDENADA nova = troca_ordem( coord );
    if ( obter_estado_casa( estado,nova ) != PRETA && obter_estado_casa( estado,nova ) != BRANCA ) result = 1;
    return result;
}

int jogada_valida (ESTADO *estado, COORDENADA c){
    COORDENADA final = troca_ordem (c);
    CASA j = (obter_estado_casa(estado,final));
    if((j == VAZIO || j == UM ||j == DOIS) && vizinha(estado, c))
        return 1;
    else return 0;
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

LISTA criar_lista(){
    LISTA lista;
    lista = malloc (sizeof(Nodo));
    lista->prox = NULL;
    return lista;
}

LISTA insere_cabeca(LISTA L, COORDENADA *valor){
    LISTA lista = criar_lista();
    lista->valor = valor;
    lista->prox = L;
    return lista;
}

void *devolve_cabeca(LISTA L){
    COORDENADA *c;
    if(L == NULL) c = NULL;
    else c = L->valor;
    return c;
}

LISTA proximo(LISTA L){
    LISTA c=L->prox;
    if(L == NULL) c = NULL;
    return c;
}

LISTA remove_cabeca(LISTA L){
    LISTA cabeca;
    cabeca = L;
    L = proximo (L);
    free (cabeca);
    return L;
}

int lista_esta_vazia(LISTA L){
    int x = 0;
    if (L == NULL) x = 1;
    return x;
}

int len_Lista(LISTA l){
    if(lista_esta_vazia(l)) return 0;
    else return 1 + len_Lista(proximo(l));
}

int cond_canto (COORDENADA c) {
    if (c.coluna > 7 || c.linha > 7 || c.coluna < 0 || c.linha < 0) return 1;
    else return 0;
}

//Testar se tem vizinhos validos
int vizivalide(ESTADO *e, COORDENADA c){
    COORDENADA c0 = {c.coluna +1,c.linha +1};
    COORDENADA c1 = {c.coluna +1,c.linha };
    COORDENADA c2 = {c.coluna +1,c.linha -1};
    COORDENADA c3 = {c.coluna ,c.linha +1};
    COORDENADA c4 = {c.coluna +1,c.linha -1};
    COORDENADA c5 = {c.coluna -1,c.linha +1};
    COORDENADA c6 = {c.coluna -1,c.linha};
    COORDENADA c7 = {c.coluna -1,c.linha -1};
    COORDENADA arr[8] = {c0,c1,c2,c3,c4,c5,c6,c7};
    int r = 0, resultado = 0;
    for (int i = 0; i < 8; i++){
        if (obter_estado_casa(e, troca_ordem(arr[i])) == PRETA || cond_canto (arr[i])) r++;
    }
    if ( r == 8 ) resultado = 1;
    return resultado;
}

//Testa se a Coordenada é igual á final
int fim(ESTADO *e, COORDENADA c){
    if ((c.coluna) == 0 && (c.linha)== 0){
        return 1;
    }
    else if((c.coluna) == 7 && (c.linha) == 7){
        return 2;
    }
    else if (vizivalide(e,c) == 1){
        int i = obter_jogador_atual(e);
        int jogador;
        if ( i == 1) jogador = 2;
        else jogador = 1;
        return jogador;
    }
    else return 0;
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

int jogar(ESTADO *estado, COORDENADA c){
    int resultado = 0 , r = 0;
    if (jogada_valida(estado,c)){
        r = 1;
        altera_estado(estado,c);
        resultado = fim(estado,c);
    }
    if (r == 0)
        resultado = 3;
    return resultado;
}
