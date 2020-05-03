//
// Created by laura on 09/04/20.
//

#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "Camada_dados.h"

LISTA criar_lista(){
    LISTA lista;
    lista = malloc (sizeof(Nodo));
    lista->prox = NULL;
    return lista;
}

LISTA insere_cabeca(LISTA L, par *valor){
    LISTA lista = criar_lista();
    lista->valor = valor;
    lista->prox = L;
    return lista;
}

void *devolve_cabeca(LISTA L){
    par *c;
    if(L == NULL) c = NULL;
    else c = L->valor;
    return c;
}

LISTA proximo(LISTA L){
   LISTA c = L->prox;
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
   int result = 0;
   while(!lista_esta_vazia(proximo(l))){
       result++;
       l = l->prox;
   }
   return result;
}

par *cria_par(COORDENADA c, int qualidade){
    par *p;
    p = malloc(sizeof(par));
    p->coord  = c;
    p->qualid = qualidade;
    return p;
}

COORDENADA obter_coordenada (par *p){
    return p -> coord;
}

int obter_qualid (par *p){
    return p -> qualid;
}

LISTA insereOrd (par *p, LISTA L){
    int qualidade = p->qualid;
    LISTA novo, *sitio;
    sitio = &L;
    while (*sitio != NULL && (*sitio)->valor->qualid > qualidade){
        sitio = &((*sitio)->prox);
    }
    novo = malloc(sizeof(Nodo));
    novo->valor = p;
    novo->prox= *sitio;
    *sitio = novo;
    return L;
}

LISTA organizar_qualidade ( LISTA inicial ){
    LISTA final = criar_lista();
    final->valor = inicial->valor;
    inicial = inicial->prox;
    while ( proximo(inicial) != NULL ){
        final = insereOrd( inicial->valor, final );
        inicial = inicial->prox;
    }
    return final;
}

LISTA alterar_qualid (LISTA inicial, par *p){
    LISTA *sitio;
    sitio = &inicial;
    COORDENADA d = p->coord;
    int j = p ->qualid;
    while( (*sitio)->prox != NULL ){
        COORDENADA c = (*sitio)->valor->coord;
        if ( c.coluna == d.coluna && c.linha == d.linha )
            (*sitio)->valor->qualid = j;
        sitio = &((*sitio)->prox);
    }
    return inicial;
}

