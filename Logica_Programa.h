//
// Created by laura on 12/03/20.
//

/**
@file Logica_Programa.h
Definição da função jogar e funções associadas a essa
*/

#ifndef PROJETORASTROS_LOGICA_PROGRAMA_H
#define PROJETORASTROS_LOGICA_PROGRAMA_H

#include "Camada_dados.h"

/**
\brief Testa se a Coordenada é vizinha da Coordenada anterior e se se encontra dentro do tabuleiro
@param e Apontador para o estado
@param c A coordenada
@returns 0 ou 1 para verdadeiro ou falso
*/
int vizinha(ESTADO *e, COORDENADA c);

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
@param c A coordenada
@returns 1 ou 0 para verdadeiro ou falso
*/
int cond_canto (COORDENADA c);

void coordvizinho(COORDENADA ls[], COORDENADA c);


/**
\brief Testar se tem vizinhos validos
@param e Apontador para o estado
@returns 1 ou 0 para verdadeiro ou falso, respetivamente
*/
int vizivalide(ESTADO *estado, COORDENADA coord);

/**
\brief Testa se a Coordenada é igual à final
@param c A coordenada
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
