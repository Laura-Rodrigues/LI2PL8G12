//
// Created by laura on 23/04/20.
//

#ifndef PROJETORASTROS_BOT_H
#define PROJETORASTROS_BOT_H

#include "funcoes_aux.h"

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
\brief Vê se ganhou
@param e Apontador para estado
@param C Apontador para coordenada
@returns verdadeiro ou falso
*/
int vitoria (ESTADO *e, COORDENADA C);

/**
\brief Vê se perdeu
@param e Apontador para estado
@param c Apontador para coordenada
@returns verdadeiro ou falso
*/
int derrota (ESTADO *e, COORDENADA c);

/**
\brief Tendo em conta as coordenadas vizinhas das vizinhas, remove da lista se permitir a vitória do adversário
@param e Apontador para estado
@param l Apontador para lista
@returns lista
*/
LISTA remove_opcoes (ESTADO *e, LISTA l);

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

/**
\brief Aplica a heurística e joga no tabuleiro a melhor jogada
@param e Apontador para o estado
@returns coordenada
*/
COORDENADA bot (ESTADO *e);

#endif //PROJETORASTROS_BOT_H
