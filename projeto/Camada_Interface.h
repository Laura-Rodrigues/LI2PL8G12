#ifndef PROJETORASTROS_CAMADA_INTERFACE_H
#define PROJETORASTROS_CAMADA_INTERFACE_H

/**
@file Camada_Interface.h
Definição do interpretador, mostrar tabuleiro e das funções associadas ao acesso direto da interface do jogo
*/

#include <stdio.h>
#include <string.h>
#include "Logica_Programa.h"
#include "Camada_Interface.h"
#include "Camada_dados.h"
#include "Funcoes_Ficheiro.h"
/**
\brief Definição do tamanho do buf
*/
#define BUF_SIZE 1024

/**
\brief Permite mostrar o tabuleiro
@param estado Apontador para o estado
*/
void mostrar_tabuleiro(ESTADO *estado);

/**
\brief Permite apresentar um prompt
@param e Apontador para o estado
*/
void prompt (ESTADO *e);

/**
\brief Permite dar uma resposta no final do jogo
@param resultado Um inteiro
@returns Qual dos jogadores ganhou
*/
int Resposta (int resultado);

/**
\brief Joga uma coordenada
@param estado Apontador para o estado
@param coord Apontador para a coordenada
@returns valor final (verdadeiro ou falso)
*/
int jogar_coord ( ESTADO *estado, COORDENADA coord );

/**
\brief Mostra a lista de movimentos
@param estado Apontador para o estado
@returns 0
*/
int movs ( ESTADO *estado );

/**
\brief Interpretador
@param e Apontador para o estado
@returns 0 ou 1
*/
int interpretador(ESTADO *e);

#endif //PROJETORASTROS_CAMADA_INTERFACE_H
