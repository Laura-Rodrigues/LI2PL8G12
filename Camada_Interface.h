//
// Created by laura on 12/03/20.
//

#ifndef PROJETORASTROS_CAMADA_INTERFACE_H
#define PROJETORASTROS_CAMADA_INTERFACE_H

#include <stdio.h>
#include <string.h>
#include "Logica_Programa.h"
#include "Camada_Interface.h"
#include "Camada_dados.h"
#define BUF_SIZE 1024


void mostrar_tabuleiro(ESTADO estado);
int interpretador(ESTADO *e);

#endif //PROJETORASTROS_CAMADA_INTERFACE_H
