//
// Created by laura on 12/03/20.
//

/**
@file Camada_Interface.h
Definição do interpretador e mostrar tabuleiro e das funções associadas
*/

#ifndef PROJETORASTROS_CAMADA_INTERFACE_H
#define PROJETORASTROS_CAMADA_INTERFACE_H

#include <stdio.h>
#include <string.h>
#include "Logica_Programa.h"
#include "Camada_Interface.h"
#include "Camada_dados.h"

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
void prompt (ESTADO*e);

/**
\brief Interpretador
@param e Apontador para o estado
@returns 0 ou 1
*/
int interpretador(ESTADO *e);

#endif //PROJETORASTROS_CAMADA_INTERFACE_H
