#ifndef PROJETORASTROS_LISTAS_H
#define PROJETORASTROS_LISTAS_H
/**
@file listas.h
Definição de funções associadas ao acesso direto às listas, entre outras funções auxiliares
*/

#include "../Camada_dados.h"

/** @par
\brief Tipo de dados para os pares
 *
 * Os pares são estruturas constituidas por uma coordenada e um inteiro que classifica a qualidade dessa coordenada.
 * Por outras palavras, a qualidade permite identificar se a coordenada é a melhor jogada a ser feita.
*/
typedef struct par_dados{
    /** Uma coordenada */
    COORDENADA coord; 
    /** A qualidade da coordenada com a qual faz um par */
    int qualid; 
} par;

/** @LISTA
\brief Tipo de dados para as listas
*/
typedef struct listas *LISTA;

/** @Nodo
\brief Tipo de dados para os nodos
*/
typedef struct listas {
    /** A cabeça da lista, que será neste caso um par */
    par *valor; 
    /** A "cauda" da lista, que é uma lista */
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
LISTA insere_cabeca(LISTA L, par *valor);

/**
\brief Devolve a cabeça da lista
@param L Apontador para a lista
*/
void *devolve_cabeca(LISTA L);

/**
\brief Devolve a cauda da lista
@param L Apontador para a lista
@returns Lista ligada
*/
LISTA proximo(LISTA L);

/**
\brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
@param L Apontador para a lista
@returns Lista
*/
LISTA remove_cabeca(LISTA L);

/**
\brief Devolve verdareiro se a lista é vazia
@param L Apontador para a lista
@returns int (0 ou 1, falso ou verdadeiro)
*/
int lista_esta_vazia(LISTA L);

/**
\brief Função que determina o comprimento de uma lista
@param L Apontador para a lista
@returns inteiro, comprimento da lista
*/
int len_Lista(LISTA l);

/**
\brief Função que recebe uma coordenada e um inteiro e transforma-os num par
@param c Coordenada
@param qualidade Inteiro
@returns par
*/
par *cria_par(COORDENADA c, int qualidade);

/**
\brief Recebe um par e devolve a coordenada
@param p Apontador para um par
@returns Coordenada
*/
COORDENADA obter_coordenada (par *p);

/**
\brief Recebe um par e devolve o qualidade (inteiro)
@param p Apontador para um par
@returns inteiro correspondente à qualidade
*/
int obter_qualid (par *p);

/**
\brief Função que recebe um par e uma Lista e coloca o par numa lista ordenada por ordem crescente da qualidade
@param p Apontador para um par
@param L Lista
@returns Lista ordenada com o novo par
*/
LISTA insereOrd (par *p, LISTA L);

/**
\brief Função que recebe uma Lista desordenada e transforma-a numa lista ordenada por ordem crescente da qualidade
@param L Lista
@returns Lista ordenada
*/
LISTA organizar_qualidade (LISTA L);

/**
\brief Função que recebe um par e uma Lista e altera a qualidade de um dos pares da lista
@param L Lista
@param p Apontador para um par
@returns Lista com a qualidade de um dos seus elementos alterada
*/
LISTA alterar_qualid (LISTA L, par* novo);

#endif //PROJETORASTROS_LISTAS_H
