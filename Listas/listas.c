//
// Created by laura on 09/04/20.
//

#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "../Camada_dados.h"


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
  /*   LISTA x;
    if(L==NULL) x = NULL;
    else x = L->prox;
    return x;*/
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
