//
// Created by laura on 09/04/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"


LISTA criar_lista(){
    LISTA lista;
    lista = malloc (sizeof(Nodo));
    lista->prox = NULL;
    return lista;
}

LISTA insere_cabeca(LISTA L, void *valor){
    LISTA lista = criar_lista();
    lista->valor = valor;
    lista->prox = L;
    return lista;
}

void *devolve_cabeca(LISTA L){}

LISTA proximo(LISTA L){}

LISTA remove_cabeca(LISTA L){}

int lista_esta_vazia(LISTA L){}
