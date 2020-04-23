//
// Created by laura on 09/04/20.
//

#ifndef PROJETORASTROS_LISTAS_H
#define PROJETORASTROS_LISTAS_H

#include "../Camada_dados.h"

typedef struct listas *LISTA;

typedef struct listas {
    COORDENADA *valor;
    LISTA prox;
} Nodo;


/**
\brief Cria uma lista vazia
@returns lista
*/
LISTA criar_lista();

/**
\brief Insere um valor na cabeça da lista
@param L Apontador para a lista
@param valor Apontador para a cabeça da lista
@returns lista
*/
LISTA insere_cabeca(LISTA L, COORDENADA *valor);

/**
\brief Devolve a cabeça da lista
@param L Apontador para a lista
*/
void *devolve_cabeca(LISTA L);

/**
\brief Devolve a cauda da lista
@param L Apontador para a lista
@returns
*/
LISTA proximo(LISTA L);

/**
\brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
@param L Apontador para a lista
@returns
*/
LISTA remove_cabeca(LISTA L);

/**
\brief Devolve verdareiro se a lista é vazia
@param L Apontador para a lista
@returns
*/
int lista_esta_vazia(LISTA L);

//Comprimento de uma lista
int len_Lista(LISTA l);

//procura elemento na lista
int dent_Lista (LISTA L, void *x);

#endif //PROJETORASTROS_LISTAS_H
