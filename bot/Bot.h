#ifndef PROJETORASTROS_BOT_H
#define PROJETORASTROS_BOT_H

/**
@file Bot.h
* Definição da função essencial do bot
*/

#include "Camada_dados.h"
#include "listas.h"

/**
\brief Aplica a heurística e joga no tabuleiro a melhor jogada
@param e Apontador para o estado
@returns int
*/
int bot (ESTADO *e);

#endif //PROJETORASTROS_BOT_H
