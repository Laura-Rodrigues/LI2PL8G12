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
@param e Apontador para o estado
@param nome Apontador para o ficheiro
@returns 0
*/
int movsficheiro (ESTADO *e, FILE *nome);

/**
\brief Grava o tabuleiro
@param e Apontador para o estado
@param nomeficheiro Apontador para o ficheiro
@returns 1
*/
int gr(char nomeficheiro[], ESTADO *e);

/**
\brief Lê o tabuleiro e atualiza o estado
@param e Apontador para o estado
@param nomeficheiro Apontador para o ficheiro
@returns o estado alterado
*/
ESTADO *ler(char nomeficheiro[], ESTADO *e);

/**
\brief Permitir ao utilizador aceder a uma jogada anterior
@param e Apontador para o estado
@param dado Apontador para a jogada pretendida
@returns Apontador do estado
*/
ESTADO* pos (ESTADO *e, int dado);

/**
\brief Permitir calcular a distância de uma coordenada à casa final
@param c Coordenada 
@param nj Numero do jogador atual
@returns int
*/
int det_dist(COORDENADA c, int nj);

/**
\brief Determina a melhor jogada tendo em consideração a distância à casa objetivo
@param e Apontador para o estado
@returns coordenada
*/
COORDENADA jog ( ESTADO *e);

// Coloca numa Lista as casas vizinhas vaziaz
LISTA listvizinho(ESTADO *e, COORDENADA c);

//Coloca numa lista as casas com numero para de casas vizinhas vazias
LISTA len_Viz(LISTA l, ESTADO *e);

//Compara qual Casa tem menor numero de casas livres
COORDENADA min(LISTA l, ESTADO *e);

//Devolve a nova Coordenada
COORDENADA heu_par(LISTA l, ESTADO *e);

//Nova jog com heuristica paridade
COORDENADA jog2(ESTADO *e);



#endif //PROJETORASTROS_FUNCOES_FICHEIRO_H
