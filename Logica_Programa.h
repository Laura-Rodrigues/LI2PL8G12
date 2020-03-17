//
// Created by laura on 12/03/20.
//

#ifndef PROJETORASTROS_LOGICA_PROGRAMA_H
#define PROJETORASTROS_LOGICA_PROGRAMA_H

#include "Camada_dados.h"

int vizinha(ESTADO *e, COORDENADA c);
int jogada_valida (ESTADO *estado, COORDENADA c);
int jogar(ESTADO *estado, COORDENADA c);

#endif //PROJETORASTROS_LOGICA_PROGRAMA_H
