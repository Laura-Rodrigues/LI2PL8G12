//
// Created by laura on 09/04/20.
//

#ifndef PROJETORASTROS_LISTAS_H
#define PROJETORASTROS_LISTAS_H

typedef struct listas *LISTA;

typedef struct listas {
    void *valor;
    LISTA prox;
} Nodo;

// Cria uma lista vazia
LISTA criar_lista();

// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *valor);

// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L);

// Devolve a cauda da lista
LISTA proximo(LISTA L);

// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);

// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L);

#endif //PROJETORASTROS_LISTAS_H
