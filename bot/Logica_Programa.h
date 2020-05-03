#ifndef PROJETORASTROS_LOGICA_PROGRAMA_H
#define PROJETORASTROS_LOGICA_PROGRAMA_H

/**
@file Logica_Programa.h
Definição da função jogar e funções associadas à estrutura lógica do jogo
*/

#include "Camada_dados.h"

/**
\brief Testa se a Coordenada é vizinha da Coordenada anterior e se se encontra dentro do tabuleiro
@param estado Apontador para o estado
@param coord A coordenada
@returns 0 ou 1 para verdadeiro ou falso
*/
int e_vizinha( ESTADO *estado, COORDENADA coord);

/**
\brief Testa se a jogada é possível
@param e Apontador para o estado
@param c A coordenada
@returns 0 ou 1 para verdadeiro ou falso
*/
int possivel ( ESTADO *e, COORDENADA c);

/**
\brief Testa se a Jogada é válida
@param estado Apontador para o estado
@param c A coordenada
@returns 0 ou 1 para verdadeiro ou falso
*/
int jogada_valida (ESTADO *estado, COORDENADA c);

/**
\brief Função que determina se a coordenada se encontra fora do tabuleiro
@param c Apontador para coordenada
@returns 1 ou 0 para verdadeiro ou falso
*/
int cond_canto (COORDENADA c);

/**
\brief Cria um array das coordenadas vizinhas
@param ls array de coordenadas
@param c Apontador para coordenada
*/
void coordvizinho(COORDENADA ls[], COORDENADA c);

/**
\brief Testar se tem vizinhos validos
@param estado Apontador para o estado
@param coord Apontador para coordenada
@returns 1 ou 0 para verdadeiro ou falso, respetivamente
*/
int vizivalide(ESTADO *estado, COORDENADA coord);

/**
\brief Testa se a Coordenada é igual à final
@param estado Apontador para estado
@param coord A coordenada
@returns 0 ou 1 para verdadeiro ou falso
*/
int fim(ESTADO *estado, COORDENADA coord );

/**
\brief Modifica o estado ao jogar na casa correta se a jogada for válida
@param estado Apontador para o estado
@param c A coordenada
@returns 0 ou 1 para verdadeiro ou falso
*/
int jogar(ESTADO *estado, COORDENADA c);


#endif //PROJETORASTROS_LOGICA_PROGRAMA_H
