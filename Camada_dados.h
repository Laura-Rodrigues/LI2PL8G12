//
// Created by laura on 12/03/20.
//

#ifndef PROJETORASTROS_CAMADA_DADOS_H
#define PROJETORASTROS_CAMADA_DADOS_H

#include "Definiçoes.h"

ESTADO *inicializar_estado();
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
int obter_estado_casa(ESTADO *e, COORDENADA c);


#endif //PROJETORASTROS_CAMADA_DADOS_H
