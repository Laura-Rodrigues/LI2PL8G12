//
// Created by laura on 09/04/20.
//

#ifndef PROJETORASTROS_LISTAS_H
#define PROJETORASTROS_LISTAS_H

#include "../Camada_dados.h"

/**
\brief Tipo de dados para as listas
*/
typedef struct listas *LISTA;

/**
\brief Tipo de dados para os nodos
*/
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
@returns lista
*/
LISTA proximo(LISTA L);

/**
\brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
@param L Apontador para a lista
@returns lista
*/
LISTA remove_cabeca(LISTA L);

/**
\brief Devolve verdareiro se a lista é vazia
@param L Apontador para a lista
@returns verdadeiro ou falso
*/
int lista_esta_vazia(LISTA L);

/**
\brief descobre o comprimento da lista
@param l Apontador para a lista
@returns tamanho da lista
*/
int len_Lista(LISTA l);

#endif //PROJETORASTROS_LISTAS_H
