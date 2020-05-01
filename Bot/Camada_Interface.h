//
// Created by laura on 01/05/20.
//

#ifndef PROJETORASTROS_CAMADA_INTERFACE_H
#define PROJETORASTROS_CAMADA_INTERFACE_H

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
\brief Mostra a lista de movimentos
@param estado Apontador para o estado
@returns 0
*/
int movs ( ESTADO *estado );


#endif //PROJETORASTROS_CAMADA_INTERFACE_H
