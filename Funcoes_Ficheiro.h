//
// Created by laura on 26/03/20.
//

#ifndef PROJETORASTROS_FUNCOES_FICHEIRO_H
#define PROJETORASTROS_FUNCOES_FICHEIRO_H

#include <stdio.h>
#include "Camada_dados.h"
#include "Listas/listas.h"
/**
\brief Permite imprimir o tabuleiro no ficheiro
@param Projeto_Rastros Apontador para o ficheiro
@param e Apontador para o estado
*/
void fptabuleiro(FILE *Projeto_Rastros, ESTADO *e);

/**
\brief Mostra a lista de movimentos no ficheiro
@param estado Apontador para o estado
@param nome Apontador para o ficheiro
@returns 0
*/
int movsficheiro (ESTADO *estado, FILE *nome_fich);

/**
\brief Grava o tabuleiro
@param estado Apontador para o estado
@param nomeficheiro Apontador para o ficheiro
@returns 1
*/
int gr ( char nomeficheiro[], ESTADO *estado );

/**
\brief Testa se a coordenada é válida
@param c Apontador para coordenada
@returns 1 ou 0
*/
int coordeval( COORDENADA c );

/**
\brief Lê o tabuleiro e atualiza o estado
@param estado Apontador para o estado
@param nomeficheiro Apontador para o ficheiro
@returns o estado alterado
*/
ESTADO *ler ( char nomeficheiro[], ESTADO *estado );


/**
\brief Permitir ao utilizador aceder a uma jogada anterior
@param estado Apontador para o estado
@param dado Inteiro que indica a jogada pretendida
@returns Apontador do estado
*/
ESTADO* pos (ESTADO *estado, int dado);

/**
\brief Permitir calcular a distância de uma coordenada à casa final
@param c Coordenada
@param nj Numero do jogador atual
@returns int
*/
int det_dist(COORDENADA c, int nj);

/**
\brief Heurística para distância euclidiana
@param e Apontador para estado
@param L Apontador para lista
@returns coordenada
*/
COORDENADA dist_euclidiana ( ESTADO *e, LISTA L);

/**
\brief Determina a melhor jogada tendo em consideração a distância à casa objetivo
@param e Apontador para o estado
@returns coordenada
*/
COORDENADA jog ( ESTADO *e);

/**
\brief Função que transforma uma array de coordenadas numa lista
@param arr Array de coordenadas
@param L Lista ligada
@param e Apontador para estado
@returns int
*/
LISTA from_Array ( COORDENADA arr[], LISTA L, ESTADO *e);

/**
\brief Remove da lista a coordenada dada
@param inicial Lista ligada
@param c Coordenada dada
@returns lista
*/
LISTA remove_elementos ( LISTA inicial, COORDENADA c);

/**
\brief Função dá um valor (1,0 ou -1) conforme a coordenada dá uma vitoria, uma derrota, ou outra.
@param estado Apontador para o estado
@param coord Coordenada dada
@param ronda A ronda (int) em q se encontra
@returns int, valor da coordenada
*/
int valor_coord (ESTADO *estado, COORDENADA coord, int ronda);


/**
\brief Função que determina a qualidade de uma coordenada em função das coordenadas vizinhas
@param coord Coordenada dada
@param qualid Inteiro - qualidade da coordenada
@param estado Apontador para o estado
@param repete Inteiro - quantidade de vezes que repete o codigo; indicativo da profundidade
@param ronda A ronda(int) em q se encontra
@returns int, valor da coordenada
*/
int atualiza_qualidade (COORDENADA coord, int qualid, ESTADO *estado, int repete, int ronda);

/**
\brief Tendo em conta as jogadas possíveis, escolhe a melhor
@param e Apontador para estado
@returns coordenada
*/
COORDENADA heuristica (ESTADO *e);

/**
\brief Invoca a heurística e devolve uma coordenada
@param e Apontador para estado
@returns coordenada
*/
COORDENADA jog2 ( ESTADO *e );


#endif //PROJETORASTROS_FUNCOES_FICHEIRO_H
